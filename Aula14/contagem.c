#include <stdio.h>
#include <stdlib.h>

#define DADOS 10

typedef struct {
	int chave;
} TItem;

void contagem (TItem *A, TItem *B, int n, int k)
{
	int i;
	int C[k]; 
	
	for (i = 0; i < k; i++)
		C[i] = 0;
		
	for (i = 0; i < n; i++)
		C[A[i].chave] = C[A[i].chave] + 1;
	
	for (i = 1; i < k; i++)
		C[i] = C[i] + C[i-1];
		
	for (i = n-1; i >= 0; i--)
	{
		B[C[A[i].chave]-1] = A[i];
		C[A[i].chave] = C[A[i].chave] - 1;
	}
}

int main (void)
{
	TItem dados[DADOS], dadosOrdenado[DADOS];
	int i, k;
	
	k = 10;
	
	printf ("Vetor inicial: ");
	for (i=0; i<DADOS; i++) {
		dados[i].chave = rand() % k;
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\nExecutando a ordenação...\n");
	
	contagem (dados, dadosOrdenado, DADOS, k);
	
	printf ("Resultado da ordenação: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dadosOrdenado[i].chave);
	}
	
	printf ("\n");
}
