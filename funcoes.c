/*TRABALHO DE TELEINFORMATICA E REDES 2
*
* ALUNO : GABRIEL PEREIRA PINHEIRO - 14/0020764
* ALUNO : VICTOR ARAUJO VIEIRA - 14/0032801
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JACIR BORDIM
*
*/
#include "biblioteca.h"

/*Funcao Cria_grafo
* Funcao que ira criar a Grafo e cria uma
* struct no e aponta para ela.
*/
Grafo * cria_grafo()
{
	No *novo_no = NULL;

	Grafo *grafo = NULL;

	grafo = (Grafo *)malloc(sizeof(Grafo));

	novo_no = (No *)malloc(sizeof(No));

	novo_no->id = -1;

	novo_no->proximo = NULL;

	novo_no->proximo_table= NULL;

	grafo->cabeca = novo_no;/*cabeca ira apontar para o primeiro no*/
	grafo->V = 0; /*inicializa o numero de vertices como 0*/

	return grafo;

}
/* Funcao adiciona_no ira criar um novo no
* e inseri-lo no fim da lista de nos , a cabeca
* da struct grafo ira apontar para a primeira.
*/
void adiciona_no(Grafo *ptr, int ID)
{
	No *ponteiro = NULL;
	No *novo_no = NULL;
	No *ponteiro_aux = NULL;

	ponteiro = ptr->cabeca;
	ptr->V++; /*incrementa o numero de vertices no grafo*/

	while(ponteiro->id!=-1 && ponteiro->proximo!=NULL)
	{	
		ponteiro = ponteiro->proximo;
	}

	ponteiro->id = ID;

	ponteiro->flag_visitado = -1;

	ponteiro->proximo_adj = NULL;

	novo_no = (No *)malloc(sizeof(No));

	ponteiro->proximo = novo_no;

	novo_no->id = -1;

	novo_no->flag_visitado = -1;

	novo_no->proximo = NULL;

	novo_no->proximo_adj = NULL;

	novo_no->proximo_table= NULL;
}

