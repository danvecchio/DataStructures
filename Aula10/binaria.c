#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
	int info;
	int info2;
} TItem;

typedef struct {
	TItem *v;
	int n, max;
} TDicionario;

void iniciarDicionario (TDicionario *d) {
	d->n = 0;
	d->max = 10;
	d->v = (TItem*) malloc (sizeof (TItem) * d->max);
}

void inserir (TDicionario *d, TItem x) {
	if (d->n == d->max) {
		d->max *= 2;
		d->v = (TItem*) realloc (d->v, sizeof (TItem) * d->max);
	}
	
	d->v[d->n++] = x;
}

int buscaBinaria (TDicionario *d, int esq, int dir, int chave) {
	int meio = (esq + dir) / 2;
	
	if (d->v[meio].chave != chave && esq >= dir)
		return -1;
	else if (chave > d->v[meio].chave)
		return buscaBinaria(d, meio+1, dir, chave);
	else if (chave < d->v[meio].chave)
		return buscaBinaria(d, esq, meio-1, chave);
	else
		return meio;
}

int busca (TDicionario *d, int chave) {
	if (d->n == 0)
		return -1;
	else
		return buscaBinaria (d, 0, d->n-1, chave);
}

int buscaIterativa (TDicionario *d, int chave) {
	int i, esq, dir;
	
	if (d->n == 0) 
		return -1;
		
	esq = 0;
	dir = d->n-1;
	
	do {
		i = (esq + dir) / 2;
		if (chave > d->v[i].chave) 
			esq = i + 1;
		else 
			dir = i - 1;
	} while (chave != d->v[i].chave && esq <= dir);
	
	if (chave == d->v[i].chave) 
		return i;
	else 
		return -1;
}

int main (void)
{
	TDicionario d;
	int i;
	
	printf ("Criando dicionário...\n");
	iniciarDicionario (&d);
	
	printf ("Inserindo itens...\n");
	for (i = 0; i < 21; i++) {
		TItem item;
		// Garantindo que a insercao seja feita em ordem
		item.chave = i * 2;
		item.info = rand();
		item.info2 = rand();
		
		inserir (&d, item);
	}
	printf ("%d itens foram inseridos e o vetor tem alocado %d espaços.\n", d.n, d.max);
		
	printf ("Buscando itens\n");
	for (i = 0; i < 5; i++) {
		int chaveSorteada = rand() % 50;
		printf ("Procurando chave %d... ", chaveSorteada);
		
		int indice = busca (&d, chaveSorteada);
		//int indice = buscaIterativa (&d, chaveSorteada);
		
		if (indice == -1)
			printf ("não encontrada\n");
		else
			printf ("encontrada no índice %d\n", indice);
	}
}
