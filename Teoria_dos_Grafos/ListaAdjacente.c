#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertice;
    struct Node *prox;
} node;

int main()
{
    node *vetor = malloc(sizeof(node) * 26);
    for (int i = 1; i < 26; i++)
    {
        node no;
        no.prox = NULL;
        vetor[i] = no;
    }

    int N, i, a, b;

    printf("Digite um Valor N: ");
    scanf("%d", &N);

    printf("Digite os seus %d pares de 1 a 25: ", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);

        node *noB = malloc(sizeof(node));
        noB->vertice = b;
        noB->prox = vetor[a].prox;
        vetor[a].prox = noB;

        node *noA = malloc(sizeof(node));
        noA->vertice = a;
        noA->prox = vetor[b].prox;
        vetor[b].prox = noA;
    };

    for (int i = 1; i < 26; i++)
    {
        printf("Vertice %d -> ", i);
        node *aux = vetor[i].prox;
        while (aux)
        {
            if (!aux->prox)
                printf("%d", aux->vertice);
            else
                printf("%d -> ", aux->vertice);
            aux = aux->prox;
        }
        printf("\n");
    }

    free(vetor);

    return 0;
}