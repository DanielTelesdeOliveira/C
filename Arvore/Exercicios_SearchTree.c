/*
  Arquivo: Exercicio_SearchTree.c
  Autor: Lisbete Madsen Barbosa
  Date: 11/09/24 09:27
  Descrição: Este programa implementa as operações elementares de
  uma Árvore Binária de Busca - criação, busca, inserção e remoção.
  Inserir não aceita duplicatas. Remover com as duas versões.
  Implementa também as funções obter Pai, ancestral,determinarAltura e dfs iterativo.
  Implementa ancestral recursivo e outros.
*/
#include <stdio.h>
#include <stdlib.h>  /* a constante NULL está nesta biblioteca */
#include "PilhaPointer.h"
#include "FilaPointer.h"
#include "Booleano.h"

typedef struct No{
        int chave;
        char satelite;
        struct No * esq; 
        struct No * dir;
} No;

typedef No* ArvoreBB;

//protótipos No
void mostrarNo(No*);
No* criarNo(int,char);

// protótipos ArvoreBB
ArvoreBB criarArvoreBB( );		// criar árvore vazia
ArvoreBB construirExemplo();	//construir uma árvore 

bool verificarArvoreVazia(ArvoreBB);	// devolver TRUE se a árvore é vazia

void mostrarArvore(ArvoreBB);		// eRd recursivo
void mostrarArvore_eRd(ArvoreBB);	// eRd iterativo
void mostrarArvoreRed(ArvoreBB);	// Red recursivo
void mostrarArvore_edR(ArvoreBB);	// edR recursivo
void mostrarArvoreBFS(ArvoreBB);	// caminhamento por nivel

No* buscarNo(ArvoreBB, int);		// buscar iterativo
No* buscarNoRec(ArvoreBB, int);		// buscar recursivo

int determinarAltura(ArvoreBB);		//obter altura da árvore
No* obterPai(ArvoreBB, No*);		// obter pai de um nó

No* obterAncestral(ArvoreBB, No*, No*);		//obter ancestral comum mais próximo ITERATIVO
No* obterAncestralRec(ArvoreBB, No*, No*);	//obter ancestral comum mais próximo RECURSIVO


bool verificarBinaria(ArvoreBB);			// devolver TRUE se árvore é binária de busca

void mostrarPrimeiro(ArvoreBB);		// mostrar elemento que tem a menor chave
No* obterPrimeiro(ArvoreBB);		// obter referência do menor elemento
void mostrarUltimo(ArvoreBB);		// mostrar elemento que tem a maior chave

No* select(ArvoreBB,int);			// obter referência do elemento de ordem k
int rank(ArvoreBB, int);			// obter ordem de uma chave y

int contarMaiores(ArvoreBB,int);	// devolver quantidade de maiores do que a chave y
No *procura(ArvoreBB, int);			// exercício Feofiloff - processo de busca

No* obterAnterior(ArvoreBB,No*);	// obter referência do elemento anterior 
No* obterSucessor(ArvoreBB,No*);	// obter referência do elemento seguinte 

void criarListaBB(ArvoreBB, int K[]);	// armazenar chaves em um array, na ordem crescente

ArvoreBB inserirNo(ArvoreBB, No*);		// inserir um novo elemento se não é duplicata - ITERATIVO

ArvoreBB removerNo(ArvoreBB, int);		// remover o elemento que tem chave y
ArvoreBB removerRaiz(ArvoreBB);			// remover a raiz da árvore

No* destruirArvore(ArvoreBB);		// tornar a árvore vazia

