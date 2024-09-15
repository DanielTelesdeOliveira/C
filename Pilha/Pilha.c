#include <stdio.h>
#include <stdbool.h>
#define Max 10
#define sinal 0
#define fantasma 36

typedef struct{
	int topo;
	unsigned char Vetor[Max];
}Pilha;

Pilha criarPilha();
bool PilhaVazia (Pilha);
unsigned char acessarPilha(Pilha);
Pilha pushPilha(Pilha, unsigned char);
Pilha popPilha (Pilha);
Pilha esvaziarPilha(Pilha);
int obterProfundidade(Pilha);
void mostrarPilha(Pilha);
Pilha inverterPilha(Pilha);
void invPilha(Pilha*);
void copiarPilha(Pilha*, Pilha*);
Pilha copiarPilhaR(Pilha);

int main(){
	Pilha A;
	int profundidade;
	bool var;
	char y;
	
	A = criarPilha();
	var = PilhaVazia(A);
	
	if(var) 
		printf(" Vazia\n"); 
	else 
		printf(" Nao vazia\n");
		
	A = pushPilha(A,'A');
	A = pushPilha(A,'m');
	A = pushPilha(A,'o');
	A = pushPilha(A,'r');
	
	mostrarPilha(A);
	Pilha B;
	//copiarPilha(&A,&B);
	B = copiarPilhaR(A);
	printf("	Pilha B: 	");
	mostrarPilha(B);
	//A = inverterPilha(A);
	/*invPilha(&A);

	mostrarPilha(A);
	
	if(var) 
		printf(" Vazia\n"); 
	else
	 	printf(" Nao vazia\n");
	 	
	y = acessarPilha(A);
	printf("\n Valor de y: %c \n", y);
	
	A = popPilha(A);
	y = acessarPilha(A);
	printf("\n Valor de y pos pop: %c \n", y);
	
	profundidade = obterProfundidade(A);
	printf("\n Profundidade da pilha: %d \n", profundidade);
	
	A = esvaziarPilha(A);
	var = PilhaVazia(A);
	
	profundidade = obterProfundidade(A);
	printf("\n Profundidade da pilha: %d \n\n", profundidade);
	
	if(var)
		printf(" Vazia\n"); 
	else 
		printf(" Nao vazia\n");
		
	y = acessarPilha(A);
	printf("\n Valor de y pos esvaziar: %c \n", y);
	
	mostrarPilha(A);*/
	
	return 0;
}

Pilha criarPilha(){
	Pilha P;
	P.Vetor[0] = Max-1;
	P.topo = sinal;
	return P;
}

bool PilhaVazia (Pilha P){
	bool b;
	if(P.topo == sinal)
		b = true;
	else
		b = false;
	
	return b;		
}

unsigned char acessarPilha(Pilha P){
	char ch;
	int s;
	if(P.topo != sinal){
		s = P.topo;	
		ch = P.Vetor[s];
	}
	else
		ch = fantasma;
	
	return ch;		
}

Pilha pushPilha(Pilha P, unsigned char ch){
	int s;
	if (P.topo != P.Vetor[0]){
		s = P.topo + 1;
		P.Vetor[s] = ch;
		P.topo = s;
	}
	
	return P;
}

Pilha popPilha(Pilha P){
	if (P.topo != sinal){
		P.topo--;
	}
	
	return P;
}

Pilha esvaziarPilha(Pilha P){
	P.topo = sinal;	
	return P;
}

int obterProfundidade(Pilha P){
	int tam;
	tam = P.topo;
	return tam;
}

void mostrarPilha(Pilha P){
	int i;
	if(P.topo != sinal){
		printf("\n Valor do topo : %d\n", P.topo);
		printf(" Itens armazenados na Pilha: \n ");
		for(i = P.topo; i > 0; i--)
			printf("%c ", P.Vetor[i]);
	}
	else 
		printf("\n A pilha esta vazia. \n");
	printf("\n");	
}

Pilha inverterPilha(Pilha P){
	Pilha B;
	int i,j;
	if(P.topo != sinal){
		j = 1;
		B.topo = P.topo;
		B.Vetor[0] = P.Vetor[0];
		for(i = P.topo; i > 0; i--){
			B.Vetor[j] = P.Vetor[i];
			j++;
		}
	}
	return B;
}

void invPilha(Pilha * P){
	int i, tam, j = 1;
	unsigned char aux;
	tam = P->topo;
	for(i = tam; i > tam/2; i--){
		aux = P->Vetor[i];
		P->Vetor[i] = P->Vetor[j];
		P->Vetor[j] = aux;
		j++;
	}
}

void copiarPilha(Pilha * P, Pilha * Q){
	if(P->topo != sinal){
		*Q = *P;
	}
}

Pilha copiarPilhaR(Pilha P){
	Pilha A;
	int tam, i;
	if(P.topo != sinal){
		tam = P.topo;
		A.topo = P.topo;
		A.Vetor[0] = P.Vetor[0];
		
		for(i = 1; i <= tam; i++){
			A.Vetor[i] = P.Vetor[i];
		}
	}
	
	return A;	
	
}