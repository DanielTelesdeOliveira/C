#include <stdio.h>
#include "Booleano.h"
#define sinal -1
#define Geist 0
#define Max 10

typedef struct{
	int inicio;
	int fim;
	int Vetor[Max];
} Fila;

Fila criarFilaVazia();
bool FilaVazia(Fila);
int acessarPrimeiro(Fila);
Fila pushFila(Fila, int);
Fila popFila(Fila);
Fila esvaziarFila(Fila);
int obterTamanho(Fila);
void mostrarFila(Fila);

int main(){
	
	int tam;
	Fila Q;
	for(int i = 1; i < 	Max; i++)
		Q = pushFila(Q, i);
	
	Q = popFila(Q);
	Q = popFila(Q);
	Q = popFila(Q);
	
	Q = pushFila(Q, 1);
	Q = pushFila(Q, 11);
	Q = pushFila(Q, 12);
	Q = pushFila(Q, 13);
	
	Q = popFila(Q);
	Q = pushFila(Q,1);
	tam = obterTamanho(Q);
	
	mostrarFila(Q);
	printf("\n\n");
	
	
	printf("Tamanho: %d", tam);
	
	return 0;
}

Fila criarFilaVazia(){
	Fila Q;
	Q.inicio = sinal;
	Q.fim = sinal;
	return Q;
}

bool FilaVazia(Fila Q){
	bool vz = TRUE;
	if(Q.inicio != 0)
		vz = FALSE;
	
	return vz;
}

int acessarPrimeiro(Fila Q){
	int n = Geist, y;
	if(Q.inicio != sinal){
		y = Q.inicio;
		n = Q.Vetor[y];
	}
	
	return n;
}

Fila pushFila(Fila Q, int n){
	int seg;
	seg = (Q.fim + 1) % Max;
	if (seg != Q.inicio) {
		Q.Vetor[seg] = n;
		if ( Q.inicio == sinal ) Q.inicio = seg;
		Q.fim = seg;
	}
	return Q;	
}

Fila popFila(Fila Q){	
	int seg;
	if(Q.inicio != sinal) {
		if ( Q.inicio == Q.fim ) {
			Q.inicio = sinal; Q.fim = sinal;
		} else {
		   seg = (Q.inicio + 1) % Max;
		   Q.inicio = seg;
		  }
	}
	
	return Q;
}


Fila esvaziarFila(Fila Q){
	Q.inicio = sinal;
	Q.fim = sinal;
	return Q;
}

int obterTamanho(Fila Q){
	int tam;
	if(Q.inicio <= Q.fim)
		tam = Q.fim-Q.inicio+1;
	else tam = Max-1 - Q.fim+Q.inicio;
	return tam;
}

void mostrarFila(Fila Q){
	int i;
	if(Q.inicio <= Q.fim){
		for(i = Q.inicio; i <= Q.fim; i++)
			printf("%d ",Q.Vetor[i]);
		
	} else{
		for(i = Q.inicio; i < Max; i++)
			printf("%d ", Q.Vetor[i]);
		
		for(i = 0; i <= Q.fim; i++)
			printf("%d ", Q.Vetor[i]);	
			
	}	
	
}
