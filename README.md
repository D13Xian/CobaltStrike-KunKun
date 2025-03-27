# CobaltStrike-[坤坤版]-4.5-基于CobaltStrike_cat4.5项目二开

> 大家好，我是练习时长两年半的个人练习生蔡徐坤。
>
> Ps:坤坤Cs:基于CobaltStrike4.5-猫猫版二开完成 (原dogcs4.4二开功能基本都有)(自带破解,不需要使用csagent.)
>
> 新版客户端只在Windows 与Ubuntu系统上测试过，Mac OS还未测试，如果有macos用户出现使用问题请在Issues中留言
>
> 如有bug请在lssues中提出，如果收集到沙箱IP、测绘IP也欢迎在Issues里提出，被分析了也可以在issues里提供截图（注意打码）

## 2025.3.28
 - 修复profile配置有概率上线失败的问题（现在可使用server/tools/Malleable-C2-Randomizer-master自己随机生成，过两天把c2lint改出来，如果有大牛改出来了麻烦issue一下，感激不尽。）
 - 增加了后渗透自动检测杀软插件、自动维权插件 默认不加载，可使用`java -jar cat_server.jar script [host] [port] [user] [password] [cna脚本]`自己加载。
 - 简单做个免杀测一下（截止到今日shellcode还活着QAQ）：
 1. 火绒最新版：
   ![image](https://github.com/user-attachments/assets/ce2db803-2c57-4b52-a4a0-f9e9044a77ad)
 2.360老版但是带晶核（为了不让他传沙箱给他联网权限关了，这里有个trick 360qvm不杀自己图标的马，增加熵也可以做到）
   ![image](https://github.com/user-attachments/assets/44e42f2b-5494-4bfc-b66b-d025354fcc3d)


## 2025.3.27
 - 修复 https://github.com/D13Xian/CobaltStrike-KunKun/issues/1
 - 修复了Version参数转换成浮点数的bug



## 😘致敬原作者

https://github.com/TryGOTry/CobaltStrike_Cat_4.5



## 相关配置

`Java版本:11 运行前请先配置CatClient.properties`

`为兼容CS-cat客户端，同CS-cat原配置文件相同，为新手增加了中文注释`

#### 客户端

修改了默认主题颜色，黑色配置改为红色，默认为红色。

> **java -jar cat_client.jar client**

##### 配置文件说明(CatClient.properties)

|        配置名        |                           配置说明                           |
| :------------------: | :----------------------------------------------------------: |
|  CatClient.Version   | 自定义版本号,需要和服务端一致.(别人拿到这个版本的cs信息,如果版本号不对,也无法登录TeamSever):String |
|  CatClient.OpenAuth  | 是否开启auth验证,需要和服务端对应(开启后安全性较高,但是客户端无法断线重连)：true,false |
| CatClient.InjectSelf | 是否注入自身,开启的话Desktop，Keylogger,Hashdump,PortScan,Mimikatz,PowerShellUnmanaged,Printscreen,Screenshot,Screenwatch会注入自身(开启后无法适配geacon_pro)：true,false |
|   CatClient.theme    |            客户端主题配置,0是原版,1是白色,2是黑色            |
|  CatClient.ini_name  |            自定义配置文件存放名称,防止被蜜罐读取             |
| stager.checksum-num  |     关于stager的相关配置(强烈建议用profile文件自定义url)     |
|    stager.x86-num    |                     客户端和服务器需一致                     |
|  stager.x86-uri-len  |                     客户端和服务器需一致                     |
|    stager.x64-num    |                     客户端和服务器需一致                     |
|  stager.x64-uri-len  |                     客户端和服务器需一致                     |

---

#### 服务端

```bash
推荐使用ubuntu18运行
sudo apt install openjdk-11-jre-headless
sudo apt install openjdk-11-jdk
```

> **需Java11运行，运行前请先配置CatServer.properties**

##### 配置文件说明(CatServer.properties)

|          配置名          |                           配置说明                           |
| :----------------------: | :----------------------------------------------------------: |
|    CatServer.Version     | 自定义版本号,需要和客户端一致.(别人拿到这个版本的cs信息,如果版本号不对,也无法登录TeamSever)，可以是任意字符串 |
|      CatServer.port      |                          服务端端口                          |
|     CatServer.store      |               TeamServer证书文件(需放当前目录)               |
| CatServer.store-password |                           证书密码                           |
|      CatServer.host      |    服务器ip(可随意填写,只是客户端监听时候会默认显示的ip)     |
|    CatServer.password    |                          服务端密码                          |
|  CatServer.profile-name  |                       profile文件名称                        |
|    CatServer.profile     | 使用的profile文件,需放在当前目录下(所以必须使用profile启动)  |
|      CatServer.auth      |         是否开启双重验证,需要和客户端一致:true,false         |
|    CatServer.authlog     | 是否开启登录日志记录(只是在安全码正确,但是密码错误的情况下记录.):true,false |
|   CatServer.googleauth   |          开启双重验证后,再开启谷歌验证码:true,false          |
|   CatServer.googlekey    | 谷歌二次验证的key(可用java -jar cat_server.jar google 命令生成) |
|    CatServer.safecode    | 如果开启双重验证,但是关闭谷歌的话,就会启动安全码,固定不变(限制10位数) |
|       CatServer.Iv       | AES加密的iv值,方便类似geacon_pro等重写的项目，限制为16位,切勿乱改,会出现无法上线问题(默认:abcdefghijklmnop) |
|   stager.checksum-num    |     关于stager的相关配置(强烈建议用profile文件自定义url)     |
|      stager.x86-num      |                     客户端和服务器需一致                     |
|    stager.x86-uri-len    |                     客户端和服务器需一致                     |
|      stager.x64-num      |                     客户端和服务器需一致                     |
|    stager.x64-uri-len    |                     客户端和服务器需一致                     |

##### 相关命令

```bash
运行服务端:
chmod 755 teamserver
./teamserver

Windows下运行(改好配置文件后)
java.exe -jar cat_server.jar server

获取google二次验证配置:
java -jar cat_server.jar google
（Ps:将获取到的SecretKey填入服务端配置中,把data:image/jpeg;base64...这一串复制到浏览器中打开,用谷歌验证器扫描）

运行cna脚本

(如果没开启二次验证)
java -jar cat_server.jar script [host] [port] [user] [password] [cna脚本]

(如果开启二次验证)
java -jar cat_server.jar script [host] [port] [user] [password] [二次验证的密码] [cna脚本]
```

# CAT原版：一些二开说明

1. 去除ListenerConfig中的特征水印

2. 修改Stager Url（checksum8）校验算法

3. 修改默认登录int长度48879,让网上的爆破脚本无法爆破

4. 修改beacon配置信息的默认密钥,不会被默认的脚本获取到配置信息

5. 增加在线主机统计

6. 自定义bypass 360核晶模式:截图,Mimikatz,Hashdump等

7. 去掉遗留的暗桩bug

8. 可自定义修改默认配置文件存放文件名

9. 新加ip归宿地查询

10. 自定义双端版本号

    -------------------------------------------------------------



# 坤坤版 一些二开说明

1.修改部分shellcode特征，现在常规yara无法识别

2.增加Malleable-C2-Randomizer，可以快速生成随机URI profile文件（模板可自行修改）

3.自定义ExternalC2功能。

4.增加上线自动维权插件、检测目标beacon是否存在杀软、上线消息推送插件、沙箱IP黑名单、跨平台目标支持

​	默认不启用，启用执行：`java -jar cat_server.jar script [host] [port] [user] [password] [cna脚本]）`

5.更新IP归属地数据库

6.增加IP黑名单功能（需要sudo，仅linux平台支持），添加IP直接修改ip黑名单.txt即可（注意不要改名），修改之后重新执行sudo ./teamserver

7.修改默认生成的cobaltstrike.store密码



## 👍TODO - star 250+  继续开发以下功能（HVV期间暂停更新）

 - 兼容JDK1.8

 - 增加客户端表格排序功能

 - 增加分组功能（Tools内部版本）

 - 编译几个免杀Fscan、mimikataz、向日葵

 - 增加一些反沙箱功能

 - 把上线语音提示换成鸡你太美（逃



## 修复 CVE-2022-39197

https://github.com/burpheart/CVE-2022-39197-patch



## 🌹致谢项目

https://github.com/TryGOTry/CobaltStrike_Cat_4.5

https://github.com/lintstar/CS-AutoPostChain

https://github.com/raspberryhusky/antiVirusCheck

https://github.com/gloxec/CrossC2

https://github.com/trustedsec/CS-Situational-Awareness-BOF

https://github.com/qwqdanchun/Pillager/blob/main/README_ZH.md

https://github.com/lintstar/LSTAR
