#include "biblioteca.h"


int main()
{
	Grafo *grafo = NULL;
	No *ponteiro = NULL;
	adj *ponteiro_aux = NULL;

	grafo = cria_grafo();
	GeraGrafoNFSNET(grafo);
	/*adiciona_no(grafo,0);

	adiciona_no(grafo,1);

	adiciona_no(grafo,2);
	
	adiciona_no(grafo,3);

	adiciona_no(grafo,4);

	adiciona_no(grafo,5);

	adiciona_no(grafo,6);

	adiciona_vizinho(grafo,1,15,0);

	adiciona_vizinho(grafo,0,15,1);

	adiciona_vizinho(grafo,2,1,1);

	adiciona_vizinho(grafo,3,2,1);

	adiciona_vizinho(grafo,1,1,2);

	adiciona_vizinho(grafo,3,6,2);

	adiciona_vizinho(grafo,4,5,2);

	adiciona_vizinho(grafo,1,2,3);

	adiciona_vizinho(grafo,2,6,3);

	adiciona_vizinho(grafo,5,7,3);

	adiciona_vizinho(grafo,2,5,4);

	adiciona_vizinho(grafo,5,10,4);

	adiciona_vizinho(grafo,6,11,4);

	adiciona_vizinho(grafo,3,7,5);

	adiciona_vizinho(grafo,4,10,5);

	adiciona_vizinho(grafo,6,12,5);

	adiciona_vizinho(grafo,4,11,6);

	adiciona_vizinho(grafo,5,12,6);*/
	//manda_msg(grafo,2);
	//manda_msg(grafo,3);


	//flooding(grafo,2,2,2,1,10,1,1);

	lsa_max(grafo);

	//envia_msg(grafo,2,2,2,1,1,1,1);

	printf("\n\n******NO 0******\n\n");
	ve_table(grafo,0);

	printf("\n\n******NO 1******\n\n");
	ve_table(grafo,1);

	printf("\n\n******NO 2******\n\n");
	ve_table(grafo,2);



	printf("\n\n******NO 3******\n\n");
	ve_table(grafo,3);


	printf("\n\n******NO 4******\n\n");
	ve_table(grafo,4);


	printf("\n\n******NO 5******\n\n");

	ve_table(grafo,5);

	printf("\n\n******NO 6******\n\n");
	ve_table(grafo,6);

	GeraMatrizAdjacencias(grafo);

	ponteiro = grafo->cabeca;
	ponteiro = ponteiro->proximo;
	for(int i = 0; i < grafo->V; i++){
		for(int j = 0; j < grafo->V; j++){
			printf("matriz[%d][%d] = %d\n", i, j, ponteiro->matrizAdjacencias[i][j]);
		}
	}

	dijkstra(grafo->V, 0, 12, ponteiro->matrizAdjacencias);

	printf("\n");
	for(int i = 0; i < grafo->V; i++){
		printf("distancia[%d] = %d\n", i, dist[i]);
	}

	printf("\n%d\n", grafo->V);

	LiberaGrafo(grafo);

	//completa_com_valor(G,grafo,1);

	return 0;
}