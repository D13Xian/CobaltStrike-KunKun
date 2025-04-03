#include <windows.h>
#include <stdio.h>
#include <TlHelp32.h>
#include <stdlib.h>
#include <string.h>
#include <wincrypt.h>
#include "beacon.h"
#include "auto_inject.h"

// check if user has permissions to access process.
int FindPidWithSufficientRights(const char* procname) {
    HANDLE hProcSnap;
    PROCESSENTRY32 pe32;
    int pid = 0;

    hProcSnap = KERNEL32$CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hProcSnap) return 0;

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!KERNEL32$Process32First(hProcSnap, &pe32)) {
        KERNEL32$CloseHandle(hProcSnap);
        return 0;
    }

    while (KERNEL32$Process32Next(hProcSnap, &pe32)) {
        if (KERNEL32$lstrcmpiA(procname, pe32.szExeFile) == 0) {
            HANDLE hProcess = KERNEL32$OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
            if (hProcess != NULL) {
                // Successfully opened the process with sufficient rights
                KERNEL32$CloseHandle(hProcess);
                
                pid = pe32.th32ProcessID;
                break;
            }
            // Failed to open the process with sufficient rights, continue searching
        }
    }

    KERNEL32$CloseHandle(hProcSnap);
    return pid;
}

//struct to return both values
typedef struct {
    int pid;
    const char* processname;
    const char* arch;
} Result;

//find PID of process
Result FindTarget(const char* processNames[], int numProcesses) {
    Result procinfo;
    int pid = -1; // Initialize with -1 to indicate process not found
    int found = 0; // Flag to indicate if a process has been found
    
    for (int i = 0; i < numProcesses; i++) {
        // after checking if the process exists, check if correct access.
        pid = FindPidWithSufficientRights(processNames[i]);
        if (pid != -1 && pid != 0) {
            procinfo.pid = pid;
            procinfo.processname = processNames[i];
            found = 1; // Set the flag to indicate that a process has been found
            break; // Exit the loop if a process is found
        }
    }

    return procinfo;
}


int go(char *args, int len){
    
    datap parser;
    
    char* first;
    char* second;
    char* third;
    char* fourth;

    BeaconDataParse(&parser, args, len);
    
    first = BeaconDataExtract(&parser, NULL);
    second = BeaconDataExtract(&parser, NULL);
    third = BeaconDataExtract(&parser, NULL);
    fourth = BeaconDataExtract(&parser, NULL);
	
    // Create an array of process names you want to search for
    const char* processNames[] = {first, second, third, fourth};
    int numProcesses = sizeof(processNames) / sizeof(processNames[0]);


    Result res = FindTarget(processNames, numProcesses);
    if(res.pid != 0){
        BeaconPrintf(CALLBACK_OUTPUT, "[+] \tINIT_PID_SEARCH\t%s\t%d", res.processname, res.pid);
    }else{
        BeaconPrintf(CALLBACK_OUTPUT, "[-] No valid process found\n");
    }
    
    

    return res.pid;
}
