/*
* TRABALHO DE TELEINFORMATICA E REDES 2
*
* ALUNO : GABRIEL PEREIRA PINHEIRO - 14/0020764
* ALUNO : VICTOR ARAUJO VIEIRA - 14/0032801
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JACIR BORDIM
*
*/

#include "biblioteca.h"


int main()
{
	Grafo *grafo = NULL;
	No *ponteiro = NULL;
	adj *ponteiro_aux = NULL;

	grafo = cria_grafo();

	GeraGrafoNFSNET(grafo);

	lsa_max(grafo);

	//mostra_tables(grafo);

	GeraMatrizAdjacencias(grafo);

	ponteiro = grafo->cabeca;
	ponteiro = ponteiro->proximo;
	for(int i = 0; i < grafo->V; i++){
		for(int j = 0; j < grafo->V; j++){
			printf("matriz[%d][%d] = %d\n", i, j, ponteiro->matrizAdjacencias[i][j]);
		}
	}

	dijkstra(grafo->V, 0, ponteiro->matrizAdjacencias);

	printf("\n");
	for(int i = 0; i < grafo->V; i++){
		printf("distancia[%d] = %d\n", i, dist[i]);
	}

	printf("\n%d\n", grafo->V);

	LiberaGrafo(grafo);

	//completa_com_valor(G,grafo,1);

	return 0;
}