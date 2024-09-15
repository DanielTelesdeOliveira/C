/* Lista Ligada - percorrer a lista */
/*
  Arquivo: ListaSimplesmenteEncadeada.c
  Date: 12/05/24 09:48
  Descrição: Implementa o tipo Lista - uma lista encadeada com cabeça
             A lista contém inteiros não negativos.
*/

#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"
#define ghost -1

typedef struct Celula{
        int item;
        struct Celula* next;
}Celula;

typedef struct{
        int tamanho;
        Celula* inicio;
}Lista;

/* INTERFACE */

Lista criarLista();                   	// cria uma lista vazia	
bool verListaVazia(Lista*);             // devolve TRUE se a lista é vazia
int obterTamanho(Lista*);              	// devolve o tamanho da lista
void mostrarLista(Lista*);              // mostra na tela os elementos da lista					
void inserir(Lista*, int);           	// acrescenta um novo elemento ao inicio da lista
int localizarElemento(Lista*, int);		// devolve a ordem do registro que contém y ou zero
int obterElemento(Lista*, int);
void removerPri(Lista*); // Remove o primeiro registro da lista
void removerUlt(Lista*); // Remove o ultimo registro da lista
void removerItemEspecificio(Lista*, int);
void inserirOrdenado(Lista*, int);
void esvaziarLista(Lista*);

int main(){
	Lista L;
	int w;
	int ordem;
	
	printf("\n");
	L = criarLista(); // mostrarLista(&L);
	inserir(&L, 2022);
	w = 10; printf(" inserir %d \n",w);
	inserirOrdenado(&L,w);   //	mostrarLista(&L);
	
	w = 20; printf("\n inserir %d \n",w);
	inserirOrdenado(&L,w);   	//mostrarLista(&L);
	
	w = 30; printf("\n inserir %d \n",w);
	inserirOrdenado(&L,w);   //	mostrarLista(&L);
	
	w = 40; printf("\n inserir %d \n",w);
	inserirOrdenado(&L,w);   	//mostrarLista(&L);
	
	w = 50; printf("\n inserir %d \n",w);
	inserirOrdenado(&L,w);   	//mostrarLista(&L);
	
	//w = 10;
	//ordem = localizarElemento(&L,w); printf("\n item = %d  ordem = %d \n",w,ordem);
	inserirOrdenado(&L, 201);
	inserirOrdenado(&L, 200);
	inserirOrdenado(&L, 199);
	inserirOrdenado(&L, 205);
	inserirOrdenado(&L, 1110);
	inserirOrdenado(&L, 33);
	inserirOrdenado(&L, 0);
	inserirOrdenado(&L, 13);
	inserirOrdenado(&L, 25);
	inserirOrdenado(&L, 5);
	inserirOrdenado(&L, -39);
	inserirOrdenado(&L, -1);
	inserirOrdenado(&L, 25);
	removerItemEspecificio(&L, -39);
//	for(int i = -10; i < 10; i++)
	//	inserirOrdenado(&L, i);
	//removerUlt(&L);	
	printf("\n\n\n\n\n");
	mostrarLista(&L);
	esvaziarLista(&L);
	mostrarLista(&L);
	printf("\n\n FIM ");
	return 0;
}

/* IMPLEMENTAÇÃO */
Lista criarLista(){     
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    return L;
}

bool verListaVazia(Lista * ap){
    bool vz = TRUE;
    if(ap->tamanho != 0)
    	vz = FALSE;
    	
    return vz;	
}

int obterTamanho(Lista * ap){
    int tam;
    tam = ap->tamanho;
    return tam;
}
     
void inserir(Lista *ap, int y){
    Celula *novo;
    novo = malloc(sizeof(Celula));
    novo->item = y;
    novo->next = ap->inicio;
    ap->inicio = novo;
    ap->tamanho = ap->tamanho+1;
}
       
void mostrarLista(Lista * ap){
    int k;
    Celula *p;
    if(ap->inicio == NULL)
    	printf(" A lista esta vazia\n\n");
    else{
    	p = ap->inicio;
    	k = p->item;
	    printf("  %d  ", k);
	    p = p->next;
	    while(p != NULL){
	    	k = p->item;
	    	printf("  %d  ", k);
	    	p = p->next;
		}	

	}	
    
}

int localizarElemento(Lista* ap, int y){
	int k = 0, cont;
	Celula* p;
	
	if(ap->inicio != NULL){
		p = ap->inicio;
		cont++;
		while(p->next != NULL && p->item != y){
			p = p->next;
			cont++;
		}
		
		if(p->item == y) 
			k = cont;
	}
	return k;	
}

int obterElemento(Lista* ap, int y){
	int cont, e = ghost;
	Celula* p;
	if(ap->inicio != NULL){
		if(y > 0 && y <= ap->tamanho){
			p = ap->inicio;
			cont++;
			while(cont < y){
				p = p->next;
				cont++;
			}
		  e = p->item;
		}
	}
	
	return e;
}	

void removerPri(Lista* ap){
	Celula* p;
	if(ap->inicio != NULL){
		p = ap->inicio;
		ap->inicio = p->next;
		free(p);
		ap->tamanho = ap->tamanho-1;
	}
	
}

void removerUlt(Lista* ap){
	Celula* p, *u;
	if(ap->inicio != NULL){
		p = ap->inicio;
		while(p->next != NULL){	
			u = p;
			p = p->next;	
		}	
		free(p);
		u->next = NULL;
		ap->tamanho = ap->tamanho-1;
	}
	
}

void removerItemEspecificio(Lista* ap, int y){
	Celula* p, *aux;
	//Verificar se a lista e vazia
	//Se nao for --> verificar se o elemento pertence a lista e suas posicaoes:
	// ser removido e o primeiro
	//Verificar se e o ultimo
	//Verifica se estiver no meio
	if(ap->inicio != NULL){
		p = ap->inicio;
		while(p != NULL && p->item != y){
			aux = p;
			p = p->next;
		}
		if(p != NULL){
				if(p == ap->inicio){
					ap->inicio= p->next;
				}  else if(p->next == NULL){
						aux->next = NULL;
					} else{
						aux->next = p->next;
					}
				
				free(p);
				ap->tamanho--;
		}
	}
	
}

void inserirOrdenado(Lista* ap, int y){
	Celula* p, *aux, *ant;
	//Verificar se e vazia
	//Se nao for achar a posicao
	//Se for o menor valor da lista -> inserir no inicio
	//Se for o maior valor da lista -> inserir no fim
	//Senao -> inserir no meio
	p = malloc(sizeof(Celula));
	p->item = y;
	if(ap->inicio != NULL){
		aux = ap->inicio;
		while(aux != NULL && p->item < aux->item){ //Enquanto existir um proximo ou p for menor que aux
			ant = aux;
			aux = aux->next;
		}
		if(aux == NULL){ //Menor valor --> inserir no fim
			ant->next = p;
			p->next = NULL;
		} else if(aux == ap->inicio){ //Maior valor --> inserir no comeco
				 p->next = aux;
				 ap->inicio = p;
			  } else{ //Senao --> inserir entre as celulas  
			  	ant->next = p;
			  	p->next = aux;
			  }
	} else{
		p->next = ap->inicio;
		ap->inicio = p;
	}
	
	ap->tamanho++;
}

void esvaziarLista(Lista* ap){
	Celula* p, *prox;
	
	if(ap->inicio != NULL){
		p = ap->inicio;
		while(p != NULL){
			prox = p->next;
			free(p);
			p = prox;
		}
		ap->inicio = NULL;
	}	
}