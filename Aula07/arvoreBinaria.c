#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
	int informacao;
} TItem;

typedef struct No {
	TItem item;
	struct No *pEsq, *pDir;
} TNo;


TNo* criarNo (TItem x) {
	TNo *pAux = (TNo*) malloc (sizeof(TNo));
	pAux->item = x;
	pAux->pEsq = NULL;
	pAux->pDir = NULL;
	return pAux;
}

TNo* inserirNo (TNo *pR, TItem x) {
	if (pR == NULL) {
		pR = criarNo (x);
	} else {	
		if (x.chave < pR->item.chave)
			pR->pEsq = inserirNo (pR->pEsq, x);
		else
			pR->pDir = inserirNo (pR->pDir, x);
	}
	
	return pR;
}

TItem* pesquisa (TNo* pR, int chave) {
	if (pR == NULL)
		return NULL;
		
	if (chave < pR->item.chave)
		return pesquisa (pR->pEsq, chave);
	
	if (chave > pR->item.chave)
		return pesquisa (pR->pDir, chave);
		
	return &(pR->item);
}

void preOrdem (TNo *p) {
	if (p == NULL) 
		return;
	printf("chave: %d - info: %d\n", p->item.chave, p->item.informacao );
	preOrdem (p->pEsq);
	preOrdem (p->pDir);
}

void posOrdem (TNo *p) {
	if (p == NULL)
		return;
	posOrdem (p->pEsq);
	posOrdem (p->pDir);
	printf("chave: %d - info: %d\n", p->item.chave, p->item.informacao );
}

void emOrdem (TNo *p) {
	if (p == NULL)
		return;
	emOrdem (p->pEsq);
	printf("chave: %d - info: %d\n", p->item.chave, p->item.informacao );
	emOrdem (p->pDir);
}



int main (void)
{
	int i;
	
	printf ("Criando a árvore...\n");
	TNo *arvore = NULL;
	
	printf ("\nInserindo nós...\n");
	for (i = 0; i < 10; i++) {
		TItem item;
		item.chave = rand() % 50;
		item.informacao = rand() % 100000;
		
		printf ("Chave: %d - Info: %d\n", item.chave, item.informacao);
		arvore = inserirNo (arvore, item);
	}
	
	printf ("\nNos existentes:\n"); 
	preOrdem (arvore);
		
	printf ("\nPesquisando...\n");
	for (i = 0; i < 20; i++) {
		int chaveSorteada = rand() % 50;
		printf ("Procurando chave %d... ", chaveSorteada);
		
		TItem *item = pesquisa (arvore, chaveSorteada);
		
		if (item == NULL)
			printf ("não encontrada\n");
		else
			printf ("encontrada, info: %d\n", item->informacao);
	}
}
