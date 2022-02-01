all: test_poly perf_poly

GCC_OPT= -Wall

perf_poly: perf_poly.o poly.o
	gcc -o perf_poly perf_poly.o poly.o

perf_poly.o: perf_poly.c poly.h
	gcc $(GCC_OPT) -c perf_poly.c


test_poly: test_poly.o poly.o
	gcc -o test_poly test_poly.o poly.o

test_poly.o: test_poly.c poly.h
	gcc $(GCC_OPT) -c test_poly.c

poly.o: poly.c poly.h
	gcc $(GCC_OPT) -c poly.c

clean:
	rm -f test_poly perf_poly *.o *~
