#include <stdlib.h>
#include <stdio.h>

typedef struct Grafo {
    int visitado;
    int lista_adj[1000];
    int tam_lista;
} Grafo; 

int cont = 0;

void dfs(Grafo *g, int raiz){
    g[raiz].visitado = 1;
    
    cont++;

    for(int i = 0; i < g[raiz].tam_lista; i++){
        if(g[g[raiz].lista_adj[i]].visitado == 0){
            dfs(g, g[raiz].lista_adj[i]);
        }
    }
}

int main(){
    int qntd_vertice, qntd_arestas, a, b, i, qntd_cc_vert = 1, qntd_cc = 0;;
  
    scanf("%d %d", &qntd_vertice, &qntd_arestas); // V = Funcionarios, A = Relacionamentos
    
    Grafo *g = (Grafo*)calloc(qntd_vertice+1, sizeof(Grafo));

    for(i = 0; i < qntd_arestas; i++){
        scanf("%d %d", &a, &b);
        g[a].lista_adj[g[a].tam_lista] = b;
        g[a].tam_lista++;
        g[b].lista_adj[g[b].tam_lista] = a;
        g[b].tam_lista++;
    }

    for(i = 1; i <= qntd_vertice; i++){
        if(g[i].visitado == 0){
            cont = 0;
            dfs(g, i);
            qntd_cc++;
            qntd_cc_vert *= cont;
        }
    }

    printf("\n%d %d\n", qntd_cc, qntd_cc_vert);

    return 0;
}