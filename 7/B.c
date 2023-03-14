#include <stdio.h>
//二分木

#define MAX 32
#define NIL -1

typedef struct {
    int parent,left,right;
}tree;


tree T[MAX];
int n,D[MAX],H[MAX];

void depth(int ,int);
int height(int);
int sibiling(int);
void print(int);

int main(){
    int v,l,r,root=0;
    scanf("%d",&n);

    for(int i=0; i<n; i++) T[i].parent = NIL;

    for(int i=0; i<n; i++){
        scanf("%d %d %d",&v,&l,&r);
        T[v].left = l;  
        T[v].right = r;
        if(l != NIL) T[l].parent = v;
        if(r != NIL) T[r].parent = v;
    }


    for(int i=0;i<n;i++)
    if(T[i].parent == NIL)root = i;

    depth(root,0);
    height(root);

    for(int i=0; i<n; i++) print(i);
    return 0;
}

void depth(int u,int d){
    if(u == NIL)return;
    D[u] = d;
    if(T[u].right != NIL) depth(T[u].right,d+1);
    if(T[u].left != NIL) depth(T[u].left,d+1);
}

int height(int u){
    int h1=0, h2=0;
    if(T[u].left != NIL){
        h1 = height(T[u].left) + 1;
    }
    if(T[u].right != NIL) {
        h2 = height(T[u].right) + 1;
    }
    if(h1>=h2){
        H[u] = h1;
    } else{
        H[u] = h2;
    }
    return H[u];
}

int sibiling(int u){
    if(T[u].parent == NIL)
    return NIL;

    if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)
    return T[T[u].parent].left;

    if(T[T[u].parent].right != u && T[T[u].parent].right != NIL)
    return T[T[u].parent].right;

    return NIL;
}

void print(int u){
    printf("node %d: ",u);
    printf("parent = %d, ",T[u].parent);
    printf("sibling = %d, ",sibiling(u));
    int deg = 0;
    if(T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[u]);
    printf("height = %d, ",H[u]);

    if(T[u].parent == NIL) {
        printf("root\n");
    } else if (T[u].left == NIL && T[u].right == NIL){
        printf("leaf\n");
    }else printf("internal node\n");
}