/* Funcao adciona_vizinho ira criar no no (FROM) um vizinho com o ID vizinho
* que tem como custo o link from->vizinho o custo COST*
*/
void adiciona_vizinho(Grafo *ptr,int vizinho,int cost,int from)
{
	No *ponteiro;
	adj *ponteiro_adj;
	adj *ponteiro_aux;
	adj *ponteiro_aux2;

	ponteiro = ptr->cabeca;

	while(ponteiro->id!=from && ponteiro->proximo!=NULL)
	{
		ponteiro = ponteiro -> proximo;

	}

	if(ponteiro->id == from)
	{
		//printf("encontrou o %d \n",ponteiro->id);
		ponteiro_adj = ponteiro ->proximo_adj;
		
		if(ponteiro_adj == NULL)
		{
			ponteiro_aux = (adj*)malloc(sizeof(adj));

			ponteiro->proximo_adj= ponteiro_aux;

			ponteiro_aux->id_adj = vizinho;

			ponteiro_aux->cost = cost;

			ponteiro_aux->flag_enviado = -1;

			ponteiro_aux->proximo=NULL;
		}
		else
		{
			while(ponteiro_adj = NULL)
			{
				ponteiro_aux = ponteiro_adj;
				ponteiro_adj = ponteiro_adj->proximo;
			}
			//printf("d\n");

			ponteiro_aux2 = ponteiro_aux;

			ponteiro_aux = (adj*)malloc(sizeof(adj));

			ponteiro_aux2->proximo = ponteiro_aux;

			ponteiro_aux->id_adj = vizinho;

			ponteiro_aux->cost = cost;

			ponteiro_aux->flag_enviado = -1;

			ponteiro_aux->proximo=NULL;
		}
	}
}
/* Funcao retorna_ponteiro_no ira retornar o ponteiro do no
* que for pedido no parametro ID
*/
No * retorna_ponteiro_no(Grafo *ptr,int id)
{
	No *ponteiro = NULL;

	ponteiro = ptr->cabeca;

	while(ponteiro->id!=id)
	{
		ponteiro = ponteiro->proximo;
	}

	return ponteiro ;
}
/*
* Funcao que adiciona_table ira criar uma table no NO  
* que foi especificado
*
*/
void adiciona_table(Grafo *ptr,int no ,int from, int link_1,int link_2,int cost, int seq,int age)
{

	No *ponteiro = NULL; /*PONTEIRO PARA MANIPULAR UM NO*/
	table *ponteiro_table = NULL; /*PONTEIRO PARA MANIPULAR UMA TABLE*/
	table *ponteiro_aux_table = NULL;
	table *ponteiro_aux_table_2 = NULL;

	ponteiro = retorna_ponteiro_no(ptr, no);

	ponteiro_table = ponteiro->proximo_table;

	if(ponteiro_table == NULL)
	{
		
		ponteiro_aux_table = (table*)malloc(sizeof(table));

		ponteiro_aux_table -> from = from;

		ponteiro_aux_table-> link[0] = link_1;

		ponteiro_aux_table-> link[1] = link_2;


		ponteiro_aux_table-> cost = cost;

		ponteiro->proximo_table = ponteiro_aux_table;

		ponteiro_aux_table -> proximo = NULL;

	}
	else
	{
		while(ponteiro_table!=NULL)
		{
			ponteiro_aux_table = ponteiro_table;
			ponteiro_table = ponteiro_table->proximo;
		}
		
			ponteiro_aux_table_2 = ponteiro_aux_table;

			ponteiro_aux_table = (table*)malloc(sizeof(table));

			ponteiro_aux_table_2 ->proximo = ponteiro_aux_table;

			ponteiro_aux_table-> from = from;

			ponteiro_aux_table-> link[0] = link_1;

			ponteiro_aux_table-> link[1] = link_2;


			ponteiro_aux_table-> cost = cost;

			ponteiro_aux_table->proximo=NULL;
	}
}
/*
* Funcao ve_table mostra todas as tables do nó que for passado como parametro
*
*/
void ve_table(Grafo *ptr,int no)
{
	No *ponteiro = NULL;
	table *ponteiro_table = NULL;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_table = ponteiro->proximo_table;

	while(ponteiro_table!=NULL)
	{
		printf("\nFROM -> %d\n LINK -> %d \n LINK -> %d \n COST -> %d\n",ponteiro_table->from,ponteiro_table->link[0],ponteiro_table->link[1],ponteiro_table->cost);
		ponteiro_table = ponteiro_table-> proximo;
	}
}

/*
* Funcao envia_msg ira enviar a mensagem recebida como parametro para todos os vizinhos
* do no recebido tambem como parametro
*/
void envia_msg(Grafo *ptr, int no,int from,int link_1,int link_2,int cost,int seq,int age)
{
	No *ponteiro = NULL;
	adj *ponteiro_adj = NULL;
	adj *ponteiro_aux = NULL;
	int novo_no;
	int var_bool;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_adj = ponteiro->proximo_adj;

	while(ponteiro_adj!=NULL)
	{
		novo_no = ponteiro_adj->id_adj;

		var_bool = confere_table(ptr,novo_no,link_1,link_2);

		/*

		F A Z E R   A Q U I   A  F U N C A O   Q U E    C O M P A R A
		O    M E N OR     S E Q  .




		*/
		if (var_bool==0) /*caso nao tenha ainda o dado na tabela desse no*/
		{
			printf("Ira adicionar table em %d \n",novo_no );
			
			adiciona_table(ptr,novo_no,no,link_1,link_2,cost,seq,age);

		}
		else /*Caso nao for vizinho , nao faz nada*/
		{
			printf("Repetido !! Em %d ja tem %d com %d \n",novo_no,link_1,link_2);
		}
		ponteiro_adj = ponteiro_adj -> proximo;
	}
}
/*
* Funcao que envia mensagem dos custos atuais para os demais
* NAO ESTA SENDO USADA ! 
*/
void manda_msg(Grafo *ptr,int no)
{

	No *ponteiro = NULL;
	adj *ponteiro_adj = NULL;
	int from,link_1,link_2,cost,seq,age;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_adj = ponteiro->proximo_adj;

	while(ponteiro_adj!=NULL)
	{
		from = no;

		link_1 = no ;

		link_2 = ponteiro_adj-> id_adj;

		cost = ponteiro_adj -> cost;

		seq = 1;

		age = 0;

		printf("**VAI ENVIAR PARA OS VIZINHOS DE %d que %d ate %d custa %d\n",no,link_1,link_2,cost );

		envia_msg(ptr,no,from,link_1,link_2,cost,seq,age);

		ponteiro_adj = ponteiro_adj -> proximo;
	}
}

