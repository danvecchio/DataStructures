#include <stdio.h>
#include <stdlib.h>

#define DADOS 10

typedef struct {
	int chave;
} TItem;

typedef struct celula {
	struct celula *pProx;
	TItem item;
} TCelula;

typedef struct {
	TCelula *pTopo;
	int tamanho;
} TPilha;

void iniciarPilha (TPilha *pPilha);
int isVazia (TPilha *pPilha);
int push (TPilha *pPilha, int chave);
int pop (TPilha *pPilha, int *chave);

void quickSort (TItem *v, int n);
void quickSortOrdena (TItem *v, int esq, int dir);
void quickSortParticao (TItem *v, int esq, int dir, int *i, int *j);



void iniciarPilha (TPilha *pPilha) {
	pPilha->pTopo = NULL;
	pPilha->tamanho = 0;
}

int isVazia (TPilha *pPilha) {
	return pPilha->pTopo == NULL;
}

int push (TPilha *pPilha, int chave) {
	TItem x;
	x.chave = chave;
	TCelula *novo = (TCelula *) malloc (sizeof (TCelula));
	novo->item = x;
	
	novo->pProx = pPilha->pTopo;
	pPilha->pTopo = novo;
	
	pPilha->tamanho++;
	
	return 1;
}
	
int pop (TPilha *pPilha, int *chave) {
	if (isVazia (pPilha))
		return 0;
		
	TCelula *pAux = pPilha->pTopo;
	*chave = pAux->item.chave;
	
	pPilha->pTopo = pAux->pProx;
	free (pAux);
	
	pPilha->tamanho--;
	
	return 1;
}



void quickSort (TItem *v, int n) {
	quickSortOrdena (v, 0, n-1);
}

void quickSortOrdena (TItem *v, int esq, int dir) {
	int i, j;
	
	quickSortParticao (v, esq, dir, &i, &j);
	
	if (esq < j)
		quickSortOrdena (v, esq, j);
	if (i < dir)
		quickSortOrdena (v, i, dir);
}

void quickSortParticao (TItem *v, int esq, int dir, int *i, int *j) {
	TItem pivo, aux;

	*i = esq; 
	*j = dir;
	pivo = v [(* i + *j) /2];

	do {
		while (pivo.chave > v[*i].chave) 
			(*i)++;
			
		while (pivo.chave < v[*j].chave) 
			(*j)--;

		if (*i <= *j) {
			aux = v[*i];
			v[*i] = v[*j];
			v[*j] = aux ;
			(*i)++; 
			(*j)--;
		}
	} while (*i <= *j);
}

void quickSortIterativo (TItem *v, int n) {
	TPilha pilhaDir, pilhaEsq;
	int esq, dir, i, j;

	iniciarPilha (&pilhaDir);
	iniciarPilha (&pilhaEsq);
	esq = 0;
	dir = n - 1;

	push (&pilhaDir, dir);
	push (&pilhaEsq, esq);

	do {
		if (dir > esq) {
			quickSortParticao (v, esq, dir, &i, &j);
			push (&pilhaDir, j);
			push (&pilhaEsq, esq);
			esq = i;
		} else {
			pop (&pilhaDir, &dir);
			pop (&pilhaEsq, &esq);
		}
	} while (!isVazia (&pilhaDir));
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
	
	quickSort (dados, DADOS);
	//quickSortIterativo (dados, DADOS);
	
	printf ("Resultado da ordenação: ");
	for (i=0; i<DADOS; i++) {
		printf ("%d ", dados[i].chave);
	}
	
	printf ("\n");
}
