#include <stdio.h>

#define INICIO 0

void iniciarLista (TLista *pLista) {

int remover (TLista *pLista, int p, TItem *pX) {
	printf ("Itens na lista:\n");

int main() {
	TLista lista;
	iniciarLista (&lista);

	printf("Vazia: %s\n", isVazia(&lista) == 1 ? "SIM":"NAO");

	TItem item1, item2;
	item1.chave = 10;
	inserir (&lista, item1);
	item2.chave = -5;
	inserir (&lista, item2);
	imprimir (&lista);

	printf("Vazia: %s\n", isVazia(&lista) == 1 ? "SIM":"NAO");

	TItem itemRemovido;
	remover (&lista, 1, &itemRemovido);
	printf("Item removido: %d\n", itemRemovido.chave);
	imprimir (&lista);
}