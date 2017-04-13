all: AntiQubick.o util.o client.o allThreads.o commands.o strings.o http.o
	gcc -c -Wincompatible-pointer-types AntiQubick.c util.c client.c allThreads.c commands.c strings.c http.c
	gcc AntiQubick.o util.o client.o allThreads.o commands.o strings.o http.o -o BomjoBot -lm -lpthread -lcurl
clean:
	rm *.o
	rm BomjoBot
install:
	cp BomjoBot /usr/sbin/BomjoBot
