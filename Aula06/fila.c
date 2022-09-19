#include <stdio.h>
#include <stdlib.h>

typedef struct {	int chave;} TItem;typedef struct celula {	struct celula *pProx;	TItem item;} TCelula;typedef struct {	TCelula *pInicio, *pFim;	int tamanho;} TFila;
void iniciarFila (TFila *pFila);int isVazia (TFila *pFila);int enqueue (TFila *pFila, TItem x);int dequeue (TFila *pFila, TItem *pX);int peek (TFila *pFila, TItem *pX);int tamanho (TFila *pFila);
void iniciarFila (TFila *pFila) {	pFila->pInicio = NULL;	pFila->pFim = NULL;	pFila->tamanho = 0;}int isVazia (TFila *pFila) {	return pFila->pInicio == NULL;}
int enqueue (TFila *pFila, TItem x) {	TCelula *novo = (TCelula *) malloc (sizeof (TCelula));	novo->item = x;	novo->pProx = NULL;		if (isVazia (pFila)) {		pFila->pInicio = novo;	} else {		pFila->pFim->pProx = novo;	}		pFila->pFim = novo;	pFila->tamanho++;		return 1;}	int dequeue (TFila *pFila, TItem *pX) {	if (isVazia (pFila))		return 0;			TCelula *pAux = pFila->pInicio;	*pX = pAux->item;		pFila->pInicio = pAux->pProx;	free (pAux);		pFila->tamanho--;		return 1;}	int peek (TFila *pFila, TItem *pX) {	if (isVazia (pFila))		return 0;			*pX = pFila->pInicio->item;			return 1;}int tamanho (TFila *pFila) {	return pFila->tamanho;}

int main() {
	TFila fila;	iniciarFila (&fila);	printf("Vazia: %s\n", isVazia(&fila) == 1 ? "SIM":"NAO");		TItem item1, item2, item3;	item1.chave = 10;	item2.chave = -5;	item3.chave = 20;	enqueue (&fila, item1);	enqueue (&fila, item2);	enqueue (&fila, item3);	printf("Vazia: %s\n", isVazia(&fila) == 1 ? "SIM":"NAO");		TItem itemTeste;		dequeue (&fila, &itemTeste);	printf("Elemento removido: %d\n", itemTeste.chave);		printf("Elementos existentes: %d\n", tamanho(&fila));		peek (&fila, &itemTeste);	printf("Elemento no início: %d\n", itemTeste.chave);
}
