#include <stdio.h>
#include <stdlib.h>

struct struct_grafo
{
	struct no *cabeca;
};

struct no
{
	int id;
	int flag_visitado;
	struct no *proximo;
	struct adj *proximo_adj;
	struct table *proximo_table;
};

struct adj
{
	int id_adj;
	int flag_enviado;
	int cost;
	struct adj *proximo;
};


struct table
{
	int from;
	int link[2];
	int cost;
	int seq;
	int age;
	struct table *proximo;
};

struct lista
{
	int no;
	struct lista *proximo;
};

struct struct_grafo * cria_grafo();

void adiciona_no(struct struct_grafo *ptr,int ID);

void adiciona_vizinho(struct struct_grafo *ptr,int vizinho,int cost,int from);

struct no * retorna_ponteiro_no(struct struct_grafo *ptr,int id);

void adiciona_table(struct struct_grafo *ptr,int no, int from, int link_1,int link_2,int cost, int seq,int age);

void ve_table(struct struct_grafo *ptr,int no);

void envia_msg(struct struct_grafo *ptr, int no,int from,int link_1,int link_2,int cost,int seq,int age);

void manda_msg(struct struct_grafo *ptr,int no);

void flooding(struct struct_grafo *ptr,int no,int from,int link_1,int link_2, int cost , int seq ,int age);

int confere_table(struct struct_grafo *ptr,int no,int link_1,int link_2);

void muda_visitado(struct struct_grafo *ptr,int no);

int status_vistiado(struct struct_grafo *ptr,int no);

void lsa_min(struct struct_grafo *ptr,int no);

void lsa_max(struct struct_grafo *ptr);