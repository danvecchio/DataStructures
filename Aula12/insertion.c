#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DADOS 10

typedef struct {
	int chave;
} TItem;

void insertionSort (TItem *v, int n) {
	int i, j;
	TItem aux;
	
	for (i = 1; i < n; i++) {
		aux = v[i];
		j = i - 1;
		while (j >= 0 && aux.chave < v[j].chave) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = aux;
	}
}

void insertionSortSentinel (TItem *v, int n) {
	int i, j;
	TItem aux;

	for (i = 2; i <= n; i++) {
		aux = v[i];
		j = i;
		while (v[j-1].chave > aux.chave) {
			v[j] = v[j-1];
			j--;
		}
		v[j] = aux;
	}
}

int main (void)
{
	TItem dados[DADOS];
	TItem dados2[DADOS+1];
	int i;
	
	printf ("Vetor inicial: ");
	dados2[0].chave = INT_MIN;
	for (i=0; i<DADOS; i++) {
		int valor = rand() % 100;
		dados[i].chave = valor;
		dados2[i+1].chave = valor;
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\nExecutando a ordenação...\n");
	
	insertionSort (dados, DADOS);
	insertionSortSentinel (dados2, DADOS);
	
	printf ("Resultado da ordenação:\n");
	printf ("Normal: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\nCom sentinela: ");
	for (i=1; i<=DADOS; i++) {
		printf ("%d ", dados2[i].chave);
	}
	
	printf ("\n");
}
