#include <stdio.h>
#include <stdlib.h>

typedef struct {	int chave;} TItem;typedef struct celula {	struct celula *pProx;	TItem item;} TCelula;typedef struct {	TCelula *pPrimeiro, *pUltimo;} TLista;
void iniciarLista (TLista *pLista);int isVazia (TLista *pLista);int inserir (TLista *pLista, TItem x);int removerPrimeiro (TLista *pLista, TItem *pX);void imprimir (TLista *pLista);
void iniciarLista (TLista *pLista) {	pLista->pPrimeiro = (TCelula *) malloc (sizeof (TCelula));	pLista->pUltimo = pLista->pPrimeiro;	pLista->pPrimeiro->pProx = NULL;}int isVazia (TLista *pLista) {	return pLista->pPrimeiro == pLista->pUltimo;}
int inserir (TLista *pLista, TItem x) {	pLista->pUltimo->pProx = (TCelula *) malloc (sizeof (TCelula));	pLista->pUltimo = pLista->pUltimo->pProx;	pLista->pUltimo->item = x;	pLista->pUltimo->pProx = NULL;	return 1;}
int removerPrimeiro (TLista *pLista, TItem *pX) {	if (isVazia (pLista))		return 0;	TCelula *pAux;	pAux = pLista->pPrimeiro->pProx;	*pX = pAux->item;	pLista->pPrimeiro->pProx = pAux->pProx;	free (pAux);	return 1;}

int main() {
	TLista lista;	iniciarLista (&lista);	printf("Vazia: %s\n", isVazia(&lista) == 1 ? "SIM":"NAO");	TItem item1, item2;	item1.chave = 10;	inserir (&lista, item1);	item2.chave = -5;	inserir (&lista, item2);	//imprimir (&lista);	printf("Vazia: %s\n", isVazia(&lista) == 1 ? "SIM":"NAO");	TItem itemRemovido;	removerPrimeiro (&lista, &itemRemovido);	printf("Item removido: %d\n", itemRemovido.chave);	//imprimir (&lista);
}