void flooding(Grafo *ptr,int no,int from,int link_1,int link_2, int cost , int seq,int age)
{

	No *ponteiro = NULL;
	adj *ponteiro_adj = NULL;

	No *ponteiro_aux = NULL;
	adj *ponteiro_aux_adj = NULL;

	int i;
	int numero_max = ptr->V;
	int *vetor = NULL;/*Proxima rota*/
	int valor = 0, adiciona = 0;

	vetor = (int*)malloc((ptr->V)*sizeof(int));
	if(vetor == NULL){
		printf("Nao foi possivel alocar o vetor que determina o caminho do lsa!\n");
		exit(1);
	}

	for (i = 0; i < numero_max ; ++i)
	{
		vetor[i]=-1; /*Saber se nao foi usado*/
		//printf("em %d e %d\n",i,vetor[i] );
	}

	ponteiro = retorna_ponteiro_no(ptr,no);
	ponteiro_adj = ponteiro->proximo_adj;

	i =0;

	while(ponteiro_adj!=NULL)
	{
		vetor[i]= ponteiro_adj->id_adj;

		i++;
		//printf(" ** Adiciona no vetor %d em %d\n",vetor[i-1],i-1 );
		ponteiro_adj= ponteiro_adj->proximo;
	}

	int last = i;

	i=0;

	muda_visitado(ptr,no);

	adiciona_table(ptr,no,from,link_1,link_2,cost,seq,age);
	
	envia_msg(ptr,no,from,link_1,link_2,cost,seq,age);

	while(vetor[i]!=-1)
	{
		ponteiro_aux = retorna_ponteiro_no(ptr,vetor[i]);

		ponteiro_aux_adj = ponteiro_aux->proximo_adj;

		muda_visitado(ptr,vetor[i]);

		while(ponteiro_aux_adj!=NULL)
		{
			//printf("o vizinho de %d e %d \n",vetor[i],ponteiro_aux_adj->id_adj );

			int no_atual = ponteiro_aux_adj->id_adj;
	
			valor = status_vistiado(ptr,no_atual);

			envia_msg(ptr,no_atual,from,link_1,link_2,cost,seq,age);

			for (int j = 0; j < numero_max ; ++j)
			{
					if(vetor[j] == ponteiro_aux_adj->id_adj)
					{
						adiciona++;
					}
			}

			if(adiciona==0 && valor==-1)/*SE AINDA NAO TIVER NO VETOR E NAO TIVER SIDO VISITADO ADD NO VETOR*/
			{
				vetor[last]= ponteiro_aux_adj->id_adj; /*ADICIONA NA ULTIMA POSICAO SALVA*/
				last++; /*PARA O PROXIMO A SER INSERIDO*/
			}

			ponteiro_aux_adj = ponteiro_aux_adj->proximo;
		}

		i++;
	}	

	free(vetor);
}

int confere_table(Grafo *ptr,int no,int link_1,int link_2)
{
	int var_bool=0;
	No *ponteiro = NULL;
	table *ponteiro_table = NULL;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_table= ponteiro->proximo_table;

	while(ponteiro_table!=NULL)
	{
		if(ponteiro_table->link[0] == link_1 && ponteiro_table->link[1]==link_2)
		{
			var_bool=1;
		}

		ponteiro_table = ponteiro_table->proximo;
	}


	return var_bool;
}

void muda_visitado(Grafo *ptr,int no)
{
	No *ponteiro = NULL;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro-> flag_visitado = 1;

	printf(" visitado %d e a flag e %d \n",ponteiro->id,ponteiro->flag_visitado );

}
/*Funcao status_vistado
*
*
*/
int status_vistiado(Grafo *ptr,int no)
{
	int valor_retornado;

	No *ponteiro = NULL;

	ponteiro = retorna_ponteiro_no(ptr,no);

	valor_retornado = ponteiro->flag_visitado;

	return valor_retornado;
}


