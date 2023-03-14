#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

typedef struct{
    char name[100];
    int time;
}que;

int head,tail;

void enqueue(que *, que *, int);
que * dequeue(que *,int);
int min(int, int);

int main(){
    int n=0,q=0,sum=0,c=0;
    que *Q,*u;

    scanf("%d%d",&n,&q);

    Q = (que *)malloc((n+2) * sizeof(que));

    for(int i = 1; i <= n; i++){
        scanf("%s %d",Q[i].name,&Q[i].time);
    }

    head = 1;
    tail = n + 1;

    while (head != tail){
        
        u = dequeue(Q,n);
        c = min(q,u->time);
        u->time -= c;
        sum += c;
        if(u->time > 0){
            enqueue(Q,u,n);
        } else {
            printf("%s %d\n",u->name,sum);
        }
    }

    free(Q);
    return 0;
}

void enqueue (que *Q, que *x,int n){
    Q[tail] = *x;

    if(tail == n+1){
        tail = 1;
    } else {
        tail = (tail + 1);
    }
}

que * dequeue(que *Q,int n){
    que *x = &Q[head];
    if(head == n+1){
        head = 1;
    } else {
        head = (head + 1) ;
    }
    return x;
}

int min (int q, int u){
    // return q <= u ? q : u;
    if(q <= u) {
        return q;
    } else {
        return u;
    }
}