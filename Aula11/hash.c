#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
} TItem;

typedef struct celula {
	struct celula *pProx;
	TItem item;
} TCelula;

typedef struct {
	TCelula *pPrimeiro, *pUltimo;
} TLista;

typedef struct {
	int n;
	int m;
	TLista *v;
} THash;


void iniciaHash (THash *hash, int m);
int h (THash *hash, int chave);
TItem* pesquisa (THash *hash, int chave);
TCelula* pesquisaCelula (THash *hash, int chave);
int inserir (THash *hash, TItem x);
int remover (THash *hash, int chave);

void iniciaLista (TLista *lista);
int isVazia (TLista *lista);
int insereLista (TLista *lista, TItem x);
int removeLista (TLista *lista, TCelula *x);
int tamanhoLista (TLista *lista);
void histograma (THash *hash);


void iniciaHash (THash *hash, int m) {
	int i;
	hash->n = 0;
	hash->m = m;

	hash->v = (TLista*) malloc(sizeof(TLista) * m);

	for (i = 0; i < m; i++)
		iniciaLista (&hash->v[i]);
}

int h (THash *hash, int chave) {
	return chave % hash->m;
}

TItem* pesquisa (THash *hash, int chave) {
	TCelula *aux = pesquisaCelula (hash, chave);
	
	if (aux == NULL)
		return 0;
		
	return &(aux->item);
}

TCelula* pesquisaCelula (THash *hash, int chave) {
	int i = h (hash, chave);
	
	if ( isVazia (&hash->v[i]) )
		return NULL;
		
	TCelula *aux = hash->v[i].pPrimeiro;
	while (aux->pProx != NULL && chave != aux->item.chave)
		aux = aux->pProx;
		
	if (chave == aux->item.chave)
		return aux;
	else
		return NULL;
}

int inserir (THash *hash, TItem x) {
	if (pesquisaCelula (hash, x.chave) == NULL) {
		insereLista (&hash->v[h(hash, x.chave)], x);
		hash->n++;
		return 1;
	}
	return 0;
}

int remover (THash *hash, int chave) {
	TCelula *aux = pesquisaCelula (hash, chave);
	
	if (aux == NULL)
		return 0;
	
	removeLista (&hash->v[h(hash, chave)], aux);
	hash->n--;
	return 1;
}


void iniciaLista (TLista *lista) {
	lista->pPrimeiro = NULL;
	lista->pUltimo = NULL;
}

int isVazia (TLista *lista) {
	return lista->pPrimeiro == NULL;
}

int insereLista (TLista *lista, TItem x) {
	TCelula *novo = (TCelula *) malloc (sizeof (TCelula));
	novo->item = x;
	novo->pProx = NULL;
	
	if (isVazia (lista)) {
		lista->pPrimeiro = novo;
	} else {
		lista->pUltimo->pProx = novo;
	}
	lista->pUltimo = novo;
	
	return 1;
}

int removeLista (TLista *lista, TCelula *x) {
	TCelula *aux = lista->pPrimeiro;
	
	// Caso a lista tenha apenas 1 item
	if (aux->pProx == NULL) {
		if (aux == x) {
			free (aux);
			lista->pPrimeiro = NULL;
			lista->pUltimo = NULL;
		} else {
			return 0;
		}
	} else {
		// Caso tenha mais de 1 item, procurar a célula a ser removida
		while (aux != NULL && aux->pProx != x) {
			aux = aux->pProx;
		}
		
		// Verificando se a célula foi encontrada
		if (aux != NULL) {
			// Verificando se é a última célula
			if (aux->pProx == lista->pUltimo) {
				free (aux->pProx);
				aux->pProx = NULL;
				lista->pUltimo = NULL;
			} else {
				// Célula intermediária
				TCelula *aux2 = aux->pProx;
				aux->pProx = aux2->pProx;
				free (aux2);
			}
		} else {
			return 0;
		}
	}
	
	return 1;
}

int tamanhoLista (TLista *lista) {
	int tamanho = 0;
	
	TCelula *aux = lista->pPrimeiro;
	
	while (aux != NULL) {
		aux = aux->pProx;
		tamanho++;
	}
	
	return tamanho;
}

void histograma (THash *hash) {
	int i;
	for (i = 0; i < hash->m; i++) {
		printf ("%d\n", tamanhoLista(&hash->v[i]));
	}
}




int main (void)
{
	THash hash;
	iniciaHash (&hash, 97);

	// Inserindo
	int i;
	for (i = 0; i < 10000; i++) {
		TItem item;
		item.chave = rand() % 100000;
		inserir (&hash, item);
	}

	TItem item; 
	item.chave = 54109; inserir (&hash, item);
	item.chave = 100; inserir (&hash, item);
	
	remover (&hash, 54109);

	// Pesquisando
	TItem* p;
	p = pesquisa (&hash, 0);
	printf ("Procurando chave %d: %s\n", 0, p == NULL ? "não encontrada" : "encontrada");

	p = pesquisa (&hash, 54109);
	printf ("Procurando chave %d: %s\n", 54109, p == NULL ? "não encontrada" : "encontrada");

	p = pesquisa (&hash, 100);
	printf ("Procurando chave %d: %s\n", 100, p == NULL ? "não encontrada" : "encontrada");
	
	histograma (&hash);
}
