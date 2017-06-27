/*TRABALHO DE TELEINFORMATICA E REDES 2
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* ALUNO : VICTOR ARAUJO VIEIRA
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JACIR BORDIM
*
*/


#include "biblioteca.h"

/*
* Funcao Cria_grafo
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

	novo_no->nomeVertice = NULL;

	novo_no->vetorDistancias = NULL;

	grafo->cabeca = novo_no;/*cabeca ira apontar para o primeiro no*/
	grafo->V = 0; /*inicializa o numero de vertices como 0*/

	return grafo;

}
/* Funcao adiciona_no ira criar um novo no
* e inseri-lo no fim da lista de nos , a cabeca
* da struct grafo ira apontar para a primeira.
*/
void adiciona_no(Grafo *ptr, int ID, char *nomeNo)
{
	int tamNomeVertice = 0;
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

	tamNomeVertice = strlen(nomeNo) + 1;
	ponteiro->nomeVertice = (char*)malloc(tamNomeVertice*sizeof(char));
	if(ponteiro->nomeVertice == NULL){
		printf("Nao foi possivel alocar a string do nome do vertice!\n");
		exit(1);
	}

	strcpy(ponteiro->nomeVertice, nomeNo); //copia o nome passado como parametro para o campo do No correspondente ao nome do vertice

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

		ponteiro_aux_table-> seq = seq;

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

			ponteiro_aux_table-> seq = seq;

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
		printf("\n FROM -> %d\n LINK -> %d \n LINK -> %d \n COST -> %d\n ",ponteiro_table->from,ponteiro_table->link[0],ponteiro_table->link[1],ponteiro_table->cost);
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
	int seq_compara;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_adj = ponteiro->proximo_adj;

	while(ponteiro_adj!=NULL)
	{
		novo_no = ponteiro_adj->id_adj;

		var_bool = confere_table(ptr,novo_no,link_1,link_2);

		if (var_bool==0) /*caso nao tenha ainda o dado na tabela desse no*/
		{
			//printf("Ira adicionar table em %d \n",novo_no );
			
			adiciona_table(ptr,novo_no,no,link_1,link_2,cost,seq,age);

		}
		else /*Caso ja esteja na tabela, confere o seq .*/
		{
			seq_compara= retorna_seq(ptr,novo_no,link_1,link_2);
			
			if( seq_compara > seq  )
			{
		
				atualiza_table(ptr,novo_no,link_1,link_2,age,cost);
			}

		}
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

			seq ++ ;

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
				last++; /*PAARA O PROXIMO A SER INSERIDO*/
			}

			ponteiro_aux_adj = ponteiro_aux_adj->proximo;
		}

		i++;
	}	

	reverte_visitado(ptr);

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


int retorna_seq(Grafo *ptr,int no,int link_1,int link_2)
{
	int var_seq=-1;
	No *ponteiro = NULL;
	table *ponteiro_table = NULL;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_table= ponteiro->proximo_table;

	while(ponteiro_table!=NULL)
	{
		if(ponteiro_table->link[0] == link_1 && ponteiro_table->link[1]==link_2)
		{
			var_seq = ponteiro_table->seq;
			break;
		}

		ponteiro_table = ponteiro_table->proximo;
	}


	return var_seq;
}

void atualiza_table(Grafo *ptr,int no,int link_1,int link_2,int seq,int cost)
{
	No *ponteiro = NULL;
	table *ponteiro_table = NULL;	

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_table = ponteiro->proximo_table;

	while(ponteiro_table)
	{
		if(ponteiro_table->link[0] == link_1 && ponteiro_table->link[1]==link_2)
		{
			ponteiro_table->cost = cost;
			ponteiro_table->seq = seq;
			break;
		}

		ponteiro_table = ponteiro_table->proximo;
	}
}

void muda_visitado(Grafo *ptr,int no)
{
	No *ponteiro = NULL;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro-> flag_visitado = 1;

	//printf(" visitado %d e a flag e %d \n",ponteiro->id,ponteiro->flag_visitado );

}

