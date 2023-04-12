
#TARGET = main

CC = gcc
CFLAGS=-g -Wall -ansi
LDFLAGS= -shared
SRC=src
INC=include

TARGET= test.so
SOURCE = $(wildcard $(SRC)/*.c)
HEADERS= $(wildcard $(INC)/*.h)
OBJECT = $(patsubst %,$(SRC)/%,$(notdir $(SOURCE:.c=.o)))

all:$(TARGET)

$(TARGET): $(OBJECT)
	gcc -shared -fPIC -o libtime_lib.so ./src/time_manager_lib.c

# $(SRC)/$(TARGET):$(OBJECT)
# 	$(CC) -o $@ $^

# $(SRC)/%.o : $(SRC)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(TARGET):$(OBJECT)
# 	gcc -shared -fPIC -o libtime_lib.so time_manager_lib.o
    
# clean :
# 	rm -f $(OBJECT) $(SRC)/$(TARGET)

# help :
# 	@echo "src: $(SOURCE)"
# 	@echo "obj: $(OBJECT)"
