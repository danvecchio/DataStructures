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

int busca (TDicionario *d, int chave) {
	int i;
	for (i = 0; i < d->n; i++)
		if (d->v[i].chave == chave)
			return i;
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
		if (indice == -1)
			printf ("não encontrada\n");
		else
			printf ("encontrada no índice %d\n", indice);
	}
}
