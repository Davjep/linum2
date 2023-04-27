CC=gcc
CFLAGS=-Wall -Werror -std=c99
LDFLAGS=-lpam -lpam_misc
CUNITFLAGS=-lcunit -lcomponent -lpower -lresistance -lm
U=uppgift_

all: check_user catchsignalinscript electro_test

check_user: $(U)6/check_user.c
	$(CC) $(CFLAGS) -o $(U)6/check_user $(U)6/check_user.c $(LDFLAGS)

catchsignalinscript: $(U)4/catchsignalinscript.c
	$(CC) $(CFLAGS) -o $(U)4/catchsignalinscript $(U)4/catchsignalinscript.c

electro_test: $(U)7/electro_test.c
	$(CC) -o $(U)7/electro_test $(U)7/electro_test.c $(CUNITFLAGS)

clean:
	rm -f $(U)6/check_user $(U)6/*.o $(U)6/*.so
	rm -f $(U)4/catchsignalinscript $(U)4/*.o $(U)4/*.so
	rm -f $(U)7/electro_test $(U)7/*.o $(U)7/*.so