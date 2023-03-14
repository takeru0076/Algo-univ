#include <stdio.h>
//深さ優先探索
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N],color[N],d[N],f[N],tt,nt[N]; //タイムスタンプd[],f[]
//d＝最初に発見した発見時刻、f＝vの隣接リストを調べ終えた完了時刻を記録

void dfs_visit(int);
void dfs();

int main(){
    int u,k,v,i,j;

    scanf("%d",&n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            M[i][j] = 0;
        }
    }

    for(i=0; i<n; i++){
        scanf("%d%d",&u,&k);
        u--;
        for(j=0; j<k; j++){
            scanf("%d",&v);
            v--;
            M[u][v] = 1;
        }
    }
    dfs();
    return 0;
}

//再帰関数による深さ優先探索
void dfs_visit(int u){
    int v;
    color[u] = GRAY;
    d[u] = ++tt; //d[]の値はttより１大きい
    for(v=0; v<n; v++){
        if(M[u][v] == 0) continue;
        if(color[v] == WHITE){
            dfs_visit(v);
        }
    }
    color[u] = BLACK;
    f[u]= ++tt;
}

void dfs(){
    int u;
    for(u=0; u<n; u++) color[u] = WHITE;
    tt = 0;

    for(u=0;u<n; u++){
        if(color[u] == WHITE) dfs_visit(u);
    }

    for(u=0; u<n; u++){
        printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}

