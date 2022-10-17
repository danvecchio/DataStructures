#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
} TItem;

typedef struct No {
	TItem item;
	struct No *pEsq, *pDir;
} TNo;



int altura (TNo* pRaiz) { 
	int alturaEsq, alturaDir;
	 
	if (pRaiz == NULL) 
		return -1; 
		
	alturaEsq = altura (pRaiz->pEsq);
	alturaDir = altura (pRaiz->pDir); 

	if (alturaEsq > alturaDir) 
		return alturaEsq + 1; 
	else 
		return alturaDir + 1; 
}

int fb (TNo* pRaiz) {
	if (pRaiz == NULL)
		return 0;
		
	return altura (pRaiz->pEsq) - altura (pRaiz->pDir);
}

TNo* rotacaoSimplesDireita (TNo* pR) {
	TNo *pAux = pR->pEsq;
	pR->pEsq = pAux->pDir;
	pAux->pDir = pR;
	return pAux;
}

TNo* rotacaoSimplesEsquerda (TNo* pR) {
	TNo *pAux = pR->pDir;
	pR->pDir = pAux->pEsq;
	pAux->pEsq = pR;
	return pAux;
}

TNo* balancaDireita (TNo* pR) { 
	int valorFb = fb (pR->pDir); 
	if (valorFb <= 0) { 
		pR = rotacaoSimplesEsquerda (pR); 
	} else { 
		pR->pDir = rotacaoSimplesDireita (pR->pDir);
		pR = rotacaoSimplesEsquerda (pR); 
	} 
	return pR;
}

TNo* balancaEsquerda (TNo* pR) {
	int valorFb = fb (pR->pEsq);
	if (valorFb >= 0) {
		pR = rotacaoSimplesDireita(pR);
	} else {
		pR->pEsq = rotacaoSimplesEsquerda (pR->pEsq);
		pR = rotacaoSimplesDireita (pR);
	}
	return pR;
}

TNo* balanceamento (TNo* pR) {
	int valorFb = fb (pR);
	if (valorFb > 1)
		pR = balancaEsquerda(pR);
	else if (valorFb < -1)
		pR = balancaDireita(pR);
	return pR;
}

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
		if (x.chave < pR->item.chave) {	
			pR->pEsq = inserirNo (pR->pEsq, x);
		} else {
			pR->pDir = inserirNo (pR->pDir, x);
		}
		pR = balanceamento (pR);
	}
	
	return pR;
}

TNo* removerNo (TNo *pR, int chave) {
	TNo *aux;
	
    if (pR == NULL) 
		return pR;
 
    // Se a chave for menor, procurar na subarvore da esquerda
    if (chave < pR->item.chave)
        pR->pEsq = removerNo (pR->pEsq, chave);
 
    // Se for maior, procurar na subarvore da direita
    else if (chave > pR->item.chave)
        pR->pDir = removerNo (pR->pDir, chave);
 
    // Se tiver o mesmo valor, entao este no deve ser removido
    else {
        // No com apenas 1 filho ou nenhum
        if (pR->pEsq == NULL) {
            aux = pR->pDir;
            free (pR);
            return aux;
        } else if (pR->pDir == NULL) {
            aux = pR->pEsq;
            free (pR);
            return aux;
        }
 
        // No com 2 filhos: obter no sucessor (o no mais a esquerda da sub-árvore direita)
        aux = pR->pDir;
		while (aux->pEsq != NULL)
			aux = aux->pEsq;	 
 
        // Copiando o sucessor
        pR->item = aux->item;
 
        // Removendo o no copiado
        pR->pDir = removerNo (pR->pDir, aux->item.chave);
    }
    
    pR = balanceamento (pR);
    
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
	printf("chave: %d\n", p->item.chave );
	preOrdem (p->pEsq);
	preOrdem (p->pDir);
}


int main (void)
{
	//int i;
	
	printf ("Criando a árvore...\n");
	TNo *arvoreAvl = NULL;
	
	printf ("\nInserindo nós...\n");
	/*for (i = 0; i < 10; i++) {
		TItem item;
		item.chave = rand() % 50;
		
		printf ("Chave: %d\n", item.chave);
		arvoreAvl = inserirNo (arvoreAvl, item);
	}*/
	
	TItem item; 
	item.chave = 10; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 20; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 5; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 8; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 12; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 22; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 23; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 24; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 11; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 13; arvoreAvl = inserirNo (arvoreAvl, item);
	item.chave = 18; arvoreAvl = inserirNo (arvoreAvl, item);
	preOrdem (arvoreAvl);
	
	
	printf ("\nRemovendo nós...\n");
	arvoreAvl = removerNo (arvoreAvl, 22);
	arvoreAvl = removerNo (arvoreAvl, 11);
	arvoreAvl = removerNo (arvoreAvl, 5);
	arvoreAvl = removerNo (arvoreAvl, 10);
	
	printf ("\nImprimindo...\n");
	preOrdem (arvoreAvl);
}
