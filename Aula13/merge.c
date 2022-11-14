#include <stdio.h>
#include <stdlib.h>

#define DADOS 10

typedef struct {
	int chave;
} TItem;


void mergeSort (TItem *v, int n);
void mergeSortOrdena (TItem *v, int esq, int dir);
void mergeSortIntercala (TItem *v, int esq, int meio, int dir);
void mergeSortIterativo (TItem *v, int n);


void mergeSort (TItem *v, int n) {
	mergeSortOrdena (v, 0, n-1);
}

void mergeSortOrdena (TItem *v, int esq, int dir) {
	if (esq < dir) {
		int meio = (esq + dir) / 2;
		mergeSortOrdena (v, esq, meio);
		mergeSortOrdena (v, meio+1, dir);
		mergeSortIntercala (v, esq, meio, dir);
	}
}

void mergeSortIntercala (TItem *v, int esq, int meio, int dir) {
	int i, j, k;
	int a_tam = meio - esq + 1;
	int b_tam = dir - meio;
	TItem *a = (TItem *) malloc (sizeof (TItem) * a_tam);
	TItem *b = (TItem *) malloc (sizeof (TItem) * b_tam);

	for (i = 0; i < a_tam; i++) 
		a[i] = v[i+esq];
	for (i = 0; i < b_tam; i++) 
		b[i] = v[i+meio+1];
		
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) 
			v[k] = b[j++];
		else if (j == b_tam) 
			v[k] = a[i++];
		else if (a[i].chave < b[j].chave) 
			v[k] = a[i++];
		else 
			v[k] = b[j++];
	}
	
	free (a); 
	free (b);
}

void mergeSortIterativo (TItem *v, int n) {
	int esq, dir;
	int b = 1;
	while (b < n) {
		esq = 0;
		while (esq + b < n) {
			dir = esq + 2 * b;
			if (dir > n) 
				dir = n;
			mergeSortIntercala (v, esq, esq+b-1, dir-1);
			esq = esq + 2 * b;
		}
		b *= 2;
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
	
	mergeSort (dados, DADOS);
	//mergeSortIterativo (dados, DADOS);
	
	printf ("Resultado da ordenação: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\n");
}
