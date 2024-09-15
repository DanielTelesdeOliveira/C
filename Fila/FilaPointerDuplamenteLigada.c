#include <stdio.h>
#include <stdlib.h>
typedef struct Celula{
	int ponto;
	struct Celula* suc;
	struct Celula* pre;
}Celula;

typedef struct{
	Celula* inicio;
	Celula* fim;
}Fila;

void criarFila(Fila*);
void pushFila(Fila*, int);
void popFila(Fila*);
void mostrarFila(Fila);

int main(){
	Fila Q;
	criarFila(&Q);
	pushFila(&Q, 1);
	pushFila(&Q, 2);
	pushFila(&Q, 3);
	pushFila(&Q, 4);
	pushFila(&Q, 5);
	popFila(&Q);
	
	mostrarFila(Q);
	
	return 0;
}

void criarFila(Fila* q){
	q->inicio = NULL;
	q->fim = NULL;
}


void pushFila(Fila* q, int y){
	Celula* novo;
	novo = malloc(sizeof(Celula));
	novo->ponto = y;
	novo->suc = NULL;
	if(q->inicio == NULL){
		novo->pre = NULL;
		q->inicio = novo;
		q->fim = novo;
	}else{
		novo->pre = q->fim;
		q->fim->suc = novo;
		q->fim = novo;
	}	
}

void popFila(Fila* q){
	Celula* p, *pri;
	if(q->inicio != NULL){
		pri = q->inicio;
		if(pri->suc != NULL){
			p = pri->suc;
			p->pre = NULL;
			q->inicio = p;
		} else{
			q->inicio = NULL;
			q->fim = NULL;
		}
		free(pri);	
	}
	
}


void mostrarFila(Fila q){
	Celula* p;
	if(q.inicio != NULL){
		p = q.inicio;
		while(p != NULL){
			printf("%d ", p->ponto);
			p = p->suc;
		}		
	}			
}
