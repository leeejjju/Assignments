SERVER = 127.0.0.1
PORT = 9999

default: 
	mkdir -p result
	gcc occ_client.c -o client -pthread
	gcc occ_server.c -o server -pthread

s:
	./server $(PORT)
run:
	./client $(SERVER) $(PORT) test.c
run2:
	./client $(SERVER) $(PORT) popen.c
clean:
	rm client
	rm server
