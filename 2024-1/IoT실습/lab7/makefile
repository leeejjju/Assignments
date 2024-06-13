CC = gcc
IP = 127.0.0.1
PORT = 8080
MSG = "Hello world"

all: client.out


client.out: simple_ws_client.c
	$(CC) $^ -o $@

rs: 
	./wsServer/examples/echo/echo
rc: client.out
	./$^ $(IP) $(PORT) $(MSG)


clean: 
	rm -rf *.out
