#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int distancia;
    int lista_adj[1000];
    int tam_lista_adj;
    int cor;
}vertice;

typedef enum { branco , cinza , preto } cor;

void mostrar_tudo (vertice * vertices, int qtd_vertices);
void dfs(vertice * vertices,int raiz);

int main()
{
    int qtd_vertices, qtd_arestas;
    int i,a,b,qtd_cc=0;
    vertice * vertices;
    scanf("%d",&qtd_vertices);



    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    for(i=0;i<qtd_vertices-1;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }

    dfs(vertices,1);

    for(int i = 0 ; i < qtd_vertices; i++){
        if(vertices[i].cor == branco){
            printf("Vertice %d: Branco\n", i);
        } else if (vertices[i].cor == cinza){
            printf("Vertice %d: Cinza\n", i);
        } else if(vertices[i].cor == preto){
            printf("Vertice %d: Preto\n", i);
        }
    }

    return 0;
}


void mostrar_tudo (vertice * vertices, int qtd_vertices)
{
    int i,j;

    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Vertice: %d",i);
        printf("\n Lista de adjacencias: ");

        for(j=0;j<vertices[i].tam_lista_adj;j++)
        {
            printf("%d ",vertices[i].lista_adj[j]);
        }
    }
}

void dfs(vertice * vertices,int raiz)
{
    int i;

    vertices[raiz].cor = cinza;

    if (vertices[raiz].lista_adj == NULL)
    {
        return;
    }



    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].cor == branco)
        {
            dfs(vertices, vertices[raiz].lista_adj[i]);
        }
    }
    vertices[raiz].cor = preto;
}