CC = gcc
LNK = gcc
NASM = nasm
CFLAGS = -ggdb -Wall -m64 -O0 -c
LNKFLAGS = -ggdb -Wall -m64 -O0
ASMFLAGS = -f elf64 -g -Wall
SRCs = $(wildcard *.c)
OBJs := $(SRCs:%.c=%.o)


all: main

%.o: %.c
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.asm
		$(NASM) $(ASMFLAGS) $< -o $@

main : $(OBJs)
		rm main.exe -f
		$(LNK) $(LNKFLAGS) $^ -o $@

clean:
		rm *.o -f