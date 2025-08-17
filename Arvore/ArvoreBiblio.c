#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Booleano.h"
#include "FilaPointer.h"
#include "PilhaPointer.h"

typedef struct No{
	int chave;
	struct No *esq;
	struct No *dir;
} No;

typedef No *ArvoreB;

ArvoreB criarArvoreVazia(); //Cria uma arvore vazia
ArvoreB construirExemplo(); //Constroi uma arvore  com a sequencia eRd H O W E A S Y Q U E S T I O N
ArvoreB construirArvore(int, ArvoreB, ArvoreB); //Constrori uma arvore a partir dos parametros

void mostrarArvore_eRd(ArvoreB); //Mostra a sequencia eRd Recursiva
void mostrarArvore(ArvoreB); //Mostra a sequencia eRd iterativa
void mostrarArvore_Red(ArvoreB); //Mostra a sequencia Red Recursiva
void mostrarArvore_RedIT(ArvoreB); //Mostra a sequencia Red iterativa
void mostrarArvore_BFS(ArvoreB tree); //Mostra a sequencia BFS iterativa

No *buscarAB(ArvoreB, int); //Busca valor de forma iterativa
No *buscarABIT(ArvoreB, int); //Busca valor de forma recursiva (esta invertido meu deos)

int obterAltura(ArvoreB);
int obterAlturaIT(ArvoreB);

void mostrarPrimeiro_eRd(ArvoreB);
void mostrarUltimo_eRd(ArvoreB);

No *obterPrimeiro(ArvoreB);
No *obterSeguinte_eRd(ArvoreB, int);
No *obterAnterior_eRd(ArvoreB, int);

int contarNoIN(ArvoreB);
int contarNos(ArvoreB);
int contarFolha(ArvoreB);

No* rodarNoEsquerda(No*);
No* rodarNoDireita(No*);
No* rodarDuplaEsquerda(No*);
No* rodarDuplaDireita(No*);

ArvoreB construirArvoreRam(int);

int main(){
	ArvoreB t;
	ArvoreB tree, a, b, c;
//	a = construirArvore(4,NULL,NULL);
//	b = construirArvore(5,NULL,NULL);
	tree = construirArvore(2,NULL,NULL);
	a = construirArvore(6,NULL,NULL);
	b = construirArvore(7,NULL,NULL);
	b = construirArvore(3,a,b);
	tree = construirArvore(1,tree,b);
	
	t = construirExemplo();
	mostrarArvore_eRd(t);
	
	printf("\n\n\n");
	printf("eRd nao recursivo\n\n");
	mostrarArvore(t);
	
	
	printf("\n\n\n");
	printf("Red\n\n\n");
	mostrarArvore_Red(tree);
	printf("\n\n\n");
	printf("Red nao recursivo\n\n\n");
	mostrarArvore_RedIT(tree);
	
	printf("\n\n\n");
	printf("BFS\n");
	mostrarArvore_BFS(tree);
	
	
	printf("\n\nBuscar por chave 7\n");
	No *n;
	n = buscarABIT(tree, 7);
	if(n != NULL)
	  printf("   n->chave = %d ", n->chave);
	  
	int altura = obterAltura(tree);
	printf("\n\n\n");
	printf("Altura de tree: %d", altura);  
	altura = obterAltura(tree);
	printf("\n\n\n");
	printf("Altura de t: %d\n\n", altura); 
	  
	  
	printf(" Primeiro encaminhamento eRd de tree: ");
	mostrarPrimeiro_eRd(tree);  
	printf("\n Ultimo encaminhamento eRd de tree: ");
	mostrarUltimo_eRd(tree);  
	
	n = obterPrimeiro(tree);
    printf("\n\n\nPrimeiro no obtido no caminhamento eRd de tree: %d", n);
	printf("\n chave do no: %d", n->chave);
	
	printf("\n\n\n");
	int noIN, qtdNos, qtdFolhas;
	noIN = contarNoIN(tree);
	printf(" Quantidade de nos interiores em tree: %d ", noIN);
	noIN = contarNoIN(t);
	printf("\n\n Quantidade de nos interiores em t: %d", noIN);

	printf("\n\n\n");
	qtdNos = contarNos(tree);
	printf(" Quantidade de nos em tree: %d ", qtdNos);
	printf("\n\n\n");
	qtdNos = contarNos(t);
	printf(" Quantidade de nos em t: %d ", qtdNos);
	
	printf("\n\n\n");
	qtdFolhas = contarFolha(tree);
	printf(" Quantidade de folhas em tree: %d ", qtdFolhas);
	printf("\n\n\n");
	qtdFolhas = contarFolha(t);
	printf(" Quantidade de folhas em t: %d ", qtdFolhas);
	
	
	
	printf("\n\nRed nao recursivo\n\n\n");
	n = buscarAB(tree, 3);
	mostrarArvore_Red(n);
	
	printf("\n\nRed nao recursivo apos rotacao\n\n\n");
	
	n = rodarNoEsquerda(n); 
	tree->dir = n;
	mostrarArvore_Red(n);
	
	
	No* anterior;
	int value = 1;
	anterior = obterSeguinte_eRd(tree, value);
	if(anterior != NULL) printf("\n\nseguinte de %d em tree = %d", value, anterior->chave);
	else printf("\n\nnao encontrou :(");
}

