#include "biblioteca.h"
void preenche_matriz(int G[][10])
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			G[i][j]=-1;
		}
		printf("\n");
	}

}

void completa_com_valor(int G[][10], Grafo *ptr,int no)
{
	No *ponteiro = NULL;
	table *ponteiro_aux = NULL;
	
	ponteiro = retorna_ponteiro_no(ptr,no)	;



}

int main()
{
	Grafo *grafo = NULL;
	No *ponteiro = NULL;
	adj *ponteiro_aux = NULL;
	int G[10][10];

	grafo = cria_grafo();

	adiciona_no(grafo,1);

	adiciona_no(grafo,2);
	
	adiciona_no(grafo,3);

	adiciona_no(grafo,4);

	adiciona_no(grafo,5);

	adiciona_no(grafo,6);

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

	adiciona_vizinho(grafo,5,12,6);
	//manda_msg(grafo,2);
	//manda_msg(grafo,3);


	//flooding(grafo,2,2,2,1,10,1,1);

	lsa_max(grafo);

	//envia_msg(grafo,2,2,2,1,1,1,1);
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

	LiberaGrafo(grafo);

	//preenche_matriz(G);

	//completa_com_valor(G,grafo,1);

	return 0;
}