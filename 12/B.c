#include <stdio.h>
//単一始点最短経路

#define N 100
#define INFTY 100000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,G[N][N],d[N];//d最短距離
void dijkstra();

int main(){
    int k,c,u,v;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G[i][j] = INFTY;
        }
    }

    for(int i=0; i<n; i++){
        scanf("%d%d",&u,&k);
        for(int j=0; j<k; j++){
            scanf("%d%d",&v,&c);
            G[u][v] = c;
        }
    }

    dijkstra();

    for(int i=0; i<n; i++){
        if(d[i] == INFTY) d[i] = -1;
        printf("%d %d\n",i,d[i]);
    }
    return 0;
}

void dijkstra(){
    int minv,color[N];

    for(int i=0; i<n; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    color[0] = GRAY;

    while (1)
    {
        minv = INFTY;
        int u = -1;
        for(int i=0; i<n; i++){
            if(minv > d[i] && color[i] != BLACK){
                u = i; 
                minv = d[i]; //minv(最小の辺)
            }
        }

        if(u == -1) break;
        color[u] = BLACK;

        for(int v = 0; v<n; v++){
            if(color[v] != BLACK && G[u][v] != INFTY){
                if(d[v] > d[u] + G[u][v]){
                    d[v] = d[u] + G[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }
    
}