#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define ghost -1
typedef struct Celula{
	 int elemento;
	 struct Celula* suc;
	 struct Celula* pre;
}Celula;

typedef struct{
	int tamanho;
	Celula* inicio;
	Celula* fim;
}Lista;

 Lista newLista( ); 
 bool ListaVazia(Lista*); 
 int obterTamanho(Lista*); 
 int obterElemento(Lista*, int); 
 int localizarItem(Lista*, int); 
 void mostrarLista(Lista*); 
 void inserirLista(Lista*, int); 
 void removerPrimeiro(Lista*);
 void esvaziarLista(Lista*); 
 void removerUltimo(Lista*); 
 //Celula* buscarItem(Lista*,char);

int main(){
	Lista L = newLista();
	for(int i = 1; i <= 5; i++){
		inserirLista(&L, i);
	}
	
	mostrarLista(&L);
	
	
	int tamanho = obterTamanho(&L);
	printf("\ntamanho da lista: %d ", tamanho);
	printf("\n Ultimo item da lista: %d ", L.fim->elemento);
	
	int indice = localizarItem(&L, 5);
	printf("\nindice de 5 na lista L: %d", indice);
	
	/*removerUltimo(&L);
	removerUltimo(&L);
	removerUltimo(&L);
	printf("\n Ultimo item da lista: %d ", L.fim->elemento);
	removerUltimo(&L);
	removerUltimo(&L);
	tamanho = obterTamanho(&L);
	printf("\ntamanho da lista: %d \n", tamanho);
	mostrarLista(&L);
//	printf("\nUltimo item da lista: %d ", L.fim->elemento);*/
	return 0;
}

Lista newLista(){
	Lista L;
	L.tamanho = 0;
	L.inicio = NULL;
	L.fim = NULL;
	return L;
}

bool ListaVazia(Lista* ap){
	bool vz = FALSE;
	if(ap->inicio == NULL)
		vz = TRUE;

	return vz;
}

void inserirLista(Lista* ap, int n){
	Celula* novo;
	novo = malloc(sizeof(Celula));
	novo->elemento = n;
	novo->pre = NULL;
	if(ap->inicio == NULL){
		novo->suc = (struct Celula*)ap->inicio;
		ap->inicio = (Celula*)novo;
		ap->fim = (Celula*)ap->inicio;
	} else{
		novo->suc = (struct Celula*)ap->inicio;
		ap->inicio->pre = (struct Celula*)novo;
		ap->inicio = (Celula*)novo;
	}
	
	ap->tamanho++;
	
}
void mostrarLista(Lista* ap){
	Celula* p;
	if(ap->inicio != NULL){
		p = ap->inicio;
		while(p != NULL){
			printf("%d ", p->elemento);
			p = (Celula*)p->suc;
		}
		printf("\n");
	} else printf("\nA lista esta vazia. \n");
}

int obterTamanho(Lista* ap){
	int tam;
	tam = ap->tamanho;
	return tam;
}

//Obter elemento de ordem n
int obterElemento(Lista* aL, int n){
	int e = ghost, cont = 0;
	Celula * p;
	if(aL->inicio != NULL){
		if(n > 0 && n <= aL->tamanho){
			p = aL->inicio;
			cont++;
			while(p != NULL && cont != n){
				cont++;
				p = p->suc;
			}
			if(p != NULL)
				e = p->elemento;
		}
	}
	
	return e;		
}


void esvaziarLista(Lista* aL){
	//Verificar se a lista e vazia
	//Se a lista nao for vazia e tiver um elemento...
	//Se a lista nao for vazia e tiver mais de um elemento...
	Celula* p, *next;
	if(aL->inicio != NULL){
		p = aL->inicio;
		if(p->suc != NULL){   //Verifica se ha mais de um elemento
			while(p->suc != NULL){ //Enquanto existir um proximo
				next = p->suc;
				free(p);
				p = next;
			}
			free(p);
		} else{ //A lista tem apenas um elemento
			free(p);
		  }	 
	
		aL->inicio = NULL;
		aL->fim = NULL;
		aL->tamanho = 0;
	}
}

void removerPrimeiro(Lista* aL){
	//Verificar se a lista nao e vazia
	//Se a lista nao for vazia, verificar se possui mais de um elemento
	//Senao....
	Celula* p, *next;
	if(aL->inicio != NULL){
		p = aL->inicio;
		if(p->suc != NULL){ //A lista tem mais de um elemento
			next = p->suc;
			free(p);
			next->pre = NULL;
			aL->inicio = next;
			aL->tamanho--;
		} else{ //A lista tem um unico elemento
			free(p);
			aL->inicio = NULL;
			aL->fim = NULL;
			aL->tamanho = 0;
		 }
	}
	
}


void removerUltimo(Lista* aL){
 	//Verificar se a lista e vazia
 	//Se nao for vazia, verificar se tem mais de um elemento
 	//Senao....
 	Celula* p, *ult;
 	if(aL->inicio != NULL){
 		p = aL->inicio;
 		if(p->suc != NULL){ //Se existe um proximo
			while(p->suc != NULL){ //Enquanto nao chegar nao fim na lista
				ult = p;
				p = p->suc;
			}
			ult->suc = NULL;
			free(p);
			aL->fim = ult;
			aL->tamanho--;
	    } else{
	    	aL->inicio = NULL;
	    	aL->fim = NULL;
	    	free(p);
	    	aL->tamanho = 0;
		}
 	
 	}
}

int localizarItem(Lista* aL, int n){
	Celula* p;
	int cont = 0, indice = 0;
	if(aL->inicio != NULL){
		p = aL->inicio;
		cont++;
		while(p != NULL && p->elemento != n){
			cont++;
			p = p->suc;
		}
		if(p != NULL)
			indice = cont;
	}	
	return indice;
}