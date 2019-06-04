all: main

main: arvore-binaria.o grafo.o main.c
	gcc main.c -o main arvore-binaria.o grafo.o
    
arvore.o: arvore-binaria.c
	gcc -c arvore-binaria.c

grafo.o: grafo.c
	gcc -c grafo.c

clean:
	rm -o