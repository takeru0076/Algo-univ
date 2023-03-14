#include <stdio.h>
//maxヒープ

#define MAX 500005
#define HIGH 2000000002

void maxHeapify(int);

int heap[MAX],n;

int main(){
    for(int i=0; i<MAX; i++) heap[i] = HIGH;

    int x;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&x);
        heap[i] = x;
    }

    for(int i=n/2; i>=1; i--) maxHeapify(i);

    for(int i=1; i<=n; i++) printf(" %d",heap[i]);

    printf("\n");
    return 0;
}

void maxHeapify(int x){
    int l,r,largest;
    l = 2*x; r = 2*x+1;

    //左、自分、右で値が最大のノードを選ぶ。
    if(l <= n && heap[l] > heap[x]) largest = l;
    else largest = x;
    if(r <= n && heap[r] > heap[largest]) largest = r;

    if(largest != x){  //xの子の方が値が大きい場合
        int tem;
        tem = heap[largest] ;
        heap[largest] = heap[x]; 
        heap[x] = tem;
        maxHeapify(largest);
    }
}