int main(){
	No* node, *fa, *ant, *anc, *node2;
    ArvoreBB a;
    a = criarArvoreBB();
    node = criarNo(8, 'A');
    a = inserirNo(a, node);
     node2 = node;
    
    
    node = criarNo(4, 'B');
    a = inserirNo(a, node);
    
    
    
    node = criarNo(10, 'C');
    a = inserirNo(a, node);
    
    node = criarNo(2, 'D');
    a = inserirNo(a, node);
    
    node = criarNo(6, 'E');
    a = inserirNo(a, node);
    
    
    node = criarNo(9, 'F');
    a = inserirNo(a, node);
   
    
    node = criarNo(11, 'G');
    a = inserirNo(a, node);
    
    node = criarNo(1, 'H');
    a = inserirNo(a, node);
    
    node = criarNo(3, 'I');
    a = inserirNo(a, node);
    
    node = criarNo(5, 'J');
    a = inserirNo(a, node);
    
    node = criarNo(7, 'J');
    a = inserirNo(a, node);
   // mostrarArvore_edR(a);
    bool abb;
    abb = verificarBinaria(a);
	
	printf("\n\nValor de abb: %d\n", abb);
	
	
    fa = obterPai(a, node);
	if(fa != NULL)
		printf("pai de %d eh %d", node->chave, fa->chave);
		
	ant = obterAnterior(a, node);
	if(ant != NULL)
		printf("\nAnterior: %d", ant->chave);
	
	a = removerRaiz(a);
	printf("\n\nArvore apos ter a raiz removida: \n");
	mostrarArvore(a);	
	//anc = obterAncestral(a, node, node2);
	//if(anc != NULL)
		//printf("\nAncestral: %d", anc->chave);	
	//destruirArvore(a);
	//printf("Mostrar arvore apos destruir: ");
	//mostrarArvore(a);

	int z;
    //mostrarArvore_edR
    /*a = construirExemplo();   
	printf("\n BFS - por nivel: \n"); mostrarArvoreBFS(a); printf("\n\n");
    printf("\n Caminhamento eRd iterativo e recursivo: \n");
	mostrarArvore_eRd(a); printf("\n\n");
    mostrarArvore(a);
    
	z = 40;	     
    printf("\n Remover %d \n",z);
    a = removerNo(a,z);
	printf("\n BFS - por nivel: \n"); mostrarArvoreBFS(a); printf("\n");
    printf("\n Caminhamento eRd : \n");  mostrarArvore(a); 	
    
	printf("\n");
 	z = 10;	     
    printf("\n Remover %d \n",z);
    a = removerNo(a,z);
	printf("\n BFS - por nivel: \n"); mostrarArvoreBFS(a); printf("\n");
    printf("\n Caminhamento eRd : \n");  mostrarArvore(a); 	  
	
	printf("\n");
 	z = 20;	     
    printf("\n Remover %d \n",z);
    a = removerNo(a,z);
	printf("\n BFS - por nivel: \n"); mostrarArvoreBFS(a); printf("\n");
    printf("\n Caminhamento eRd : \n");  mostrarArvore(a); 
		
    printf(" \n \n");*/
    return 0;
}

// implementações das funções de No       
void mostrarNo(No *p){
     if (p != NULL){ printf("  %d %c ",p->chave, p->satelite);}
     else printf("no inexistente \n\n");
     }

No* criarNo(int c, char ch){
   No* aux;
   aux = (struct No*) malloc(sizeof(struct No));
   aux->chave = c; aux->satelite = ch;
   aux->esq = NULL;  aux->dir = NULL;
   return aux;    
   }
               
// implementaçóes das funções de ArvoreBB   

ArvoreBB criarArvoreBB( ){
    ArvoreBB ap;
    ap = NULL;
    return ap;
}

ArvoreBB construirExemplo(){
	ArvoreBB a;
		
	return a;
}         

bool verificarArvoreVazia(ArvoreBB ap){
    bool ok;
    if (ap == NULL) ok = TRUE; else ok = FALSE;
    return ok;
}

void mostrarArvore(ArvoreBB ap){   // varredura eRd
    if (ap != NULL){
        mostrarArvore(ap->esq);
        mostrarNo(ap);
        mostrarArvore(ap->dir);
    }      
}
 
void mostrarArvoreRed(ArvoreBB ap){
    if (ap != NULL){
    	mostrarNo(ap);
        mostrarArvoreRed(ap->esq);
        mostrarArvoreRed(ap->dir);
    }  		
}
 
void mostrarArvore_edR(ArvoreBB ap){
	if (ap != NULL){	
        mostrarArvore_edR(ap->esq);
        mostrarArvore_edR(ap->dir);
        mostrarNo(ap);
    }  		
}

void mostrarArvoreBFS(ArvoreBB ap){
    No *p, *e, *d;
    Fila f;
    if (ap != NULL){
        p = ap;
        criarFilaVazia(&f);
        pushFila(&f,p);
        do {
            p = acessarFila(&f); mostrarNo(p); popFila(&f);
            e = p->esq;
            if (e != NULL) pushFila(&f,e);
            d = p->dir;
            if (d != NULL) pushFila(&f,d);
        } while (verificarFilaVazia(&f) == 0);
    }
}
     
void mostrarArvore_eRd(ArvoreBB ap){
    Pilha s;  No *p;  int fim;
    if (ap != NULL){
        criarPilhaVazia(&s); fim = 0; p = ap;    
        do {
            while (p != NULL){ pushPilha(&s,p);  p = p->esq; }
            if (verificarPilhaVazia(&s) == 0){
                p = acessarTopo(&s);  mostrarNo(p); 
	   			popPilha(&s);	p = p->dir;
            } else fim = 1;
        } while (fim == 0);
    }
}

