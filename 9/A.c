#include <stdio.h>
//完全二分木
 
#define SIZE 252
#define MAX 2000000001

typedef struct {
    int key,parent_key,left_key,right_key;
} heap;
heap H[SIZE];

int main(){
    for(int i=0; i<SIZE; i++) H[i].parent_key = MAX;

    int n,x;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&x);
        H[i].key = x;
        H[i].parent_key = i/2;
        H[i].left_key = 2*i;
        H[i].right_key = 2*i+1;
    }

    for(int i=1; i<=n; i++){
        printf("node %d: key = %d, ",i,H[i].key);
        if(H[i].parent_key != MAX && H[H[i].parent_key].key != 0) printf("parent key = %d, ",H[H[i].parent_key].key);
        if(H[i].left_key <= n)  printf("left key = %d, ",H[H[i].left_key].key);
        if(H[i].right_key <= n) printf("right key = %d, ",H[H[i].right_key].key);
        printf("\n");
    }
    return 0;
}