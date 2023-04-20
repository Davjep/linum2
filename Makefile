CC=gcc
CFLAGS=-Wall -Werror -std=c99
LDFLAGS=-lpam -lpam_misc

all: check_user catchsignalinscript

check_user: uppgift_6/check_user.c
	$(CC) $(CFLAGS) -o uppgift_6/check_user uppgift_6/check_user.c $(LDFLAGS)

catchsignalinscript: uppgift_4/catchsignalinscript.c
	$(CC) $(CFLAGS) -o uppgift_4/catchsignalinscript uppgift_4/catchsignalinscript.c


clean:
	rm -f uppgift_6/check_user
	rm -f uppgift_4/catchsignalinscript