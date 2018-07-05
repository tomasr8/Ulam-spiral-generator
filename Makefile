all:
	gcc -Wall -Werror -Wpedantic -Wextra -std=c99 ulam.c ppm.c util.c -o ulam -lm

clean:
	rm -f ./ulam
