#include <stdio.h>
#include <stdlib.h>

typedef struct {	int chave;} TItem;typedef struct celula {	struct celula *pProx;	TItem item;} TCelula;typedef struct {	TCelula *pTopo;	int tamanho;} TPilha;
void iniciarPilha (TPilha *pPilha);int isVazia (TPilha *pPilha);int push (TPilha *pPilha, TItem x);int pop (TPilha *pPilha, TItem *pX);int peek (TPilha *pPilha, TItem *pX);int tamanho (TPilha *pPilha);
void iniciarPilha (TPilha *pPilha) {	pPilha->pTopo = NULL;	pPilha->tamanho = 0;}int isVazia (TPilha *pPilha) {	return pPilha->pTopo == NULL;}
int push (TPilha *pPilha, TItem x) {	TCelula *novo = (TCelula *) malloc (sizeof (TCelula));	novo->item = x;		novo->pProx = pPilha->pTopo;	pPilha->pTopo = novo;		pPilha->tamanho++;		return 1;}	int pop (TPilha *pPilha, TItem *pX) {	if (isVazia (pPilha))		return 0;			TCelula *pAux = pPilha->pTopo;	*pX = pAux->item;		pPilha->pTopo = pAux->pProx;	free (pAux);		pPilha->tamanho--;		return 1;}	int peek (TPilha *pPilha, TItem *pX) {	if (isVazia (pPilha))		return 0;			*pX = pPilha->pTopo->item;			return 1;}int tamanho (TPilha *pPilha) {	return pPilha->tamanho;}

int main() {
	TPilha pilha;	iniciarPilha (&pilha);	printf("Vazia: %s\n", isVazia(&pilha) == 1 ? "SIM":"NAO");		TItem item1, item2, item3;	item1.chave = 10;	item2.chave = -5;	item3.chave = 20;	push (&pilha, item1);	push (&pilha, item2);	push (&pilha, item3);	printf("Vazia: %s\n", isVazia(&pilha) == 1 ? "SIM":"NAO");		TItem itemTeste;		pop (&pilha, &itemTeste);	printf("Elemento removido: %d\n", itemTeste.chave);		printf("Elementos existentes: %d\n", tamanho(&pilha));		peek (&pilha, &itemTeste);	printf("Elemento no topo: %d\n", itemTeste.chave);
}
