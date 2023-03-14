#include <stdio.h>
//最小全域木

#define N 100
#define INFTY 200000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,G[N][N];

int prim(void);

int main(){
    int x;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&x);
            if(x == -1) G[i][j] = INFTY;
            else G[i][j] = x;
        }
    }

    printf("%d\n",prim());

    return 0;
}

int prim(){
    int u,minv,d[N],p[N],color[N];

    for(int i=0; i<n; i++){
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while (1)
    {
        minv = INFTY;
        u = -1;
        for(int i=0; i<n; i++){
            if(minv > d[i] && color[i] != BLACK){
                u = i;
                minv = d[i];
            }
        }
        if(u == -1) break;
        color[u] = BLACK;
        for(int v=0; v<n; v++){
            if(color[v] != BLACK && G[u][v] != INFTY){
                if(d[v] > G[u][v]){
                    d[v] = G[u][v];
                    p[v] = u;  //最小のところをマーク(頂点の親)
                    color[v] = GRAY;
                }
            }
        }
    }

    int sum =0; 
    for(int i=0; i<n; i++){
        if(p[i] != -1) sum += G[i][p[i]];
    }

    return sum;
}