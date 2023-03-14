#include<stdio.h>

#define MAX 101
#define WHITE 0
#define BLACK 1
#define INF 10000001
#define NIL 1000000000

int G[MAX][MAX],n,d[MAX],pi[MAX],color[MAX];

void Dijkstra(int);

int main(){
  int i,j;
  n=100;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=NIL;
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
  	   scanf("%d",&G[i][j]);
  	}
  }
  Dijkstra(0);
  int mx=0;
  for(i=0;i<n;i++){
    if(mx<d[i])mx=d[i];
  }
    printf("%d\n",mx);
  return 0;
}




void Dijkstra(int r){
  int i,j;
  for(i=0;i<n;i++){
    d[i]=INF;
    pi[i]=NIL;
  }
  d[r]=0;
  while(1){
	int u,mincost = INF;
	for(i=0;i<n;i++){
  	if(color[i]!=BLACK && d[i]<mincost){
    mincost = d[i];
    u = i;
  	}
	}

	if(mincost==INF)break;
	color[u]=BLACK;

	for(i=0;i<n;i++){
  	if(color[i]!=BLACK && G[u][i]+d[u]<d[i] && G[u][i]!=NIL){
    pi[i] = u;
    d[i] = G[u][i]+d[u];
  	}
	}
  }
}