#include <stdio.h>
#include <stdlib.h>

#define DADOS 10

typedef struct {
	int chave;
} TItem;

void bubbleSort (TItem *v, int n) {
	int i, j;
	TItem aux;
	
	for (i = 0; i < n-1; i++) {
		for (j = 1; j < n-i; j++) {
			if (v[j].chave < v[j-1].chave) {
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
			}
		}
	}
}

void bubbleSort2 (TItem *v, int n) {
	int i, j, troca;
	TItem aux;
	
	for (i = 0; i < n-1; i++) {
		troca = 0;
		for (j = 1; j < n-i; j++) {
			if (v[j].chave < v[j-1].chave) {
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				troca++;
			}
		}
		
		if (troca == 0)
			break;
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
	
	bubbleSort (dados, DADOS);
	
	printf ("Resultado da ordenação: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\n");
}
