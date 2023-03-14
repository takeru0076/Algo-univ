#include <stdio.h>

#define NUM 10000
#define INFTY 200000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

void swap(int *, int *);
int getLeft(int);
int getRight(int);
int getParent(int);
void addHeap(int);
void removeHeap(int);
void makeHeap(int);
void heapSort(int);
void dijkstra();

int n,G[NUM][NUM];

int main(){
    int k.u,v,c;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d%d",&u,&k);
        for(int j=0; j<n; j++){
            scanf("%d%d",&v,&c);
             G[u][v] = c;
        }
    }

    /* ヒープソート */
    heapSort(NUM);

    for(int i=0; i<n; i++){
        if(d[i] == INFTY) d[i] = -1;
        
        printf("%d %d\n",i,d[i]);
    }
    return 0;
}

/* データを入れ替える関数 */
void swap(int *a, int *b) {
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

/* 左の子ノードの位置を取得 */
int getLeft(int parent) {
    return parent * 2 + 1;
}

/* 左の子ノードの位置を取得 */
int getRight(int parent) {
    return parent * 2 + 2;
}

/* 親ノードの位置を取得 */
int getParent(int child) {
    return (child - 1) / 2;
}

/* a[size]を二分ヒープに追加し、二分ヒープを再構成する */
void addHeap(int size) {

    int add; /* 追加ノードの位置 */
    int parent; /* 追加ノードの親の位置 */

    /* まだ二分ヒープに追加していないデータの先頭を二分ヒープに追加 */
    add = size;
    if (add == 0) {
        /* 追加したノードが根ノードなら二分ヒープへの追加完了 */
        return;
    }

    /* 二分ヒープを満たすまで、追加したノードを根の方向に移動する */
    while (1) {
        /* 親ノードの位置を取得 */
        parent = getParent(add);
        
        if (a[parent] < a[add]) {
            /* 親と子で大小関係が逆ならデータを交換する */
            swap(&G[parent], &G[add]);

            /* 追加ノードは親ノードの位置に移動する */
            add = parent;
            if (add == 0) {
                /* 追加ノードが根ノードまで移動したら二分ヒープへの追加完了 */
                break;
            }
        } else {
            /* 大小関係が満たされているなら二分ヒープへの追加完了 */
            break;
        }
    }
}

/* 根ノードを二分ヒープから取り出し、二分ヒープを再構成する */
void removeHeap(int size) {
    int left; /* 左の子ノードの位置 */
    int right; /* 右の子ノードの位置 */ 
    int large; /* データが大きい方の子ノードの位置 */
    int parent; /* 親ノードの位置 */

    /* 根ノードをヒープ外に追い出す */
    /* 一時的に木の末端のノードを根ノードに設定する */
    swap(&G[0], &G[size - 1]);
    
    /* 二分ヒープのサイズを1減らす
        これにより元々の根ノードが「ソート済みのデータ」の先頭に移動することになる */
    size--;

    /* 根ノードから子ノードとの大小関係を確認していく */
    parent = 0;

    /* 二分ヒープを満たすまで、根ノードを葉の方向に移動する */
    while (1) {
        /* 子ノードの位置を取得 */
        left = getLeft(parent);
        right = getRight(parent);

        /* 子ノードの大きい値を持つ方の位置を取得 */
        if (left < size && right < size) {
            /* 左右両方の子ノードが存在する場合は比較して確認 */
            if (G[left] < G[right]) {
                large = right;
            } else {
                large = left;
            }
        } else if (left < size) {
            /* 左の子ノードしか存在しない場合は左の子ノードを大きい値を持つとみなす */
            large = left;
        } else {
            /* 両ノードがヒープ内に存在しない場合は終了 */
            /* (右の子ノードしか存在しない場合はあり得ない) */
            break;
        }

        if (G[large] <= G[parent]) {
            /* すでに親子の大小関係が満たされているので交換不要 */
            break;
        }

        /* 親と子で大小関係が逆ならデータを交換する */
        swap(&G[large], &G[parent]);

        /* 根ノードはデータを交換した子ノードの位置に移動する */
        parent = large;
    }
}

/* 二分ヒープを作成する関数 */
void makeHeap(int num) {

    int size; /* 二分ヒープに追加済みのデータの個数 */

    /* 二分ヒープのデータ個数を0にする */
    size = 0;

    /* sizeがソートするデータの個数になるまで二分ヒープにデータ追加 */
    while (size < num) {

        /* a[size]を二分ヒープに追加 */
        addHeap(G, size);

        /* 二分ヒープのデータ数が増えたのでsizeも1増やす */
        size++;
    }
}

/* ヒープソートを行う関数 */
void heapSort(int num) {

    int size; /* 二分ヒープのノード個数 */

    /* サイズnumの二分ヒープを作成 */
    makeHeap(G, num);
    

    /* 二分ヒープの根ノードを１つずつ取り出す */
    for (size = num; size > 0; size--) {
        /* サイズsizeの二分ヒープからデータを１つ取り出す */
        removeHeap(G, size);
    }

}

void dijkstra(){
    int color[NUM],d[NUM];

    for(int i=0; i<n; i++){
        d[i]= INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
}