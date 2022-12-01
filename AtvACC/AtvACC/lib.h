#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef enum {vermelho, preto} Tcor;

typedef struct Nserv{
	int os;
	int cor;
	char stts[100];
	int quant;
	char descri[250];
	struct Nserv* esq;
	struct Nserv* dir;

}TNserv;

typedef struct user{
	int matricula;
	char nome[100];
	char mod[10];
	char UniAcad[100];
	int fator_b;
	TNserv *servico;
	
	struct user* esq;
	struct user* dir;

}Tuser;

void menu();
int altura_AVL(Tuser *a);
int calcula_FB(Tuser *a);
Tuser* rotacao_simples_esquerda(Tuser *a);
Tuser* rotacao_simples_direita(Tuser *a);
Tuser* balanceamento(Tuser* a);
Tuser* inserir(Tuser* a, int matricula);
void imprime(Tuser* a);
void imprimeServ1(int auxmatricula, Tuser* a);
Tuser * buscarMatri(int auxmatricula, Tuser *a);
TNserv * buscarServ(TNserv *Servi, int auxserv);

void menuServ();
TNserv* rotacao_simples_esquerdaServ(TNserv *s);
TNserv* rotacao_simples_direitaServ(TNserv *s);

TNserv* criar(int os);
TNserv* incluir_Nserv(TNserv* s, TNserv* dado);
TNserv* inserirServ(int os, Tuser *a, int auxmatricula);

int cor(TNserv* s);
void trocaCor(TNserv* s);

void imprimeServ(TNserv* s);

