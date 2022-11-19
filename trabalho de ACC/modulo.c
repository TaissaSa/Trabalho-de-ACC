#include "lib.h"

void menu(){
	int op, valor;
	
	//--------- iniciando a estrutura --------------------//
    Tuser *user = NULL;
    
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tGERENCIA DE PEDIDOS\n");
        puts("\t1  - CADASTRAR USUARIO \n \t2  - LISTAR USUARIOS \n \t3 - ALTERAR DADOS DO USUARIO \n \t4 - CADASTRAR SERVIÇO \n \t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Op��o
        
        switch(op)
        {
    		case 1:{
    			printf("Informe a matricula: ");
    			scanf("%d", &valor);
    			user = inserir(user, valor);
    			imprime(user);
				break;
			}
    		
    		case 2:{
    			imprime(user); break;
			}

			case 3:{

			}

			case 4:{
				menuServ();
			}
    			
	    	default:
	    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
					break;
	      
	        }
		getch();
	    }while(op!=0);
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

Tuser* inserir(Tuser* a, int matricula){
   if(a == NULL){
   	a = (Tuser *)malloc (sizeof(Tuser));
   	a->matricula = matricula;
   	a->esq = NULL;
   	a->dir = NULL;
	a->servico = NULL;
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


void imprime(Tuser* a){
    if (a == NULL){
		return;
	}
    printf("%d",a->matricula);
 
    if(a->esq != NULL)
        printf("(E:%d)",a->esq->matricula);
    if(a->dir != NULL)
        printf("(D:%d)",a->dir->matricula);
    printf("\n");
 
    imprime(a->esq);
    imprime(a->dir);
}



void menuServ(){//falta ligar a arvore de user na de serviço pois o serviço é por usuario e para inserir precisa ser feita uma busca com base na matricula do usurario e passar a matricula como parametro setando para a variavel servico
	int op, Servi;
	int auxmatricula, auxserv;
    
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tCADASTRO DE SERVIÇO\n");
        puts("\t1  - SOLICITAR SERVICO\n \t2  - EXIBIR SERVICOS\n \t4 - EDITAR STATOS DO SERVICO \n \t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Op��o
        
        switch(op)
        {
        //Op��o de exibir lista
    		case 1:{
    			printf("Informe o numero do servico: ");
    			scanf("%d", &Servi);
				printf("\nInforme sua matricula: ");
				scanf(" %d", &auxmatricula);
    			servico = inserirServ(servico, Servi);
    			imprimeServ(servico);
				break;
			}
    		
    		case 2:{
    			imprimeServ(servico);
			}

			case 3:{
				printf("Informe o numero do serviço: ");
				scanf(" %d", &auxserv);
				//falta função de busca e de modificação
			}
    			
	    	default:
	    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
					break;
	      
	        }
		getch();
	    }while(op!=0);
}


TNserv* rotacao_simples_esquerdaServ(TNserv* s){//mesmo c�digo da AVL
   TNserv *aux;
   aux = s->dir;
   s->dir = aux->esq;
   aux->esq = s;
   s = aux;   
   return s;
}
TNserv * rotacao_simples_direitaServ(TNserv *s){//mesmo c�digo da AVL
  TNserv *aux;
	aux = s->esq;
	s->esq = aux->dir;
	aux->dir = s;
	s = aux;
  return s;
}

TNserv* criarServ(int Servi){//mesmo c�digo da AVL
	TNserv * dado = (TNserv *)malloc(sizeof(TNserv));
    dado->Servi = Servi;
    dado->cor = vermelho;//s� um ajuste para inclus�o da cor
    dado->esq = NULL;
    dado->dir = NULL;
    return dado;
}
TNserv* inserirServ(TNserv* s, int Servi){
	TNserv* dado = criarServ(Servi);
	s = incluir_Nserv(s, dado);

	if(s!=NULL)
		 s->cor = preto;
	
	return s;
}
TNserv* incluir_Nserv(TNserv* s, TNserv* dado){
	if(s==NULL) //arvre ser vazia
		return dado; 
		
	if(s->Servi == dado->Servi); //Servi j� existir na �rvore
	else{ //se vai ser inserido � esquerda ou � direita
		if(s->Servi > dado->Servi)
			s->esq = incluir_Nserv(s->esq, dado);
		else
			s->dir = incluir_Nserv(s->dir, dado);
			
		if((cor(s->esq)== vermelho) && (cor(s->dir)== vermelho)){
			trocaCor(s);
		}
		if ((cor(s->esq) == vermelho) && (cor(s->esq->esq) == vermelho)){
			s->cor = vermelho;
			(s->esq)->cor = preto;
			s = rotacao_simples_direitaServ(s);
		}
		if((cor(s->esq) == vermelho) && (cor(s->esq->dir) == vermelho)){
			TNserv *aux = rotacao_simples_esquerdaServ(s->esq);
			s->esq = aux;
			s->cor = vermelho;
			(s->esq)->cor = preto;
			s = rotacao_simples_direitaServ(s);
		}
		if ((cor(s->dir) == vermelho) && (cor(s->dir->dir) == vermelho)){
			s->cor = vermelho;
			(s->dir)->cor = preto;
			s = rotacao_simples_esquerdaServ(s);
		}
		if((cor(s->dir) == vermelho) && (cor(s->dir->esq) == vermelho)){
			TNserv *aux = rotacao_simples_direitaServ(s->dir);
			s->dir = aux;
			s->cor = vermelho;
			(s->dir)->cor = preto;
			s = rotacao_simples_esquerdaServ(s);
		}
			
	}
	return s;	
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
void imprimeServ(TNserv* s){//mesmo c�digo da AVL
    if (s == NULL){
		return;
	}
    printf("%d [cor: %d]",s->Servi, s->cor);
 
    if(s->esq != NULL)
        printf("(E:%d [cor: %d])",s->esq->Servi, s->esq->cor);
    if(s->dir != NULL)
        printf("(D:%d [cor: %d])",s->dir->Servi, s->dir->cor);
    printf("\n");
 
    imprimeServ(s->esq);
    imprimeServ(s->dir);
}


