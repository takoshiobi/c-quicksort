all: test test2

test: test.o quick_sort.o
	gcc -o test test.o quick_sort.o

test2: test2.o quick_sort_gen.o nobel.o
	gcc -o test2 test2.o nobel.o quick_sort_gen.o

test.o: test.c test.h
	gcc -c test.c

test2.o: test2.c test2.h
	gcc -c test2.c

quick_sort.o: quick_sort.c
	gcc -c quick_sort.c

quick_sort_gen.o: quick_sort_gen.c
	gcc -c quick_sort_gen.c

nobel.o: nobel.c nobel.h
	gcc -c nobel.c
