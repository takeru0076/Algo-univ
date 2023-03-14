#include <stdio.h>
#include <string.h>
//優先順位キュー

#define MAX 1000000

void insert(int);
void IncreaseKey(int ,int);
int heapExtractMax();
void maxHeapify(int);

int H[MAX],F=1;

int main(){
    char str[10];

    int x;

    while(1){
        scanf("%s",str);
        if(strcmp(str,"insert") == 0){
            scanf("%d",&x);
            insert(x);
            //for(int i=1; i<10; i++) printf("i%d   ",H[i]);
            //printf("\n");
        } else if(strcmp(str,"extract") == 0){
            printf("%d\n",heapExtractMax());
           //for(int i=1; i<10; i++) printf("d%d   ",H[i]);
            //printf("\n");
        } else {
            break;
        }
    }
    return 0;
}

void maxHeapify(int x){
    int l,r,largest;
    l = 2*x; r = 2*x+1;

    //左、自分、右で値が最大のノードを選ぶ。
    if(l >= F && H[l] < H[x]) largest = l;
    else largest = x;

    if(r >= F && H[r] < H[largest]) largest = r;

    if(largest != x){ //xの子の方が値が大きい場合
        int tem;
        tem = H[largest] ;
        H[largest] = H[x]; 
        H[x] = tem;
        maxHeapify(largest);
    }
}

//ヒープ要素の最大の要素を取得・削除
int heapExtractMax(){
    int max = H[1];
    H[1] = H[F];
    F--;
    maxHeapify(1);
    //printf("%d\n",max);
    return max;
}

//優先度付きキューを表すヒープへの挿入
void insert(int key){
    F++;
    H[F] = 2000000001;
    IncreaseKey(F,key);
}


//優先度付きキューを表すヒープ要素のキーの変更
void IncreaseKey(int i,int key){
    if(key > H[i]) return;
    H[i] = key;
    while (i > 1 && H[i/2] > H[i])
    {
        int tem = H[i];
        H[i] = H[i/2];
        H[i/2] = tem;
        i = i/2;
    }
    
}