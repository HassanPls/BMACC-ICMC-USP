CC = gcc

C11 = -std=c11
CFLAGS = -Wall -Wextra -O2 $(C11)

EXEC = trabalho
GERADOR = gerador

SRCS = main.c deck.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC) $(GERADOR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(GERADOR): gerador.c
	$(CC) $(CFLAGS) gerador.c -o $(GERADOR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC) $(GERADOR) entrada.txt