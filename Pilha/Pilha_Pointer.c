#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define Max 101
#define ghost 63
#define sinal 0

typedef struct{
int topo; //o campo topo aponta para o último item colocado na pilha
unsigned char vetor[Max]; //o primeiro a entrar na pilha é colocado na posição 1
//o tamanho máximo da pilha é guardado na posição 0.
} cPilha;
typedef cPilha* Pilha;

// interface
Pilha newPilha( ); //cria a pilha vazia
bool PilhaVazia(Pilha); //devolve TRUE se a pilha é vazia, FALSE, caso contrário
unsigned char acessarPilha(Pilha); //devolve o item que está no topo da pilha
void pushPilha(Pilha,unsigned char);//coloca um item na pilha
void popPilha(Pilha); //retira um item da pilha
void esvaziarPilha(Pilha); //esvazia a pilha   
void mostrarPilha(Pilha);
int obterProfundidade(Pilha);

int main(){
	int i;
	Pilha S;
	bool var;
	S = newPilha();	
	
	pushPilha(S, 'A');
	pushPilha(S, 'B');
	pushPilha(S, 'C');
	mostrarPilha(S);


	return 0;
}

Pilha newPilha(){
	Pilha A;
	A = (Pilha)malloc(sizeof(cPilha));
	A->topo = sinal;
	A->vetor[A->topo] = Max-1;
	return A;	
}

bool PilhaVazia(Pilha P){
	bool vazio;
	
	if(P->topo == sinal)
		vazio = TRUE;
	else
		vazio = FALSE;
			
	return vazio;
}

unsigned char acessarPilha(Pilha P){
	int topo = P->topo;
	unsigned char y;
	if(topo != sinal){
		y = P->vetor[topo];
	}
	else
		y = ghost;
	
	return y;	
}

void pushPilha(Pilha P, unsigned char y){
	int topo = P->topo;
	if(topo != P->vetor[0]){
		topo++;
		P->vetor[topo] = y;
		P->topo = topo;
	}

}

void popPilha(Pilha P){
	int topo = P->topo;
	if(topo != sinal){
		P->topo--;
	}
	
	
}

void esvaziarPilha(Pilha P){
	if(P->topo != sinal)
		P->topo = 0;
}

void mostrarPilha(Pilha P){
	int topo = P->topo, i;
	if(topo != sinal){
		for(i = topo; i > 0; i--)
			printf("%c\n", P->vetor[i]);
	}
}

int obterProfundidade(Pilha P){
	int profundidade = P->topo;
	return profundidade;
}