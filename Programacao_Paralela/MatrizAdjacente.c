#include <stdio.h>
#include <stdlib.h>
int matriz[50][50];

void GRAPH_Insert1(int a, int b){
    matriz[a][b]= 1;
    matriz[b][a]= 1;

}



int main(){

    int N, a, b,i,j;

    printf("Digite um Valor N: ");
    scanf("%d", &N);

    printf("Digite os seus %d pares: ", N);
    for(i=0; i<N;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        GRAPH_Insert1(a,b);
    };

    for(i=0; i<50;i++){
        for(j=0; j<50;j++){
            printf("%d", matriz[i][j]);
        };
        printf("\n");
    };

    return 0;
};