@ECHO OFF

cl.exe /nologo /c /Od /MT /W0 /GS- /Tc main.c
move /y main.obj auto_inject.o
