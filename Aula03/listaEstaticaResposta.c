#include <stdio.h>

#define INICIO 0#define MAXTAM 500typedef struct {	int chave;} TItem;typedef struct {	TItem item[MAXTAM];	int primeiro, ultimo;} TLista;void iniciarLista (TLista *pLista);int isVazia (TLista *pLista);int inserir (TLista *pLista, TItem x);int remover (TLista *pLista, int p, TItem *pX);void imprimir (TLista *pLista);int get (TLista *pLista, int p, TItem *pX);int tamanho (TLista *pLista);

void iniciarLista (TLista *pLista) {	pLista->primeiro = INICIO;	pLista->ultimo = pLista->primeiro;}int isVazia (TLista *pLista) {	return pLista->ultimo == pLista->primeiro;}int inserir (TLista *pLista, TItem x) {	if(pLista->ultimo == MAXTAM )		return 0; // lista cheia	pLista->item[pLista->ultimo++] = x;	return 1;}

int remover (TLista *pLista, int p, TItem *pX) {	if( isVazia (pLista) || p >= pLista->ultimo )		return 0;	int cont;	*pX = pLista->item[p];	pLista->ultimo--;	for (cont = p+1; cont <= pLista->ultimo; cont++)		pLista->item[cont-1] = pLista->item[cont];	return 1;}void imprimir (TLista *pLista) {	int i;
	printf ("Itens na lista:\n");	for (i = pLista->primeiro; i < pLista->ultimo; i++)		printf ("%d\n", pLista->item[i].chave);}		int get (TLista *pLista, int p, TItem *pX) {	if( isVazia (pLista) || p >= pLista->ultimo )		return 0;			*pX = pLista->item[p];	return 1;}int tamanho (TLista *pLista) {	return pLista->ultimo;}

int main() {
	TLista lista;
	iniciarLista (&lista);
	printf("Tamanho: %d. ", tamanho(&lista));
	printf("Vazia: %s\n", isVazia(&lista) == 1 ? "SIM":"NAO");

	TItem item1, item2;
	item1.chave = 10;
	inserir (&lista, item1);
	item2.chave = -5;
	inserir (&lista, item2);
	imprimir (&lista);		TItem itemRetornado;	get (&lista, 1, &itemRetornado);	printf("Retorno: %d\n", itemRetornado.chave);
	printf("Tamanho: %d. ", tamanho(&lista));
	printf("Vazia: %s\n", isVazia(&lista) == 1 ? "SIM":"NAO");

	TItem itemRemovido;
	remover (&lista, 1, &itemRemovido);
	printf("Item removido: %d\n", itemRemovido.chave);
	imprimir (&lista);
}
