DIRS	= lib student
.PHONY:	all clean
PORT = 9999
IP = 127.0.0.1

all:	
		@for d in $(DIRS); \
		do \
				$(MAKE)	-C $$d; \
		done


rs: StudentServ
	./$^ $(PORT)

rc: StudentClnt
	./$^ $(IP) $(PORT)


clean:
		@for d in $(DIRS);	\
		do \
				$(MAKE) -C $$d clean; \
		done
