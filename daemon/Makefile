#This makefile shall create the time-manager executable


TARGET = main

CC = gcc
CFLAGS=-g -Wall -ansi

SRC=src

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(SRC)/%,$(notdir $(SOURCE:.c=.o)))

$(SRC)/$(TARGET):$(OBJECT)
	$(CC) -o $@ $^ -lpthread

$(SRC)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -lthread
clean :
	rm -f $(OBJECT) $(SRC)/$(TARGET)
help :
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"

