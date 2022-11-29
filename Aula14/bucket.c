#include <stdio.h>
#include <stdlib.h>

#define DADOS 10
#define TAM_BUCKET 100
#define NUM_BUCKET 10

typedef struct {
	int chave;
} TItem;

typedef struct {
	int quantidade;
	TItem balde[TAM_BUCKET];
} Bucket;

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

void bucketSort (TItem *v, int n)
{                                     
	Bucket b[NUM_BUCKET];                                    
	int i, j, k;
	
	for (i=0; i < NUM_BUCKET; i++)
		b[i].quantidade = 0;
         
	for( i=0; i < n; i++)
	{
		j = NUM_BUCKET - 1;
		while (1)
		{
			if (j < 0)
				break;
				
			if (v[i].chave >= j*10)
			{
				b[j].balde[b[j].quantidade] = v[i];
				(b[j].quantidade)++;
				break;
			}
			j--;
		}
	}
         
	for (i=0; i < NUM_BUCKET; i++)
		if (b[i].quantidade > 0)
			insertionSort (b[i].balde, b[i].quantidade);
         
	i = 0;
	for (j=0; j < NUM_BUCKET; j++)
	{
		for (k=0; k < b[j].quantidade; k++)
		{
			v[i] = b[j].balde[k];
			i++;
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
	
	bucketSort (dados, DADOS);
	
	printf ("Resultado da ordenação: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\n");
}
