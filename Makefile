all:
	gcc -Wincompatible-pointer-types AntiQubick.c util.c client.c allThreads.c commands.c strings.c http.c -lcurl -lpthread -lm -o bot
