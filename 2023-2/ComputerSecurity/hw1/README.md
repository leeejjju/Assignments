# 23-2-comsec-hw1


This is HW1 for Computer Security class in HGU.

The program developed in Ubuntu 22.04 LTS evironment.

It provide multithread chatting server and client program in CLI. 

I did not implement file upload system at the end... 


<br>
<br>


## Library version

We using openssl to implement TLS protocol. check the version.
> OpenSSL 3.0.2 15 Mar 2022 (Library: OpenSSL 3.0.2 15 Mar 2022)

## How to use

### 1. Unzip it/clone it

Unzip the zip file or using git clone

> $ git clone https://github.com/leeejjju/23-2-comsec-hw1.git
> 
> $ cd 23-2-comsec-hw1
>


### 2. Use makefile

There is a Makefile. You can compile and make test environment and so on by using it. 

> make

Compile `tls_chat_serv.c` and `tls_chat_clnt.c`

> make mksubdir

Make subdirs for testing

> make seperate

Copy the client exe file to subdirs

> make clean

Remove exe files



### 3. Execute

* client 

> $ ./client [server IP address] [server port number] [your nickname to use]

You can type any text messages and it will deleverd to all the client connected on time. 

The program do not support file upload system yet, sorry. 

---

* server

> $ ./server [port number to open]

You can see the server logs (about the conversation and message type of messages)






<br>
<br>
@22100579 JJLee