ArvoreB criarArvoreVazia(){
	ArvoreB tree;
	tree = NULL;
	return tree;
}

ArvoreB construirArvore(int y, ArvoreB e, ArvoreB d){
	ArvoreB tree;
	tree = malloc(sizeof(No));
	
	tree->chave = y;
	tree->esq = e;
	tree->dir = d;
	return tree;
}

ArvoreB construirExemplo(){
	ArvoreB a,b,c,d,e,f;
	a = construirArvore('H',NULL,NULL);
	b = construirArvore('W',NULL,NULL);
	c = construirArvore('O',a,b);
	a = construirArvore('A',NULL,NULL);
	b = construirArvore('Y',NULL,NULL);
	b = construirArvore('S',a,b);
	c = construirArvore('E',c,b);
	a = construirArvore('U',NULL,NULL);
	b = construirArvore('S',NULL,NULL);
	a = construirArvore('E',a,b);
	d = construirArvore('I',NULL,NULL);
	e = construirArvore('N',NULL,NULL);
	f = construirArvore('O',d,e);
	a = construirArvore('T',a,f);
	b = construirArvore('Q', c, a);
	return b;
}

void mostrarArvore_eRd(ArvoreB tree){
	if(tree != NULL){
		mostrarArvore_eRd(tree->esq);
		printf(" %d ", tree->chave);
		mostrarArvore_eRd(tree->dir);
	}
}

void mostrarArvore_Red(ArvoreB tree){
	if(tree != NULL){
		printf(" %d ", tree->chave);
		mostrarArvore_Red(tree->esq);
		mostrarArvore_Red(tree->dir);
	}
}

void mostrarArvore(ArvoreB tree){
	Pilha P;
	ArvoreB p;
	bool ok = FALSE;
	bool vazio = FALSE;
	if(tree != NULL){
		p = tree;
		criarPilhaVazia(&P);
		while(ok == FALSE){
			while(p != NULL){
				pushPilha(&P, p);
				p = p->esq;
			}
			vazio = verificarPilhaVazia(&P);
			if(vazio == FALSE){
				p = acessarTopo(&P);
				printf(" %d ", p->chave);
				popPilha(&P);
				p = p->dir;
			} else ok = TRUE;
				
		}
	} else printf("\nArvore vazia.\n");
}


void mostrarArvore_RedIT(ArvoreB tree){
	Pilha s;
	bool fim = FALSE, vazio = FALSE;
	ArvoreB p;
	if(tree != NULL){
		criarPilhaVazia(&s);
		pushPilha(&s, tree);
		while(fim == FALSE){
			if(vazio == FALSE){
				p = acessarTopo(&s);
				printf(" %d ", p->chave);
				popPilha(&s);
				
				if(p->dir != NULL)
					pushPilha(&s, p->dir);
				if(p->esq != NULL)
					pushPilha(&s, p->esq);	
					p = p->esq;
				vazio = verificarPilhaVazia(&s);
			} else fim = TRUE;		
		}	
	}	
}


