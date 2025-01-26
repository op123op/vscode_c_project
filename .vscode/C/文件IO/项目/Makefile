#定义变量保存gcc,arm-linux-gcc
CC=gcc

T=bin/main

CONFIG=-I./include -L./lib  


SRCS=$(wildcard ./src/*.c)
OBJS=$(patsubst %.c, %.o, $(SRCS))

$(T):$(OBJS)
		$(CC) -o $@ $^ $(CONFIG)

%.o:%.c
		$(CC) -c $< -o $@ $(CONFIG)

clean:
		rm ./src/*.o $(T) 