ArvoreBB inserirNo(ArvoreBB ap, No* novo){
    No* p, *ant;
    if(ap != NULL){
    	p = ap;
    	while(p != NULL){
    		ant = p;
    		if(novo->chave > p->chave)
    			p = p->dir;
    		else
				p = p->esq;	
		}
		
		if(p == NULL){
			if(novo->chave > ant->chave)
				ant->dir = novo;
			else
				ant->esq = novo;
		}
				
	} else ap = novo;
	
    return ap;
}

 
No* destruirArvore(ArvoreBB ap){   // varredura edR 
	No* p, *aux;
	Pilha s1, s2;
	bool fim = FALSE;
	p = ap;
	if(p != NULL){
		criarPilhaVazia(&s1);
		criarPilhaVazia(&s2);
		pushPilha(&s1, p);
		
		while(fim == FALSE){
			aux = acessarTopo(&s1);
			popPilha(&s1);
			pushPilha(&s2, aux);
			
			if(aux->esq != NULL){
				pushPilha(&s1, aux->esq);
			}
			
			if(aux->dir != NULL){
				pushPilha(&s1, aux->dir);
			}
			
			if(verificarPilhaVazia(&s1) == TRUE)
				fim = TRUE;
		}
		while(verificarPilhaVazia(&s2) == FALSE){	    
			p = acessarTopo(&s2);
			popPilha(&s2);
			free(p);
		}	
	}

	return NULL;    
}

No* buscarNo(ArvoreBB ap, int valor){
    No *p;
	p = ap;
	if(p != NULL){
		while(p != NULL && p->chave != valor){
			if(valor > p->chave)
				p = p->dir;
			else
			    p = p->esq;	
		}
	}
    return p;
}

No* buscarNoRec(ArvoreBB ap, int valor){
	No *p;
	p = ap;
	if(p != NULL){
		if(valor < p->chave)
			p = buscarNoRec(p->esq, valor);
		else
			p = buscarNoRec(p->dir, valor);	
	}

	return p;
}

No* obterPrimeiro(ArvoreBB ap){
	No*p;
	p = ap;
	if (ap != NULL) {
		p = ap;
		while (p->esq != NULL){ p = p->esq;	}
	}
	return p;
}

void mostrarPrimeiro(ArvoreBB ap){
	No*p;
	if (ap == NULL) printf("\n arvore vazia \n");
	else {
		p = ap;
		while (p->esq != NULL){
			p = p->esq;
		}
		printf("\n primeiro = %d \n", p->chave);
	}
}

void mostrarUltimo(ArvoreBB ap){
	No*p;
	if (ap == NULL) printf("\n arvore vazia \n");
	else {
		p = ap;
		while (p->dir != NULL){
			p = p->dir;
		}
		printf("\n ultimo = %d \n", p->chave);
	}
}
            
No* obterAnterior(ArvoreBB ap, No* q){		
	No *anterior = NULL;
	No* p, *aux = NULL;
	p = ap;
	Pilha s;
	bool vazio = FALSE;
	bool fim = FALSE;
	if(p != NULL){
		if(p->chave != q->chave){ //Nao e a raiz
			criarPilhaVazia(&s);
			while(fim == FALSE && vazio == FALSE){
				while(p != NULL){
					pushPilha(&s, p);
					p = p->esq;
				}
				
				vazio = verificarPilhaVazia(&s);
				if(vazio == FALSE){
					p = acessarTopo(&s);
					if(p->chave == q->chave){
						anterior = aux;
						fim = TRUE;
					}
						aux = p;
						p = p->dir;
						popPilha(&s);
				}	
			}
		}
	}
	return anterior;
}

No* obterSucessor(ArvoreBB ap, No* q){		
	No *sucessor;
	
	return sucessor;
}

No *procura(ArvoreBB ap, int y){		// exercício FEOFILOFF 
	while ((ap!= NULL) && (ap->chave > y)) ap = ap->esq;
	while ((ap!= NULL) && (ap->chave < y)) ap = ap->dir;
	return ap;
}

int contarMaiores(ArvoreBB ap,int z){
	int n;
	No* p;
	p = ap;
	if(p != NULL){
		while(p != NULL && p->chave != z){
			if(z > p->chave)
				p = p->dir;
			else
				p = p->esq;	
		}
		if(p != NULL){
			while(p->dir != NULL){
				n++;
				p = p->dir;
			}
		}
	}
	return n;
}

No* select(ArvoreBB ap, int k){
	No* pk;
	
	return pk;
}


int rank(ArvoreBB ap, int y){
	int c;
	
	return c;
}