void mostrarArvore_BFS(ArvoreB tree){
	Fila f;
	ArvoreB p;
	bool vazio = FALSE;
	if(tree != NULL){
		 criarFilaVazia(&f);
		 pushFila(&f, tree);
		 while(vazio == FALSE){
		 	p = acessarFila(&f);
		 	printf(" %d ", p->chave);
		 	popFila(&f);
		 	if(p->esq != NULL)
		 		pushFila(&f, p->esq);
		 	if(p->dir != NULL)
			 	pushFila(&f, p->dir);	
		 	
		 	vazio = verificarFilaVazia(&f);
		 }
	}
}



No *buscarAB(ArvoreB tree, int y){
	No* item = NULL;
	ArvoreB p;
	Fila f;
	bool vazio = FALSE, fim = FALSE;
	
	if(tree != NULL){
		criarFilaVazia(&f);
		pushFila(&f, tree);
		while(vazio == FALSE && fim == FALSE){
			p = acessarFila(&f);
			if(p->chave == y){
				item = p;
				fim = TRUE;
			}
			else{
				popFila(&f);
				if(p->esq != NULL)
					pushFila(&f, p->esq);
				if(p->dir != NULL)
					pushFila(&f, p->dir);	
				vazio = verificarFilaVazia(&f);	
			}	
		}
	
	return item;
			
	}
}

No *buscarABIT(ArvoreB tree, int y){
	No* item;
	item = NULL;
	ArvoreB p;
	
	if(tree != NULL){
		p = tree;
		if(p->chave == y)
			item = p;
		else{
			item = buscarABIT(p->esq, y);
			item = buscarABIT(p->dir, y);
		}
	}
	
	return item;	
}

int obterAltura(ArvoreB tree){
	int h, he = 0, hd = 0;
	ArvoreB p;	
	
	if(tree != NULL){
		p = tree;
		if(p->esq == NULL && p->dir == NULL)
			h = 0;
		else{
			if(p->esq != NULL) he = obterAltura(p->esq);
			if(p->dir != NULL) hd = obterAltura(p->dir);
			if(he > hd) h = he+1;
			else h = hd+1;
		}		
	} else h = -1;
		
	return h;
}


int obterAlturaIT(ArvoreB tree){
	int h = 0, tam;
	Fila f;
	No* p;
	bool fim;
	if(tree != NULL){
		p = tree;
		criarFilaVazia(&f);
		fim = FALSE;
		pushFila(&f, tree);
		while(fim == FALSE){
			while(verificarFilaVazia(&f) == FALSE){
				p = acessarFila(&f);
				popFila(&f);
				if(p->esq != NULL) pushFila(&f, p->esq);
				if(p->dir != NULL) pushFila(&f, p->dir);
			}
			
			
		//	else fim = TRUE;
			
		}
	} else h = -1;
	
	return h;
	
}

void mostrarPrimeiro_eRd(ArvoreB tree){
	ArvoreB p;
	if(tree != NULL){
		p = tree;
		while(p->esq != NULL)
				p = p->esq;
		printf(" %d ", p->chave);
	}
}

void mostrarUltimo_eRd(ArvoreB tree){
	ArvoreB p;
	if(tree != NULL){
		p = tree;
		while(p->dir != NULL)
			p = p->dir;
		printf(" %d ", p->chave);	
	}
}

No *obterPrimeiro(ArvoreB tree){
	No* pri;
	pri = NULL;
	if(tree != NULL){
		pri = tree;
		while(pri->esq != NULL)
			pri = pri->esq;
	}
	
	return pri;
}

