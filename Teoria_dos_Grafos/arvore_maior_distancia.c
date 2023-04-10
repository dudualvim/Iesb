#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo {
    int visitado;
    int distancia;
    int lista_adj[1000];
    int tam_lista;
} Grafo;

void dfs(Grafo *g, int raiz, int distancia){
    g[raiz].visitado = 1;
    g[raiz].distancia = distancia;

    for(int i = 0; i < g[raiz].tam_lista; i++){
        if(g[g[raiz].lista_adj[i]].visitado == 0){
            g[raiz].distancia++;
            dfs(g, g[raiz].lista_adj[i], distancia+1);
        }
    }
}

int main(){
    int qntd_vertices = 0, a = 0, b = 0, i = 0;

    scanf("%d", &qntd_vertices);

    Grafo *g = (Grafo*)calloc(qntd_vertices+1, sizeof(Grafo));

    for(i = 0; i < qntd_vertices-1; i++){
        scanf("%d %d", &a, &b);
        g[a].lista_adj[g[a].tam_lista] = b;
        g[a].tam_lista++;
        g[b].lista_adj[g[b].tam_lista] = a;
        g[b].tam_lista++;
    }

    dfs(g, 1, 0);

    int aux = g[0].distancia;
    int raiz = 0;
    for(i = 0; i < qntd_vertices; i++){
        if(g[i].distancia > aux){
            aux = g[i].distancia;
            raiz = i;
        }
    }

    dfs(g, raiz, aux);

    int auxb = g[0].distancia;
    int raizb = 0;
    for(i = 0; i < qntd_vertices; i++){
        if(g[i].distancia > aux){
            auxb = g[i].distancia;
            raizb = i;
        }
    }

    printf("%d\n", raiz);
    
    return 0;
}