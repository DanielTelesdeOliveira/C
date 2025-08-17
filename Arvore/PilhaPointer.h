/* Pilha de pointer */
/*
  Arquivo: PilhaPointer.h
  Autor: Fubá
  Data: 28/08/24 15:01
  Descrição: Este programa implementa um pacote de funções para o tipo Pilha.
  Os elementos da pilha são endereços - tipo pointer "coringa".
  A pilha é armazenada em um array a partir da posição zero.
  O campo topo mostra a posição onde deverá ser armazenado o próximo item.
  O valor constante Max determina o tamanho do array.
*/
#include "Booleano.h"

#define MaxPilha 20

typedef struct {
    int topo;
    void *tabela[MaxPilha];
} Pilha;

//protótipos
void criarPilhaVazia(Pilha *);
void *acessarTopo(Pilha *);
bool verificarPilhaVazia(Pilha *);
bool verificarPilhaCheia(Pilha *);
void pushPilha(Pilha *, void *);
void popPilha(Pilha *);

// implementações
void criarPilhaVazia(Pilha *a){
    a->topo = 0;
}

void *acessarTopo(Pilha *a){
    int k;
    void *t;
    if (a->topo != 0){
    	k = a->topo - 1;
		t = a->tabela[k];
	}else t= NULL;
    return t;
}     

bool verificarPilhaVazia(Pilha *a){
    int vazia;
    if (a->topo == 0) vazia = TRUE; else vazia = FALSE;
    return vazia;
}

bool verificarPilhaCheia(Pilha *a){
    int cheia;
    if (a->topo == MaxPilha) cheia = TRUE; else cheia = FALSE;
    return cheia;
}

void pushPilha(Pilha *a, void *novo){
    int k;
    k = a->topo;
    if (a->topo < MaxPilha) {	
		a->tabela[k] = novo;
     	a->topo = k + 1;
	}
}

void popPilha(Pilha *a){
    int k;
    k = a->topo;
    if (a->topo != 0){
     	a->topo = k-1;
 	}
}

