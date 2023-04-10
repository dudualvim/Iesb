#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Grafo {
    int visitado;
    int cor;
    int lista_adj[1000];
    int tam_lista;
} Grafo;

bool dfs(Grafo *g, int raiz, int cor){
    g[raiz].visitado = 1;
    g[raiz].cor = cor;

    for(int i = 0; i < g[raiz].tam_lista; i++){
        if(g[g[raiz].lista_adj[i]].visitado == 0){
            if(!dfs(g, g[raiz].lista_adj[i], cor * -1)){
                return false;
            }
        } else if (g[raiz].cor == g[g[raiz].lista_adj[i]].cor){
            return false;
        }
    }

    return true;
}

int main(){
    int a, b, qntd_vertices, qntd_arestas, j = 0, k = 0;

    scanf("%d %d", &qntd_vertices, &qntd_arestas);

    Grafo *g = (Grafo*)calloc(qntd_vertices+1, sizeof(Grafo));

    for(int i = 0; i < qntd_arestas; i++){
        scanf("%d %d", &a, &b);
        g[a].lista_adj[g[a].tam_lista] = b;
        g[a].tam_lista++;
        g[b].lista_adj[g[b].tam_lista] = a;
        g[b].tam_lista++;
    }   

    if(dfs(g, 1, 1)){
        printf("Não há insetos suspeitos\n");
    } else {
        printf("Há insetos suspeitos\n");
    }
   
    return 0;
}