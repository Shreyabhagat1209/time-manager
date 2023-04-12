#This makefile shall create the test_application binary
# This makefile shall be used to create the time_manager.so shared library


all: main

CC = gcc
CFLAGS=-g -Wall -ansi

path=./test/sample_application.c

main: sample_application.o
	$(CC) -o main sample_application.o
			
sample_application.o: sample_application.c
	$(CC) -I$(path) $(CFLAGS) -c sample_application.c	



# all:run
# INCLUDE=../lib/include
create_executable:
	gcc -o test sample_application.c -ltime_lib -L ../lib -Wl,-R../lib
	
run:create_executable
	./test

clean:
	-rm sample_application.o