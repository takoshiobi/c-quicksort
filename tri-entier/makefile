all: test

test: test.o quick_sort.o
	gcc -o test test.o quick_sort.o

test.o: test.c test.h
	gcc -c test.c

test2.o: test2.c test2.h
	gcc -c test2.c

quick_sort.o: quick_sort.c
	gcc -c quick_sort.c
