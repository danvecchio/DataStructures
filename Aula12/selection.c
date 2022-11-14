#include <stdio.h>
#include <stdlib.h>

#define DADOS 10

typedef struct {
	int chave;
} TItem;

void selectionSort (TItem *v, int n) {
	int i, j, min;
	TItem aux;
	
	for (i = 0; i < n-1; i++) {
		min = i;
		for (j = i+1; j < n; j++) {
			if (v[j].chave < v[min].chave) {
				min = j;
			}
		}
		
		if (i != min) {
			aux = v[min];
			v[min] = v[i];
			v[i] = aux;
		}
	}
}

int main (void)
{
	TItem dados[DADOS];
	int i;
	
	printf ("Vetor inicial: ");
	for (i=0; i<DADOS; i++) {
		dados[i].chave = rand() % 100;
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\nExecutando a ordenação...\n");
	
	selectionSort (dados, DADOS);
	
	printf ("Resultado da ordenação: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\n");
}
