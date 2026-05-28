CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
TARGET  = colorear_mapa.exe

SRCS    = main.c \
          mapa.c \
          backtracking.c \
          graphviz.c \
          mapas/niger.c \
          mapas/chad.c \
          mapas/brasil.c \
          mapas/espana.c

OBJS    = $(SRCS:.c=.o)

all: salidas $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

salidas:
	if not exist salidas mkdir salidas

clean:
	del /Q *.o 2>nul
	del /Q mapas\*.o 2>nul
	del /Q $(TARGET) 2>nul
	del /Q salidas\*.dot 2>nul
	del /Q salidas\*.png 2>nul

re: clean all

.PHONY: all clean re salidas