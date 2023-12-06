all: tls_chat_clnt.c tls_chat_serv.c 
	gcc tls_chat_clnt.c -o client -lssl -lcrypto -pthread
	gcc tls_chat_serv.c -o server -lssl -lcrypto -pthread

mksubdir:
	mkdir clients
	mkdir clients/1
	mkdir clients/2
	mkdir clients/3
	mkdir clients/4

seperate:
	cp client clients/1
	cp client clients/2
	cp client clients/3
	cp client clients/4

default: chat_clnt.c chat_serv.c
	gcc chat_clnt.c -o client -lssl -lcrypto -pthread
	gcc chat_serv.c -o server -lssl -lcrypto -pthread

clean:
	rm client
	rm server