void lsa_min(Grafo *ptr,int no)
{
	No *ponteiro = NULL;
	adj *ponteiro_adj = NULL;

	int from,cost,link_1,link_2,age,seq;

	ponteiro =  ptr->cabeca;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_adj = ponteiro->proximo_adj;


	while(ponteiro_adj!=NULL)
	{

		link_2 = ponteiro_adj->id_adj;
		cost = ponteiro_adj->cost;

		flooding(ptr,no,no,no,link_2,cost,seq,age);

		ponteiro_adj = ponteiro_adj -> proximo;
	}
}

void lsa_max(Grafo *ptr)
{
	No *ponteiro = NULL;

	/*
	* Por DEFAULT colocaremos o inicial do LSA 
	* como o primeiro nó do grafo, isto é, o no
	* 1.
	*
	*/

	ponteiro = retorna_ponteiro_no(ptr,0);

	while(ponteiro!=NULL && ponteiro->id !=-1)
	{
		lsa_min(ptr,ponteiro->id);
		ponteiro = ponteiro->proximo;
	}	
}

void LiberaGrafo(Grafo *G){
	No *verticePtr = NULL, *vertPtrAux = NULL; // ponteiro para vertices
	adj *adjPtr = NULL, *adjPtrAux = NULL; // ponteiro para adjacentes
	table *tablePtr = NULL, *tablePtrAux = NULL; // ponteiro para a tabela de banco de dados
	int i = 0;

	if(G){
		if(G->cabeca){
			verticePtr = G->cabeca;
			//vai percorrer todos os vertices do grafo
			while(verticePtr != NULL){
				//para todo vertice, vai verificar se existe lista de vizinhos e tabelas, e vai libera-los
				//libera os adjacentes
				if(verticePtr->proximo_adj){
					adjPtr = verticePtr->proximo_adj;
					while(adjPtr != NULL){
						adjPtrAux = adjPtr->proximo;
						free(adjPtr);
						adjPtr = adjPtrAux;
					}
				}
				//libera as tabelas de banco de dados
				if(verticePtr->proximo_table){
					tablePtr = verticePtr->proximo_table;
					while(tablePtr != NULL){
						tablePtrAux = tablePtr->proximo;
						free(tablePtr);
						tablePtr = tablePtrAux;
					}
				}
				if(verticePtr->matrizAdjacencias){
					for(i = 0; i < G->V; i++){
						free(verticePtr->matrizAdjacencias[i]);
					}
					free(verticePtr->matrizAdjacencias);
				}
				//agora vai liberar o no de fato
				vertPtrAux = verticePtr->proximo;
				free(verticePtr);
				verticePtr = vertPtrAux;
			}
		}
		free(G);
	}
}

/*Funcao que vai gerar a matriz de adjacencias de cada vertice*/
void GeraMatrizAdjacencias(Grafo *G){
	No *vertPtr = NULL; //ponteiro que percorrera a lista de vertices do grafo
	table *tabPtr = NULL; // ponteiro que percorrera a lista de tabelas do vertice
	int i = 0, j = 0;

	//coloca na matriz todos os links que estao na tabela de cada um dos nos
	for(vertPtr = G->cabeca; vertPtr != NULL; vertPtr = vertPtr->proximo){
		//parte que vai alocar a matriz de adjacencias
		vertPtr->matrizAdjacencias = (int**)malloc((G->V)*sizeof(int*));
		if(vertPtr->matrizAdjacencias == NULL){
			printf("Nao foi possivel alocar a matriz de adjacencias!\n");
			exit(1);
		}
		for(i = 0; i < G->V; i++){
			vertPtr->matrizAdjacencias[i] = (int*)malloc((G->V)*sizeof(int));
		}

		//inicia toda a matriz com infinitos (INT_MAX)
		for(i = 0; i < G->V; i++){
			for(j = 0; j < G->V; j++){
				if(i == j){
					vertPtr->matrizAdjacencias[i][j] = 0;
				}else{
					vertPtr->matrizAdjacencias[i][j] = INF;
				}				
			}
		}
		//parte que vai inserir os valores da tabela de fato na matriz
		if(vertPtr->proximo_table){
			for(tabPtr = vertPtr->proximo_table; tabPtr != NULL; tabPtr = tabPtr->proximo){
				vertPtr->matrizAdjacencias[tabPtr->link[0]][tabPtr->link[1]] = tabPtr->cost;
			}
		}
	}
	
}

