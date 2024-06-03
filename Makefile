#Laboratorio 5 -- Makefile -- Valeria Jarquin Vargas, B83986

CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lm

SRCS = main.c double_list.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# Nombre del ejecutable
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

