#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef enum {vermelho, preto} Tcor;

typedef struct Nserv{
	int Servi;
	int cor;
	char stts;
	int quant;
	//falta adicionar descrição do serviço
	struct Nserv* esq;
	struct Nserv* dir;

}TNserv;

typedef struct user{
	int matricula;
	int mod;//modalidade do curso e falta adicionar nome completo
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


void menuServ();
TNserv* rotacao_simples_esquerdaServ(TNserv *s);
TNserv* rotacao_simples_direitaServ(TNserv *s);

TNserv* criar(int Servi);
TNserv* incluir_Nserv(TNserv* s, TNserv* dado);
TNserv* inserirServ(TNserv* s, int valor);

int cor(TNserv* s);
void trocaCor(TNserv* s);

void imprimeServ(TNserv* s);
