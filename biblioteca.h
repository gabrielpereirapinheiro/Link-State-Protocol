#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

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
	int flag_visitado;
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

void adiciona_no(Grafo *ptr,int ID);

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

void dijkstra(int n,int node,int toNode);

int **GeraMatrizAdjacencias(Grafo *g, int **matrizAdjacencias);

void LiberaMatriz(int **matrizAdjacencias);

void LiberaGrafo(Grafo *G);