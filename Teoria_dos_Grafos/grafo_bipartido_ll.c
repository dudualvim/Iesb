#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
    int valor;
    struct Registro *prox;
} Registro;

typedef struct Lista {
    int qntd;
    Registro *inicio;
} Lista;

typedef struct Grafo{
    int cor;
    Lista *lista_adj;
    int tam_lista;
} Grafo;

typedef enum {Branco, Cinza, Preto} CORES;

int qntd = 0;

Lista *iniciarLista(){
    Lista *l = (Lista*)calloc(1, sizeof(Lista));
    return l;
}

Registro *iniciarRegistro(){
    Registro *r = (Registro*)calloc(1, sizeof(Registro));
    return r;
}

int inserirOrdenadoLista(Lista *l, int x){
    if(l == NULL){
        return 0;
    }
    Registro *r, *aux = NULL, *ant = NULL;
    r = iniciarRegistro();  
    r->valor = x;
    if(l->inicio == NULL){
        l->inicio = r;
    } else {
        int inserido = 0;
        aux = l->inicio;
        while(aux != NULL && !inserido){
            if(aux->valor == r->valor){
                return 0;
            } 
            if(aux->valor < r->valor){
                ant = aux;
                aux = aux->prox;    
            } else {
                if(ant == NULL){
                    l->inicio = r;   
                } else {
                    ant->prox = r;
                }
                r->prox = aux;
                inserido = 1;
            }
        }
        if(!inserido){
            ant->prox = r;
            inserido = 1;
        }
    }
    l->qntd++;
    return 1;
}


void mostrarLista(Lista *l){
    Registro *aux;

    if(l == NULL){
        printf("Lista vazia");
        return;
    }

    if(l->inicio == NULL){
        printf("Lista vazia");
        return;
    }

    aux = l->inicio;
    while(aux != NULL){
        printf(" -> %d", aux->valor);
        aux = aux->prox;
    }
}

void dfs(Grafo *g, int raiz){
    Registro *aux;
    
    g[raiz].cor = Cinza;
    qntd++;

    if(g[raiz].lista_adj == NULL){
        return;
    }
    
    aux = g[raiz].lista_adj->inicio;

    while(aux != NULL){
        if(g[aux->valor].cor == Branco){
            dfs(g, aux->valor);
        }
        aux = aux->prox;
    }
    g[raiz].cor = Preto;
}

void mostrarListaVertices(Grafo *g, int tam){
    for(int i = 0; i < tam; i++){
        if(g[i].lista_adj != NULL){
            printf("Lista de Adjacências do nó: %d", i);
            mostrarLista(g[i].lista_adj);
        }
    }
}

void push(Grafo *g, int x){
    if(g->lista_adj == NULL){
        g->lista_adj = iniciarLista();
    }
    inserirOrdenadoLista(g->lista_adj, x);
}

int main(){
    int qntd_vertices, qntd_arestas;
    int i, a, b, qntd_cc = 0, qntd_garotas;

    Grafo *g;
    int *garotas;
    
    printf("Digite a quantidade de vértices: ");
    scanf("%d", &qntd_vertices);

    g = (Grafo*)calloc(qntd_vertices+1, sizeof(Grafo));

    for(i = 0; i < qntd_vertices-1; i++){
        scanf("%d %d", &a, &b);
        push(&g[a], b);
        push(&g[b], a);
    }

    dfs(g, 1);

    for(int i = 0 ; i < qntd_vertices; i++){
        if(g[i].cor == Branco){
            printf("%d: Branco\n", i);
        } else if (g[i].cor == Cinza){
            printf("%d: Cinza\n", i);
        } else if(g[i].cor == Preto){
            printf("%d: Preto\n", i);
        }
    }

    return 0;
}