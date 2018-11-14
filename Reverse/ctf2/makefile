all: binary-with-flag binary-test

binary-with-flag: code.c main.s md5.c
	gcc -Wall -m32 $^ -o $@ -Wno-format-truncation -Wno-sequence-point

binary-test: code.c
	gcc -Wall -m32 $^ -o $@ -Wno-format-truncation
