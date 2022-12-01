#include "lib.h"

void menu(){
    int op, valor, auxmatricula;

    //--------- iniciando a estrutura --------------------//
    Tuser *a = NULL;

    while(1) {
        //--------------- Exibir menu ---------------------//
        printf("\n\t\t\t\tGERENCIA DE PEDIDOS\n");
        printf("\t1 - CADASTRAR USUARIO \n \t2 - LISTAR USUARIOS \n \t3 - ALTERAR DADOS DO USUARIO \n \t4 - CADASTRAR SERVICO \n \t5 - BUSCAR USUARIO \n \t0 - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Op??o

        switch(op){
            case 1:
                printf("Informe a matricula: ");
                scanf("%d", &valor);
                a = inserir(a, valor);
                break;
            case 2:
                imprimirArv(a, 1);
                break;

            case 3:
                printf("informe a matricula: ");
                scanf(" %d", &auxmatricula);
                alterarUser(a, auxmatricula);

                if(a->nome == NULL || a->UniAcad == NULL || a->mod == NULL){
                    printf("informe a matricula: ");
                    scanf(" %d", &auxmatricula);
                    alterarUser(a, auxmatricula);
                }
                break;
            case 4:
                menuServ(a);
                break;

            case 5:
                printf("Informe a matricula: ");

                int k = 0;

                scanf("%d", &k);
                busca (a, k);
                break;
            case 0:
                exit(0);
            default:
                puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
                break;
        }
    }
}

int altura_AVL(Tuser *a){
    int alt_esq=0, alt_dir=0;
    if (a == NULL)
        return 0;
    else{
        alt_esq = altura_AVL(a->esq);
        alt_dir = altura_AVL(a->dir);
        if (alt_esq > alt_dir)
            return (1 + alt_esq);
        else
            return (1 + alt_dir);
    }
}

int calcula_FB(Tuser *a){
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
}

Tuser* rotacao_simples_esquerda(Tuser* a){
    Tuser * aux;
    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a = aux;
    return a;
}

Tuser * rotacao_simples_direita(Tuser *a){
    Tuser* aux;
    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a = aux;
    return a;
}

Tuser * balanceio_esquerda(Tuser *a){
    int fator = calcula_FB(a->esq);
    if(fator >0)
        return rotacao_simples_direita(a);
    else if (fator <0){
        a->esq = rotacao_simples_esquerda(a->esq);
        a = rotacao_simples_direita(a);
        return a;
    }
    else return a;
}

Tuser * balanceio_direita(Tuser *a){
    int fator = calcula_FB(a->dir);
    if(fator <0)
        return rotacao_simples_esquerda(a);
    else
    if(fator > 0){
        a->dir = rotacao_simples_direita(a->dir);
        a = rotacao_simples_esquerda(a);
        return a;
    }
    return a;
}

Tuser* balanceamento(Tuser* a){
    int fator = calcula_FB(a);
    if (fator > 1)
        return balanceio_esquerda(a);
    else if (fator <-1)
        return balanceio_direita(a);
    return a;
}

Tuser* inserir(Tuser* a, int matricula){//inserir usuario
    if(a == NULL){
        a = (Tuser *)malloc (sizeof(Tuser));
        a->matricula = matricula;
        a->esq = NULL;
        a->dir = NULL;
        a->servico = NULL;

        printf("Informe seu nome completo: ");
        scanf(" %s", &a->nome);
        printf("Informe sua Unidade Academica: ");
        scanf(" %s", &a->UniAcad);
        printf("Qual sua modalidade de ensino: ");
        scanf(" %s", &a->mod);

        if(a->nome == NULL || a->UniAcad == NULL || a->mod == NULL){
            printf("Alguns dados estao inconsistentes, insira novamente \n");
            printf("Informe seu nome completo: ");
            scanf(" %s", &a->nome);
            printf("Informe sua Unidade Academica: ");
            scanf(" %s", &a->UniAcad);
            printf("Qual sua modalidade de ensino: ");
            scanf(" %s", &a->mod);
        }

        return a;
    }

    else{
        if(a->matricula > matricula){
            a->esq = inserir(a->esq, matricula);
            a= balanceamento(a);
        }

        else
        {
            a->dir = inserir(a->dir, matricula);
            a= balanceamento(a);
        }

    }
}


/*
     imprimdo usuarios
*/
void imprimirArv(Tuser* a, int nivel){
    if(a){
        imprimirArv(a->dir, nivel + 1);
        printf("\n");

        printf("Matricula: %d", a->matricula);
        printf("\nNome: %s", a->nome);
        printf("\nUnidade academica: %s",a->UniAcad);
        printf("\nModalidade de ensino: %s\n",a->mod);

        imprimirArv(a->esq, nivel + 1);
    }
}

void busca (Tuser* a, int k) { //mudar para encontrar
    if (a == NULL || a->matricula == k){

        printf("Matricula: %d", a->matricula);
        printf("\nNome: %s", a->nome);
        printf("\nUnidade academica: %s",a->UniAcad);
        printf("\nModalidade de ensino: %s\n",a->mod);
        return;
    }
    if (a->matricula > a)
        return busca (a->esq, k);
    else
        return busca (a->dir, k);
}
void alterarUser (Tuser* a, int k){
    if (a == NULL || a->matricula == k){

        printf("Informe seu nome completo: ");
        scanf(" %s", &a->nome);
        printf("Informe sua Unidade Academica: ");
        scanf(" %s", &a->UniAcad);
        printf("Qual sua modalidade de ensino: ");
        scanf(" %s", &a->mod);

        printf("Dados alterados!");

        return;

    }
    if (a->matricula > a)
        return busca (a->esq, k);
    else
        return busca (a->dir, k);
}

void menuServ(Tuser *a){
    int op, os;
    int auxmatricula, auxserv;

    while(1){
        //--------------- Exibir menu ---------------------//
    
        printf("\n\t\t\t\tCADASTRO DE SERVICO\n");
        printf("\t1 - SOLICITAR SERVICO\n \t2 - EXIBIR SERVICOS\n \t3 - EDITAR STATOS DO SERVICO \n \t0 - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Op??o

        switch(op) {
            //Opcao de exibir lista
            case 1: {
                printf("Informe o numero do servico: ");
                scanf("%d", &os);
                printf("Informe sua matricula: ");
                scanf(" %d", &auxmatricula);
                a->servico = inserirServ(os, a, auxmatricula);
                break;
            }

            case 2: {
                printf("insira sua matricula: ");
                scanf(" %d", &auxmatricula);
                imprimeServ1(auxmatricula, a);
                break;
            }

            case 3: {
                printf("Informe sua matricula: ");
                scanf(" %d", &auxmatricula);
                printf("Informe o numero do servico: ");
                scanf(" %d", &auxserv);
                buscarMatri(auxmatricula, a);
                buscarServ(a->servico, auxserv);
                printf("Qual o status do servico: ");
                scanf(" %s", &a->servico->stts);
                break;
            }
            case 0:
                return;
            default:
                puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
                break;

        }
    }
}

TNserv* rotacao_simples_esquerdaServ(TNserv* s){//mesmo c?digo da AVL
    TNserv *aux;
    aux = s->dir;
    s->dir = aux->esq;
    aux->esq = s;
    s = aux;
    return s;
}

TNserv * rotacao_simples_direitaServ(TNserv *s){//mesmo c?digo da AVL
    TNserv *aux;
    aux = s->esq;
    s->esq = aux->dir;
    aux->dir = s;
    s = aux;
    return s;
}

TNserv* criarServ(int os){//mesmo c?digo da AVL
    TNserv * dado = (TNserv *) malloc(sizeof(TNserv));
    dado->os = os;
    dado->cor = vermelho;//s? um ajuste para inclus?o da cor
    dado->esq = NULL;
    dado->dir = NULL;
    dado->quant = 1;
    printf("Informe a descricao do servico: ");
    scanf(" %s", &dado->descri);
    printf("Informe o status do servico: ");
    scanf(" %s", &dado->stts);
    return dado;
}


Tuser *buscarMatri(int value, Tuser *a) {
    if(a == NULL) {
        return NULL;
    }

    Tuser* user = a;

    while(user != NULL){
        if(value == user->matricula) {
            return user;
        }

        user = value > user->matricula ? user->dir : user->esq;
    }

    return NULL;
}

TNserv * buscarServ(TNserv *Servi, int auxserv){
    if(Servi->os > auxserv){
        Servi->esq = buscarServ(Servi->esq, auxserv);
    }

    else if(Servi->os < auxserv)
    {
        Servi->dir = buscarServ(Servi->dir, auxserv);

    } else{
        return Servi;
    }

}

TNserv* inserirServ(int os, Tuser *a, int auxmatricula){
    Tuser *b = buscarMatri(auxmatricula, a);
    TNserv* dado = criarServ(os);
    b->servico = incluir_Nserv(b->servico, dado);
    if(b->servico !=NULL)
        b->servico->cor = preto;

    return b->servico;
}

TNserv* incluir_Nserv(TNserv* servico, TNserv* dado){
    if(servico==NULL) //arvre ser vazia
        return dado;

    if(servico->os == dado->os){
        servico->quant++;
    }
    else{ //se vai ser inserido ? esquerda ou ? direita
        if(servico->os > dado->os)
            servico->esq = incluir_Nserv(servico->esq, dado);
        else
            servico->dir = incluir_Nserv(servico->dir, dado);

        if((cor(servico->esq)== vermelho) && (cor(servico->dir)== vermelho)){
            trocaCor(servico);
        }
        if ((cor(servico->esq) == vermelho) && (cor(servico->esq->esq) == vermelho)){
            servico->cor = vermelho;
            (servico->esq)->cor = preto;
            servico = rotacao_simples_direitaServ(servico);
        }
        if((cor(servico->esq) == vermelho) && (cor(servico->esq->dir) == vermelho)){
            TNserv *aux = rotacao_simples_esquerdaServ(servico->esq);
            servico->esq = aux;
            servico->cor = vermelho;
            (servico->esq)->cor = preto;
            servico = rotacao_simples_direitaServ(servico);
        }
        if ((cor(servico->dir) == vermelho) && (cor(servico->dir->dir) == vermelho)){
            servico->cor = vermelho;
            (servico->dir)->cor = preto;
            servico = rotacao_simples_esquerdaServ(servico);
        }
        if((cor(servico->dir) == vermelho) && (cor(servico->dir->esq) == vermelho)){
            TNserv *aux = rotacao_simples_direitaServ(servico->dir);
            servico->dir = aux;
            servico->cor = vermelho;
            (servico->dir)->cor = preto;
            servico = rotacao_simples_esquerdaServ(servico);
        }

    }
    return servico;
}

int cor(TNserv* s){
    if(s==NULL)
        return preto; //toda folha tem cor preta
    else
        return s->cor;
}

void trocaCor(TNserv* s){
    s->cor = !s->cor;
    if(s->esq !=NULL)
        s->esq->cor = !s->esq->cor;
    if(s->dir !=NULL)
        s->dir->cor = !s->dir->cor;
}

void imprimeServ1(int auxmatricula, Tuser* a){
    Tuser *usuario = buscarMatri(auxmatricula, a);

    if(usuario == NULL) {
        printf("usuario nao encontrado");
        return;
    }

    if(usuario->servico == NULL) {
        printf("servico nao encontrado");
        return;
    }

    imprimeServ(usuario->servico);
}

void imprimeServ(TNserv* s){//mesmo c?digo da AVL
    if (s == NULL){
        return;
    }
    printf("\nServicos:");
    printf("\nOS: %d [cor: %d]",s->os, s->cor);
    printf("\nQuantidade:%i", s->quant);
    printf("\nStatus: %s", s->stts);
    printf("\nDescricao: %s\n", s->descri);

    if(s->esq != NULL)
        printf("(E:%d [cor: %d])",s->esq->os, s->esq->cor);
    if(s->dir != NULL)
        printf("(D:%d [cor: %d])",s->dir->os, s->dir->cor);
    printf("\n");

    imprimeServ(s->esq);
    imprimeServ(s->dir);
}

