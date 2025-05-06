
first: first.o second.o
	gcc -o first first.o second.o

first.o: first.c
	gcc -c first.c

second.o: second.c
	gcc -c second.c

clean:
	rm -rf *.o
	rm -rf first