CC = gcc
CFLAGS = -c -fPIC -Wall
SOFLAG = -shared
BIN_PATH = /usr/bin
LIB_PATH = /usr/lib

all: lib electrotest

lib: lib/libresistance.so lib/libpower.so lib/libcomponent.so

clean:
	rm -rf electrotest lib/ *.o *.so

electrotest: main.c
	$(CC) -o $@ $< -Llib -lresistance -lpower -lcomponent -Wl,-rpath,lib -lm

lib/%.so: %.o
	@[ -d lib ] || mkdir lib
	$(CC) -o $@ $< $(SOFLAG)

%.o: %.c %.h
	$(CC) $(CFLAGS) $<

install: all
	sudo install -m 755 electrotest $(BIN_PATH)
	sudo install lib/* $(LIB_PATH)
	make clean
