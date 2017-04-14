/*TRABALHO DE TELEINFORMATICA E REDES 2
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* ALUNO : VICTOR ARAUJO VIEIRA
* MATRICULA: 14/0020764
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JACIR BORDIN
*
*/


#include "biblioteca.h"
/*Funcao Cria_grafo
* Funcao que ira criar a struct_grafo e cria uma
* struct no e aponta para ela.
*/
struct struct_grafo * cria_grafo()
{
	struct no *novo_no;

	struct struct_grafo *grafo;

	grafo = (struct struct_grafo *)malloc(sizeof(struct struct_grafo));

	novo_no = (struct no *)malloc(sizeof(struct no));

	novo_no->id = -1;

	novo_no->proximo = NULL;

	novo_no->proximo_table= NULL;

	grafo->cabeca = novo_no;/*cabeca ira apontar para o primeiro no*/

	return grafo;

}
/* Funcao adiciona_no ira criar um novo no
* e inseri-lo no fim da lista de nos , a cabeca
* da struct grafo ira apontar para a primeira.
*/
void adiciona_no(struct struct_grafo *ptr,int ID)
{
	struct no *ponteiro = NULL;
	struct no *novo_no;
	struct no *ponteiro_aux ;

	ponteiro = ptr->cabeca;

	while(ponteiro->id!=-1 && ponteiro->proximo!=NULL)
	{	
		ponteiro = ponteiro->proximo;
	}

	ponteiro->id = ID;

	ponteiro->flag_visitado = -1;

	ponteiro->proximo_adj = NULL;

	novo_no = (struct no *)malloc(sizeof(struct no));

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
void adiciona_vizinho(struct struct_grafo *ptr,int vizinho,int cost,int from)
{
	struct no * ponteiro;
	struct adj *ponteiro_adj;
	struct adj *ponteiro_aux;
	struct adj *ponteiro_aux2;

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
			ponteiro_aux = (struct adj*)malloc(sizeof(struct adj));

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

			ponteiro_aux = (struct adj*)malloc(sizeof(struct adj));

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
struct no * retorna_ponteiro_no(struct struct_grafo *ptr,int id)
{
	struct no *ponteiro;

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
void adiciona_table(struct struct_grafo *ptr,int no ,int from, int link_1,int link_2,int cost, int seq,int age)
{

	struct no *ponteiro; /*PONTEIRO PARA MANIPULAR UM NO*/
	struct table *ponteiro_table; /*PONTEIRO PARA MANIPULAR UMA TABLE*/
	struct table *ponteiro_aux_table;
	struct table *ponteiro_aux_table_2;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro_table = ponteiro->proximo_table;

	if(ponteiro_table == NULL)
	{
		
		ponteiro_aux_table = (struct table*)malloc(sizeof(struct table));

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

			ponteiro_aux_table = (struct table*)malloc(sizeof(struct table));

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
void ve_table(struct struct_grafo *ptr,int no)
{
	struct no *ponteiro;
	struct table *ponteiro_table;

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
void envia_msg(struct struct_grafo *ptr, int no,int from,int link_1,int link_2,int cost,int seq,int age)
{
	struct no *ponteiro;
	struct adj *ponteiro_adj;
	struct adj *ponteiro_aux;
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
void manda_msg(struct struct_grafo *ptr,int no)
{

	struct no *ponteiro;
	struct adj *ponteiro_adj;
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

void flooding(struct struct_grafo *ptr,int no,int from,int link_1,int link_2, int cost , int seq,int age)
{

	struct lista *ponteiro_lista;
	struct lista *ponteiro_lista_aux;

	struct no *ponteiro;
	struct adj *ponteiro_adj;

	struct no *ponteiro_aux;
	struct adj *ponteiro_aux_adj;

	int i;
	int numero_max = 10;
	int vetor[numero_max];/*Proxima rota*/

	for (int i = 0; i < numero_max ; ++i)
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

			int adiciona = 0;
			int no_atual = ponteiro_aux_adj->id_adj;
			int valor ;

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
}

int confere_table(struct struct_grafo *ptr,int no,int link_1,int link_2)
{
	int var_bool=0;
	struct no *ponteiro;
	struct table *ponteiro_table;

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

void muda_visitado(struct struct_grafo *ptr,int no)
{
	struct no *ponteiro;

	ponteiro = retorna_ponteiro_no(ptr,no);

	ponteiro-> flag_visitado = 1;

	printf(" visitado %d e a flag e %d \n",ponteiro->id,ponteiro->flag_visitado );

}
/*Funcao status_vistado
*
*
*/
int status_vistiado(struct struct_grafo *ptr,int no)
{
	int valor_retornado;

	struct no *ponteiro;

	ponteiro = retorna_ponteiro_no(ptr,no);

	valor_retornado = ponteiro->flag_visitado;

	return valor_retornado;
}


void lsa_min(struct struct_grafo *ptr,int no)
{
	struct no *ponteiro;
	struct adj *ponteiro_adj;

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

void lsa_max(struct struct_grafo *ptr)
{
	struct no *ponteiro;

	/*
	* Por DEFAULT colocaremos o inicial do LSA 
	* como o primeiro nó do grafo, isto é, o no
	* 1.
	*
	*/

	ponteiro = retorna_ponteiro_no(ptr,1);

	while(ponteiro!=NULL && ponteiro->id !=-1)
	{
		lsa_min(ptr,ponteiro->id);
		ponteiro = ponteiro->proximo;
	}	
}