No *obterSeguinte_eRd(ArvoreB tree, int chave){ //obter seguinte do caminhamento eRd
	No* seg = NULL;
	No* p, *aux = NULL;
	Pilha s;
	bool vazio, fim, ok;
	if(tree != NULL){
		criarPilhaVazia(&s);
		p = tree;
		vazio = FALSE;
		fim = FALSE;
		ok = TRUE;
		while(ok == TRUE && fim == FALSE){
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			
			if(aux != NULL){
				seg = acessarTopo(&s);
				fim = TRUE;
			}
			
			vazio = verificarPilhaVazia(&s);
			if(vazio == FALSE){
				p = acessarTopo(&s);
				if(p->chave == chave){
					aux = p;
				}
				
				popPilha(&s);
				p = p->dir;
				
			} else ok = FALSE;
		}
	}
	
	
	
	
	return seg;
}
No *obterAnterior_eRd(ArvoreB tree, int chave){
	No* ant = NULL, *p, *aux = NULL;
	Pilha s;
	bool vazio, fim, ok;
	if(tree != NULL){
		p = tree;
		criarPilhaVazia(&s);
		vazio = FALSE, fim = FALSE, ok = TRUE;
		while(ok == TRUE && fim == FALSE){			
			while(p != NULL){
				pushPilha(&s, p);
				p = p->esq;
			}
			vazio = verificarPilhaVazia(&s);
			if(vazio == FALSE){			
				p = acessarTopo(&s);
				if(p->chave != chave){
					aux = p;
					p = p->dir;
					popPilha(&s);
				} else{
					if(aux != NULL){
						ant = aux;
					}
						fim = TRUE;
				}
			} else ok = FALSE;
		
		}
	}

	return ant;

}

int contarNoIN(ArvoreB tree){
	int cont = 0;
	Fila q;
	ArvoreB p;
	bool vazio = FALSE;
	if(tree != NULL){
		criarFilaVazia(&q);
		pushFila(&q, tree);
		
		while(vazio == FALSE){
			p = acessarFila(&q);
			
			if(p->esq != NULL || p->dir != NULL)
				cont++;
			if(p->esq != NULL){
				pushFila(&q, p->esq);
			}	
			if(p->dir != NULL){
				pushFila(&q, p->dir);
			}			
			popFila(&q);
			vazio = verificarFilaVazia(&q);
		}
	}
	
	return cont;
}

int contarNos(ArvoreB tree){
	int cont = 0;
	int contd = 0, conte = 0;
	ArvoreB p;
	if(tree != NULL){
		p = tree;
		if(p->esq != NULL) conte = contarNos(p->esq);
		if(p->dir != NULL) contd = contarNos(p->dir);
		cont = contd+conte+1;
	}
	
	return cont;
}

int contarFolha(ArvoreB tree){
	int cont = 0;
	int contFE = 0, contFD = 0;
	ArvoreB p;
	if(tree != NULL){
		p = tree;
		if(p->esq == NULL && p->dir == NULL)
			cont = 1;
		else{
			if(p->esq != NULL) contFE = contarFolha(p->esq);
			if(p->dir != NULL) contFD = contarFolha(p->dir);
			cont = contFE+contFD;
		}	
	}
	
	return cont;
}

No *rodarNoEsquerda(No* p){
	No* re;
	No* e;
	No* y;
	re = p;
	if(p != NULL){
		y = p->dir; e = y->esq;	
		if(y != NULL){
			p->dir = e;
			y->esq = p;
			re = y;
		}
	}
	
	return re;
}

No* rodarNoDireita(No* p){
	No* re = p;
	No* d;
	No* y;
	
	if(p != NULL){
		y = p->esq; d = y->dir;
		if(y != NULL){
			p->esq = d;
			y->dir = p;
			re = y;
		}
	}
	
	return re;
}


No* rodarDuplaEsquerda(No* p){
	//Rodar primeiro filho direito para direita
	//Rodar no em questao para esquerda
	No* re = p;
	No* y;
	No* z;
	No* e, * d;
	if(p != NULL){
		y = p->dir;
		if(y != NULL){
			z = y->esq;
			if(z != NULL){
				e = z->esq;
				d = z->dir;
				y->esq = d;
				z->dir = y;
				p->dir = e;
				z->esq = p;
				re = z;
			}
		}
	}
	
	return re;
	
}

No* rodarDuplaDireita(No* p){
	//1° Rodar filho esquerdo para esquerda
	//2° Rodar no em questao para direita
	No* re;
	No* y, * z, * e, * d;
	re = p;
	if(p != NULL){
		y = p->esq;
		if(y != NULL){
			z = y->dir;
			if(z != NULL){
				e = z->esq;
				d = z->dir;
				z->esq = y;
				y->dir = e;
				z->dir = p;
				p->esq = d;	
				re = z;
			}
		}
	}
	
	return re;
}


ArvoreB construirArvoreRam(int n){
	ArvoreB tree;
	srand((int) time(NULL));
	int num = rand();
	if(n == 0)
		tree = NULL;
	else{
		
	}	
}