bool verificarBinaria(ArvoreBB ap){ 
	bool BB = TRUE, fim = FALSE; 
	Pilha s;
	No* p, *fe, *fd;
	p = ap;
	if(p != NULL){
		criarPilhaVazia(&s);
		pushPilha(&s, p);
		
		while(fim == FALSE && BB == TRUE){
			if(p->esq != NULL){
				fe = p->esq;
				if(fe->chave < p->chave)
					pushPilha(&s, fe);
				else 
					BB = FALSE;	
			}
			
			if(p->dir != NULL){
				fd = p->dir;
				if(fd->chave > p->chave)
					pushPilha(&s, fd);
				else
					BB = FALSE;			
			}		
			
			if(verificarPilhaVazia(&s) == FALSE){
				p = acessarTopo(&s);
				popPilha(&s);
			}
			else
				fim = TRUE;
		}
	}
	return BB;
}

void criarListaBB(ArvoreBB ap, int K[]){   // varredura eRd

}


int determinarAltura(ArvoreBB ap){
    int h,he,hd;
    No *p;
    if (ap == NULL) h = -1; // altura da Árvore vazia
    else {
         he = determinarAltura(ap->esq); 
         hd = determinarAltura(ap->dir); 
         if (he > hd) h = he + 1;
         else h = hd + 1 ;
     }
    return h;
}

No* obterAncestral(ArvoreBB abb, No* n1, No* n2) {//Obtem um ancestral comum entre dois nos
    No* ancestral = NULL;
    bool fim = FALSE;

    if(abb!=NULL) {
        ancestral = abb;
        do {    
            if(ancestral == n1 || ancestral == n2) {
                fim = TRUE;
            }

            else {
                if(ancestral->chave > n1->chave && ancestral->chave > n2->chave) ancestral = ancestral->esq;
                else if(ancestral->chave < n1->chave && ancestral->chave < n2->chave) ancestral = ancestral->dir;
                else fim = TRUE;
            }

        }while(fim == FALSE);
    }

    return ancestral;
}

No* obterAncestralRec(ArvoreBB ap, No* p, No* q){
    No *anc;

    return anc;
}

No* obterPai(ArvoreBB ap, No *p){
    No *pai;
	No* a, *aux;
	a = ap;
	pai = NULL;
	bool fim = FALSE;
	if(a != NULL){
		if(a->chave != p->chave){ //Nao e a raiz
			while(a != NULL && a->chave != p->chave){
				aux = a;
				if(p->chave > a->chave)
					a = a->dir;
				else a = a->esq;	
			}
			
			if(a != NULL){
				pai = aux;
			}
		}
	}
		
    return pai;
}

ArvoreBB removerRaiz(ArvoreBB raiz){
    No *q, *pai, *fp;
    No* p;
    q = raiz;
    int nf;
    if(q != NULL){
    	nf = 0;
    	if(q->esq == NULL)
    		p = q->dir;
    	else if(q->dir == NULL)
				p = q->esq;
		else
			nf = 2;
		
		if(nf == 0){
			raiz = p;
			free(q);
		} else{
								
    	if(q->esq != NULL){
    			pai = q;
	    		p = q->esq; //Procura o maior dos menores
	    		while(p != NULL && p->dir != NULL){
	    			pai = p;
	    			p = p->dir;
				}
				
				fp = p->esq;
				
				 if(pai->esq != p)
				   pai->dir = fp; //O pai de p nao eh a raiz
            	else 
					pai->esq = fp;

            	raiz->chave = p->chave;
            	raiz->satelite = p->satelite;
				free(p);
			}
		}
	}
    return q;              
}

ArvoreBB removerNo(ArvoreBB ap, int valor){
	No *raiz; 
  	No *p, *fa, *m, *ba, *filho,*fm;
	int nf;
	if(ap != NULL){
		raiz = ap;
		p = raiz;
		nf = 0; //Ou tem 2 filhos, ou tem 1, ou nao tem filhos
		
		while(p != NULL && p->chave != valor){
			fa = p;
			if(valor > p->chave)
				p = p->dir;
			else
				p = p->esq;	
		}
		
		if(p != NULL){
			if(p->esq == NULL) 
				filho = p->dir;
			else if(p->dir == NULL)
					filho = p->esq;
			else
				nf = 2;	
				
			if(fa == NULL && nf == 0){ //E a raiz
				ap = filho;
				free(p);
			} else if(fa != NULL && nf == 0){ //Folha ou unico filho
				if(p == fa->esq){ //Redirecionar filho esquerdo do pai
					fa->esq = filho;
				} else{ //Redirecionar filho direito do pai
					fa->dir = filho;
				}
				
				free(p);
			} else{ //Tem 2 filhos
				m = p->esq; //Ira procurar o maior dos menores
				ba = p;
				while(m->dir != NULL){
					ba = m; // Anterior a m
					m = m->dir;
				}
				
				fm = m->esq; //Salva o filho esquerdo de m
				
				if(ba != p)
					ba->dir = fm;
				else
					ba->esq = fm;	
					
				p->chave = m->chave;
				p->satelite = m->satelite;
				free(m);
			}		
			
		}
	}
  	return raiz;
}

