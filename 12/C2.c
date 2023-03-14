#include <stdio.h>
#include<stdbool.h>

#define N 100
#define INFTY 200000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,G[N][N],d[N],heap[N],F=1,isEmpty;

void dijkstra();
void minHeapify(int);
int heapExtractMin();
void insert(int);
void IncreaseKey(int ,int);

int main(){
    int k,c,u,v,cnt=0;
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
            insert(c);
        }
    }

    for(int i=0; i<n; i++){
        if(d[i] == INFTY) d[i] = -1;
        printf("%d %d\n",i,d[i]);
       // printf("h:%d\n",heap[i]);
    }

    return 0;
}

void dijkstra(){
    int color[N];

    for(int i=0; i<n; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[0] = 0;
    color[0] = GRAY;

    while (!isEmpty){//
        int u = heapExtractMin();
        color[u] = BLACK;

        while (1){
            if(color[v] != BLACK && G[u][v] != INFTY){
                if(d[v] > d[u] + G[u][v]){
                    d[v] = d[u] + G[u][v];
                    color[v] = GRAY;
                    for(int i=n/2; i>=1; i--) minHeapify(v);
                }
            }
            if() break;
        }
    }
}

void minHeapify(int x){
    int l,r,smallest;
    l = 2*x; r = 2*x+1;

    if(l <= n && heap[l] > heap[x]) smallest = l;
    else smallest = x;
    if(r <= n && heap[r] > heap[smallest]) smallest = r;

    if(smallest != x){
        int tem;
        tem = heap[smallest] ;
        heap[smallest] = heap[x]; 
        heap[x] = tem;
        minHeapify(smallest);
    }
}

int heapExtractMin(){
    int min = heap[1];
    heap[1] = heap[F];
    F--;
    if(F == 0) isEmpty = 0;
    minHeapify(1);
    return min;
}

void insert(int key){
    F++;
    heap[F] = -2000000001;
    IncreaseKey(F,key);
}

void IncreaseKey(int i,int key){
    if(key < heap[i]) return;
    heap[i] = key;
    while (i > 1 && heap[i/2] < heap[i])
    {
        int tem = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = tem;
        i = i/2;
    }
}