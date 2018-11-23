main: poG.o WGraph.o
	gcc -o main poG.o WGraph.o
poG.o : poG.c WGraph.h
	gcc -Wall -Werror -std=c11 -c poG.c
WGraph.o : WGraph.c WGraph.h
	gcc -Wall -Werror -std=c11 -c WGraph.c
clean:
	rm -f main main.o cardRecord.o cardLL.o core
