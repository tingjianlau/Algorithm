CC=gcc
OBJS=main.o basicKnnClassifier.o
CFLAGS=-D_DEBUG

main:$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY:clean
clean:
	-rm main *.o
