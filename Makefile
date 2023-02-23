all:
	gcc -c contatinho.c -o contatinho.o
	gcc main.c contatinho.o -o main

run:
	./main

clear:	
	rm ./main ./contatinho.o