# Une implantation d’un tri rapide pour un tableau d’entier

La fonction [`quicksort_int`][quicksort] a été realisée.

### Tester

le programme qui la teste se nomme [`test.c`][main]
(J'ai fait un makefile pour la compilation)

```shell
$ make test
$ ./test
...
```

**Makefile**

```shell
all: test

test: test.o quick_sort.o
	gcc -o test test.o quick_sort.o

test.o: test.c test.h
	gcc -c test.c

test2.o: test2.c test2.h
	gcc -c test2.c

quick_sort.o: quick_sort.c
	gcc -c quick_sort.c
```
[quicksort]:quick_sort.c
[main]:test.c
