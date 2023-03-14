#include <stdio.h>
//グラフ

int main(){
    int n,u,k,v;
    int G[100][100];

    scanf("%d",&n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        scanf("%d%d",&u,&k);
        u--;
        for(int j=0; j<k; j++){
            scanf("%d",&v);
            v--;
            G[u][v] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j) printf(" ");
            printf("%d",G[i][j]);
        }
        printf("\n");
    }
    return 0;
}