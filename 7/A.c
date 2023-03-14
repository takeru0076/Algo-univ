#include <stdio.h>
//根ツキギ

#define MAX 32
#define NIL -1

typedef struct {
    int parent,left,right;
}tree;

tree T[MAX];
int n,D[MAX];

void setdepth(int ,int);
void print(int);

int main(){
    int i,j,degree,v,c,l,r;
    scanf("%d",&n);
    for(i=0; i<n; i++) T[i].parent = T[i].left = T[i].right = NIL;

    for(i=0; i<n; i++){
        scanf("%d%d",&v,&degree);
        for(j=0; j<degree; j++){
            scanf("%d",&c);
            if(j==0) T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }

    for(i=0; i<n; i++){
        if(T[i].parent == NIL) r = i;
    }

    setdepth(r,0);

    for(i=0; i<n; i++) print(i);
    return 0;
}

void setdepth(int u,int p){
    D[u] = p;
    if(T[u].right != NIL) setdepth(T[u].right,p);
    if(T[u].left != NIL) setdepth(T[u].left,p+1);
}

void print(int u){
    int i,c;
    printf("node %d: ",u);
    printf("parent = %d, ",T[u].parent);
    printf("depth = %d, ",D[u]);

    if(T[u].parent == NIL) printf("root, ");
    else if (T[u].left == NIL) printf("leaf, ");
    else printf("internal node, ");

    printf("[");

    for(i=0, c = T[u].left; c!=NIL; i++, c = T[c].right){
        if(i) printf(", ");
        printf("%d",c);
    }
    printf("]\n");
}