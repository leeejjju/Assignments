CC = gcc

all:  task2

basic: basic_pub.out basic_sub.out

task1: multiple_pub.out multiple_sub.out

task2: mqtt_chat_client.out


basic_pub.out: basic_pub.c
	$(CC) $^ -o $@ -lmosquitto
basic_sub.out: basic_sub.c
	$(CC) $^ -o $@ -lmosquitto

multiple_pub.out: multiple_pub.c
	$(CC) $^ -o $@ -lmosquitto
multiple_sub.out: multiple_sub.c
	$(CC) $^ -o $@ -lmosquitto

mqtt_chat_client.out: mqtt_chat_client.c
	$(CC) $^ -o $@ -lmosquitto -pthread


clean: 
	rm -rf *.out
