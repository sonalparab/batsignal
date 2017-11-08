all: batsignal.c
	gcc batsignal.c

run: all
	./a.out

clean:
	rm a.out
	rm msgs