void reverte_visitado(Grafo *ptr)
{
	No *ponteiro = NULL;

	ponteiro = ptr -> cabeca;

	while (ponteiro!=NULL)
	{
		ponteiro->flag_visitado = -1;

		ponteiro = ponteiro->proximo;
	}

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

	int from,cost,link_1,link_2,age,seq=1;

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
	* 0.
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
				free(verticePtr->nomeVertice);
				free(verticePtr->vetorDistancias);
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

/*Funcao que vai alocar o vertorDistancias de cada vertice do grafo*/
void AlocaVetorDistancias(Grafo *G){
	No *verticePtr = NULL;

	for(verticePtr = G->cabeca; verticePtr != NULL; verticePtr = verticePtr->proximo){
		verticePtr->vetorDistancias = (int*)malloc((G->V)*sizeof(int)); // cada vetor distancias tem como tamano o numero de nos do grafo
		if(verticePtr->vetorDistancias == NULL){
			printf("Nao foi possivel alocar o vetorDistancias do vertice %s\n", verticePtr->nomeVertice);
			exit(1);
		}
	}
}

/*Funcao que vai criar a topologia da NFSNET*/
void GeraGrafoNFSNET(Grafo *G){

	adiciona_no(G,0, "WA"); //WA
	adiciona_no(G,1, "CA1"); //CA1
	adiciona_no(G,2, "CA2"); //CA2
	adiciona_no(G,3, "IL"); //IL
	adiciona_no(G,4, "UT"); //UT
	adiciona_no(G,5, "TX");  //TX
	adiciona_no(G,6, "NE"); //NE
	adiciona_no(G,7, "PA"); //PA
	adiciona_no(G,8, "MI"); //MI
	adiciona_no(G,9, "CO"); //CO
	adiciona_no(G,10, "GA"); //GA
	adiciona_no(G,11, "DC"); //DC
	adiciona_no(G,12, "NY"); //NY
	adiciona_no(G,13, "NJ"); //NJ

	//Vizinhos de 0
	adiciona_vizinho(G,1,3,0);
	adiciona_vizinho(G,2,5,0);
	adiciona_vizinho(G,3,1,0);

	//vizinhos de 1
	adiciona_vizinho(G,0,3,1);
	adiciona_vizinho(G,2,2,1);
	adiciona_vizinho(G,4,4,1);

	//Vizinhos de 2
	adiciona_vizinho(G,0,5,2);
	adiciona_vizinho(G,1,2,2);
	adiciona_vizinho(G,5,1,2);


	// Vizinhos de 3
	adiciona_vizinho(G,0,1,3);
	adiciona_vizinho(G,6,2,3);
	adiciona_vizinho(G,7,4,3);

	// Vizinhos 4
	adiciona_vizinho(G,1,4,4);
	adiciona_vizinho(G,11,5,4);

	//Vizinhos 5
	adiciona_vizinho(G,2,1,5);
	adiciona_vizinho(G,8,5,5);
	adiciona_vizinho(G,9,10,5);
	adiciona_vizinho(G,10,15,5);

	//vizinhos 6
	adiciona_vizinho(G,3,2,6);
	adiciona_vizinho(G,8,3,6);

	// vizinhos 7
	adiciona_vizinho(G,3,4,7);
	adiciona_vizinho(G,12,1,7);
	adiciona_vizinho(G,13,2,7);
	adiciona_vizinho(G,9,6,7);

	//vizinhos 8
	adiciona_vizinho(G,5,5,8);
	adiciona_vizinho(G,6,3,8);

	// vizinhos 9
	adiciona_vizinho(G,5,10,9);
	adiciona_vizinho(G,7,6,9);

	// vizinhos 10
	adiciona_vizinho(G,5,15,10);
	adiciona_vizinho(G,12,2,10);
	adiciona_vizinho(G,13,3,10);

	// vizinhos 11
	adiciona_vizinho(G,4,5,11);
	adiciona_vizinho(G,12,1,11);
	adiciona_vizinho(G,13,2,11);

	//vizinhos 12
	adiciona_vizinho(G,7,1,12);
	adiciona_vizinho(G,10,2,12);
	adiciona_vizinho(G,11,1,12);

	// vizinhos 13
	adiciona_vizinho(G,7,2,13);
	adiciona_vizinho(G,10,3,13);
	adiciona_vizinho(G,11,2,13);

	AlocaVetorDistancias(G);
}

void dijkstra(int n, int node, int **matrizAdjacencias, No *vertice)
{
	int cycles;
	int *fixo = NULL; 

	fixo = (int*)malloc(n*sizeof(int));
	if(fixo == NULL){
		printf("Nao foi possivel alocar o vetor fixo na funcao Dijkstra!\n");
		exit(1);
	}

	for (int i = 0; i <  n; ++i)/*ALl distances will be iguality to INFINITY and all fixos to know what 
	you stay will be 0*/
	{
		fixo[i]=0;
		vertice->vetorDistancias[i]=INF;
	}

	vertice->vetorDistancias[node]=0; /*Define what node will be the reference*/

	/*Executed n times ( n = number of nodes )*/
	for(cycles = n ; cycles > 0 ; cycles -- )
	{
		int no = -1;

		for (int i = 0; i < n; ++i) 
		{
			if(!fixo[i] && (no==-1 || vertice->vetorDistancias[i] < vertice->vetorDistancias[no]))
			{
				//printf("!fixo[%d]= %d && %d = -1 || dist[%d]= %d < dis[%d] = %d  \n", i,fixo[i],no,i,dist[i],no,dist[no] );
				no=i;	
			}
		}
	
		fixo[no] = 1;

		if(vertice->vetorDistancias[no] == INF)
		{	
			/*If the distance is infinity, go out loop*/
			break;
		}
	
		for (int i = 0; i < n; ++i)
		{
			if(matrizAdjacencias[no][i] && vertice->vetorDistancias[i] > vertice->vetorDistancias[no] + matrizAdjacencias[no][i])
			{	
				/*If the distance to this node is bigger than that some, change the value and save*/
				vertice->vetorDistancias[i] = vertice->vetorDistancias[no] + matrizAdjacencias[no][i];
				
			}
		}
	}

	free(fixo);
}

/*
* Funcao mostra_Tables e para mostrar as tabelas de todos os nos
* comecando do primeiro que foi inserido na lista de nos ate o ultimo.
*
*/
void mostra_tables(Grafo *ptr)
{

	No *ponteiro = NULL;

	ponteiro = ptr -> cabeca ;

	/*Laco para pecorrer toda a lista de nos*/
	while(ponteiro != NULL)
	{
		printf("\n***** TABLES DO NO %d *******\n",ponteiro->id );
		ve_table(ptr,ponteiro->id);
		ponteiro = ponteiro -> proximo;
	}
}

/*Funcao que retorna o nome do no pelo id passado*/
char *RetornaNomeVertice(Grafo *G, int id){
	No *vertPtr = NULL;

	for(vertPtr = G->cabeca; vertPtr != NULL; vertPtr = vertPtr->proximo){
		if(id == vertPtr->id){
			return vertPtr->nomeVertice;
		}
	}

	return NULL;
}

/*Funcao que vai criar o grafo, executar o LSA, executar o dijstra quando todas as tabelas estiverem convergidas
e criar um arquivo txt que mostrara as tabelas e informacoes de cada no*/
void ExecutaLSAeCriaArquivos(){
	Grafo *grafo = NULL;
	No *verticePtr = NULL;
	table *tabPtr = NULL;
	FILE *fp = fopen("estatisticas.txt", "w");

	grafo = cria_grafo();
	GeraGrafoNFSNET(grafo); // vai gerar o grafo com a topologia do NFSNET
	lsa_max(grafo); // vai executar o LSA
	GeraMatrizAdjacencias(grafo); // vai criar a matriz de adjacencia de cada vertice do grafo

	// loop que vai calcular o dijkstra de cada vertice
	for(verticePtr = grafo->cabeca; verticePtr != NULL; verticePtr = verticePtr->proximo){
		dijkstra(grafo->V, verticePtr->id, verticePtr->matrizAdjacencias, verticePtr);
	}

	printf("Arquivo estatisticas.txt vai ser gerado\n\n");
	//loop que vai escrever no arquivo a partir de cada vertice, as estatisticas, como a tabela
	//e o vetorDistancias
	for(verticePtr = grafo->cabeca; verticePtr != NULL; verticePtr = verticePtr->proximo){
		if(verticePtr->id != -1){
			printf("Escrevendo no arquivo o vertice %s\n", verticePtr->nomeVertice);
			fprintf(fp, "Nome do vertice: %s, ID do vertice: %d\n\n", verticePtr->nomeVertice, verticePtr->id);
			// informacoes da tabela
			fprintf(fp, "Banco de dados de caminhos do vertice\n");
			if(verticePtr->proximo_table){
				for(tabPtr = verticePtr->proximo_table; tabPtr != NULL; tabPtr = tabPtr->proximo){
					fprintf(fp, "Vertice de origem: %s, ID Vertice origem: %d, Aresta: %s->%s, Custo: %d, Numero de sequencia: %d\n", 
						    RetornaNomeVertice(grafo, tabPtr->from), tabPtr->from, RetornaNomeVertice(grafo, tabPtr->link[0]),
						    RetornaNomeVertice(grafo, tabPtr->link[1]), tabPtr->cost, tabPtr->seq);
				}
			}
			fprintf(fp, "\n");
			fprintf(fp, "Vetor de distancias do vertice\n");
			// vetor de distancias
			if(verticePtr->vetorDistancias){
				for(int i = 0; i < grafo->V; i++){
					if(i != verticePtr->id){
						fprintf(fp, "Vertice destino: %s, Custo: %d\n", RetornaNomeVertice(grafo, i), verticePtr->vetorDistancias[i]);
					}
				}
			}
			fprintf(fp, "\n");
			fprintf(fp, "-----------------------------------------------------------------------------------------\n\n");
		}
	}

	printf("\nArquivo estatisticas.txt gerado com sucesso!\n");

	LiberaGrafo(grafo);
	fclose(fp);
}
