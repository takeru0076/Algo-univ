#include <stdio.h>
#include <stdbool.h>

#define N 3
#define N2 9

typedef struct
{
    int f[N2];
    int space;
    char path[100];
}Puzzle;

typedef struct QUEUE
{
    int tail,head;
     Puzzle data[1000000];
}QUEUE_T;

typedef struct
{
    Puzzle pa;
    bool ToF;
}MAP;


static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,-1,0,1};
QUEUE_T queue;
MAP V[100000];

static const char dir[4] = {'u','l','d','r'};
void enqueue(int);
int  dequeue();
void initQueue();
void bfs(int);

bool operator < (const Puzzle &p) const {
    for(int i=0; i<N2; i++){
        if(f[i] == p.f[i]) continue;
        return f[i] > p.f[i];
    }
}

bool isTarget( Puzzle s);
char bfs(Puzzle s);

int main(){
     Puzzle in;

     for(int i=0; i<N2; i++){
         scanf("%d",&in.f[i]);
         if(in.f[i] == 0){
             in.f[i] = N2;
             in.space = i;
         }
     }
     initQueue()
     bfs(in);
    return 0;
}

void initQueue(){
    queue.head = 1;
    queue.tail = 1;
}

void enqueue(Puzzle input){
    queue.data[queue.tail] = input;
    queue.tail++;
}

Puzzle dequeue (){
    Puzzle date;
   
    date = queue.data[queue.head];
    queue.head++;
    return date;
}

void bfs(Puzzle s){
    Puzzle u,v;
    s.path = "";
    enqueue(s)
    V[s] = true;
}