CC = gcc
CFLAGS = -o

src = main.c
output = to_do

$(output): $(src)
	$(CC) $(src) $(CFLAGS) $@
