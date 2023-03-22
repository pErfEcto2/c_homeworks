build:
	gcc -o hw -Wall hw.c

clear:
	rm app* *.o 1>/dev/null 2>&1
