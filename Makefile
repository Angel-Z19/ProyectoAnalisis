CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
TARGET  = colorear_mapa

# Archivos fuente
SRCS    = main.c \
          mapa.c \
          backtracking.c \
          graphviz.c \
          mapas/niger.c \
          mapas/chad.c \
          mapas/brasil.c \
          mapas/espana.c

OBJS    = $(SRCS:.c=.o)

# Regla principal
all: salidas $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar cada .c en su .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorio de salidas si no existe
salidas:
	mkdir -p salidas

# Limpiar compilados
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f salidas/*.dot salidas/*.png

# Limpiar todo incluyendo ejecutable
fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re salidas
