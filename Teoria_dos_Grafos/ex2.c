#include <stdio.h>
#include <stdlib.h>


typedef struct vertice
{
    int visitado;
    struct lista *ListAdjacente;
} vertice;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

typedef struct lista
{
    int quantidade;
    struct registro *comeco;
} lista;


int quantidade=0;
void push(vertice *v, int x);
void MostrarListaVertices(vertice *v, int tam);
void dfs(vertice * vertices , int x);
void MostrarLista(lista *l);
int IncluindoOrdenado(lista *l, int x);
registro *AlocandoRegistro();
lista *AlocandoLista();


int IncluindoOrdenado(lista *l, int x){
    if (l == NULL){
        return 0;
    }
    registro *novo, *aux = NULL, *ant = NULL;
    novo = AlocandoRegistro();
    novo->valor = x;

    if (l->comeco == NULL){
        l->comeco = novo;
    }
    else{
        int inserido = 0;
        aux = l->comeco;
        while (aux != NULL && !inserido){
            if (aux->valor == novo->valor){
                return 0;
            }
            if (aux->valor < novo->valor){
                ant = aux;
                aux = aux->prox;
            }
            else{
                if (ant == NULL){
                    l->comeco = novo;
                }
                else{
                    ant->prox = novo;
                }
                novo->prox = aux;
                inserido = 1;
            }
        }
        if (!inserido){
            ant->prox = novo;
            inserido = 1;
        }
    }
    l->quantidade++;
    return 1;
}

void dfs(vertice * vertices , int x){
    registro * aux;
    vertices[x].visitado=1;
    quantidade++;

    if (vertices[x].ListAdjacente==NULL){
        return;
    }
    aux = vertices[x].ListAdjacente->comeco;

    while(aux!=NULL){
        if (vertices[aux->valor].visitado==0){
            dfs(vertices,aux->valor);
        }
        aux = aux->prox;
    }

}


lista *AlocandoLista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *AlocandoRegistro(){
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void MostrarListaVertices(vertice *v, int tam){
    int i;

    for (i = 0; i < tam; i++){
        if (v[i].ListAdjacente != NULL){
            MostrarLista(v[i].ListAdjacente);
        }
    }
}

void push(vertice *v, int x){
    if (v->ListAdjacente == NULL){
        v->ListAdjacente = AlocandoLista();
    }
    IncluindoOrdenado(v->ListAdjacente, x);
}


void MostrarLista(lista *l){
    registro *aux;

    if (l == NULL){
        printf("\n Lista vazia");
        return;
    }

    if (l->comeco == NULL){
        printf("\n Lista vazia");
        return;
    }

    aux = l->comeco;
    while (aux != NULL){
        printf("\n -> %d", aux->valor);
        aux = aux->prox;
    }
}

int main(int *argc, char *argv[]){
    int qtdVertices, qtdArestas,i,a,b,cont=0;
    int aux=1;

    vertice * vertices;
    scanf("%d %d",&qtdVertices,&qtdArestas);

    vertices = (vertice*)calloc(qtdVertices+1,sizeof(vertice));


    for(i=1;i<=qtdArestas;i++){
        scanf("%d %d",&a,&b);
        push(&vertices[a],b);
        push(&vertices[b],a);
        
    }

    for(i=1;i<=qtdVertices;i++){
        if (vertices[i].visitado==0){
            dfs(vertices,i);
            aux = aux * quantidade;
            cont++;
            quantidade=0;
        }
    }

    printf("%d\n",cont);
    return 0;
}


