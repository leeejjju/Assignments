CC = gcc
.PHONY : clean
IP = 127.0.0.1
PORT = 9999
FILE = test


fileup: fileup_clnt.out fileup_serv.out

#fileup
fileup_clnt.out: fileup_clnt.c
	$(CC) $^ -o $@ 
fileup_serv.out: fileup_serv.c
	$(CC) $^ -o $@ 

#run
rs: fileup_serv.out
	mkdir -p dest
	./$^ $(PORT)
rc: fileup_clnt.out
	./$^ $(IP) $(PORT) $(FILE)

clean:
	rm -f *.out



