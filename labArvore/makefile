all: esqueleto

esqueleto: arvore-binaria.o filas-listas.o lista-encadeada.o main.c
	gcc main.c -o main arvore-binaria.o filas-listas.o lista-encadeada.o

arvore-binaria.o: arvore-binaria.c
	gcc -c arvore-binaria.c

filas-listas.o: filas-listas.c
	gcc -c filas-listas.c

lista-encadeada.o:lista-encadeada.c
	gcc -c lista-encadeada.c

clean:
	rm -o

