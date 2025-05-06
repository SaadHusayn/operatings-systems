executable: first.o second.o
	gcc first.o second.o -o executable

first.o: first.c
	gcc -c first.c

second.o: second.c
	gcc -c second.c

run:
	./executable

clean:
	rm -rf *.o
	rm -rf executable
