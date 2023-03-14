#include <stdio.h>
//幅優先探索
typedef struct QUEUE
{
    int tail,head,data[101];
}QUEUE_T;

void enqueue(int);
int  dequeue();
void initQueue();
void bfs(int);
int cnt=0;

int G[101][101],d[101],n;
QUEUE_T queue;

int main(){
    int u,k,v;
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

    initQueue();
    bfs(0);
    return 0;
}


void initQueue(){
    queue.head = 1;
    queue.tail = 1;
}

void enqueue(int input){
    queue.data[queue.tail] = input;
    queue.tail++;
}

int dequeue (){
    int date;
   
    date = queue.data[queue.head];
    queue.head++;
    return date;
}

void bfs(int s){
    enqueue(s);
    for(int i=0; i<n; i++) d[i] = -1;

    d[s] = 0;
    int u;
    while(queue.head != queue.tail)
    {
        u = dequeue();
        for(int v=0; v<n; v++){
            if(G[u][v] == 0) continue;
            if(d[v] != -1) continue;//最初のやつを弾くため
            d[v] = d[u]+1;
            enqueue(v);
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d %d\n",i+1,d[i]);
    }
}