all:
	gcc AntiQubick.c util.c client.c allThreads.c commands.c strings.c http.c -lcurl -lpthread -lm -o bot
