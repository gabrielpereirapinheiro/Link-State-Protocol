/*TRABALHO DE TELEINFORMATICA E REDES 2
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* ALUNO : VICTOR ARAUJO VIEIRA 
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JACIR BORDIM
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX - 10000000

typedef struct table
{
	int from;
	int link[2];
	int cost;
	int seq;
	int age;
	struct table *proximo;
}table;

typedef struct adj
{
	int id_adj;
	int flag_enviado;
	int cost;
	struct adj *proximo;
}adj;

typedef struct no
{
	int id;
	int *vetorDistancias; // vetor que vai conter o custo para chegar ao no correspondente ao indice
	char *nomeVertice;
	int flag_visitado;
	int **matrizAdjacencias;
	struct no *proximo;
	adj *proximo_adj;
	table *proximo_table;
}No;

typedef struct grafo
{
	int V; /*numero de vertices no grafo*/
    No *cabeca;

}Grafo;

Grafo * cria_grafo();

void GeraGrafoNFSNET(Grafo *G);

void adiciona_no(Grafo *ptr, int ID, char *nomeNo);

void adiciona_vizinho(Grafo *ptr,int vizinho,int cost,int from);

No * retorna_ponteiro_no(Grafo *ptr,int id);

void adiciona_table(Grafo *ptr,int no, int from, int link_1,int link_2,int cost, int seq,int age);

void ve_table(Grafo *ptr,int no);

void envia_msg(Grafo *ptr, int no,int from,int link_1,int link_2,int cost,int seq,int age);

void manda_msg(Grafo *ptr,int no);

void flooding(Grafo *ptr,int no,int from,int link_1,int link_2, int cost , int seq ,int age);

int confere_table(Grafo *ptr,int no,int link_1,int link_2);

void muda_visitado(Grafo *ptr,int no);

int status_vistiado(Grafo *ptr,int no);

void lsa_min(Grafo *ptr,int no);

void lsa_max(Grafo *ptr);

void AlocaVetorDistancias(Grafo *G);

void GeraGrafoNFSNET(Grafo *G);

void GeraMatrizAdjacencias(Grafo *g);

void LiberaGrafo(Grafo *G);

void dijkstra(int n, int node, int **matrizAdjacencias, No *vertice);

void reverte_visitado(Grafo *ptr);

void mostra_tables(Grafo *ptr);

int retorna_seq(Grafo *ptr,int no,int link_1,int link_2);

void atualiza_table(Grafo *ptr,int no,int link_1,int link_2,int seq,int cost);

char *RetornaNomeVertice(Grafo *G, int id);

void ExecutaLSAeCriaArquivos();
