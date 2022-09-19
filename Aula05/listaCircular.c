#include <stdio.h>
#include <stdlib.h>

typedef struct {	int chave;} TItem;typedef struct celula {	struct celula *pAnt;	struct celula *pProx;	TItem item;} TCelula;typedef struct {	TCelula *pPrimeiro;} TLista;
void iniciarLista (TLista *pLista);int isVazia (TLista *pLista);int inserir (TLista *pLista, TItem x);void imprimir (TLista *pLista);int remover (TLista *pLista, int chave);
void iniciarLista (TLista *pLista) {	pLista->pPrimeiro = NULL;}int isVazia (TLista *pLista) {	return pLista->pPrimeiro == NULL;}
int inserir (TLista *pLista, TItem x) {	TCelula *novo = (TCelula *) malloc (sizeof (TCelula));	novo->item = x;		if (isVazia (pLista)) {		novo->pAnt = novo;		novo->pProx = novo;		pLista->pPrimeiro = novo;	} else {		pLista->pPrimeiro->pAnt->pProx = novo;		novo->pAnt = pLista->pPrimeiro->pAnt;				pLista->pPrimeiro->pAnt = novo;		novo->pProx = pLista->pPrimeiro;	}	return 1;}
void imprimir (TLista *pLista) {	TCelula *celula = pLista->pPrimeiro;		printf("Itens da lista: ");		if (celula != NULL) {		do {			printf("%d ", celula->item.chave);			celula = celula->pProx;		} while (celula != pLista->pPrimeiro);	}	printf("\n");}	int remover (TLista *pLista, int chave) {	int houveRemocao = 0;		TCelula* aux = pLista->pPrimeiro;	if (aux != NULL) {		do {			if (aux->item.chave == chave) {				// remover				houveRemocao = 1;								if (aux == pLista->pPrimeiro)					pLista->pPrimeiro = aux->pProx;									if (aux == aux->pAnt) {					// Apenas 1 item na lista					free(aux);					pLista->pPrimeiro = NULL;					break;				} else {					TCelula* celulaParaRemover = aux;					aux = aux->pProx;					celulaParaRemover->pAnt->pProx = celulaParaRemover->pProx;					celulaParaRemover->pProx->pAnt = celulaParaRemover->pAnt;					free(celulaParaRemover);				}											} else {				aux = aux->pProx;			}		} while (aux != pLista->pPrimeiro);	}		return houveRemocao;}

int main() {
	TLista lista;	iniciarLista (&lista);	TItem item1, item2, item3, item4;	item1.chave = 10;	inserir (&lista, item1);	item2.chave = -5;	inserir (&lista, item2);	item3.chave = 20;	inserir (&lista, item3);	item4.chave = -5;	inserir (&lista, item4);		imprimir (&lista);		remover (&lista, 20);	imprimir (&lista);	remover (&lista, -5);	imprimir (&lista);	remover (&lista, 10);	imprimir (&lista);
}
