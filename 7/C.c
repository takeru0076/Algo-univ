#include <stdio.h>
//木の巡回
#define MAX 10000
#define NIL -1

typedef struct
{
    int parent,left,right;
}tree;

tree T[MAX];
int n;

void Preorder(int);
void Inorder(int);
void Postorder(int);

int main(){
    scanf("%d",&n);
    int i,v,l,r,root;

    for(i=0; i<n; i++) T[i].parent = NIL;

    for(i=0; i<n; i++){
        scanf("%d %d %d",&v,&l,&r);
        T[v].left = l;  
        T[v].right = r;
        if(l != NIL) T[l].parent = v;
        if(r != NIL) T[r].parent = v;
    }

    for(i=0; i<n; i++) if(T[i].parent == NIL) root = i;

    printf("Preorder\n");
    Preorder(root);
    printf("\n");
    printf("Inorder\n");
    Inorder(root);
    printf("\n");
    printf("Postorder\n");
    Postorder(root);
    printf("\n");
    return 0;
}
//先行順巡回（根節点→左→右）
void Preorder(int u){
    if(u == NIL) return;
    printf(" %d",u);
    Preorder(T[u].left);
    Preorder(T[u].right);
}

//中間順巡回 (左→根→右)
void Inorder(int u){
    if(u == NIL) return;
    Inorder(T[u].left);
    printf(" %d",u);
    Inorder(T[u].right);
}


//後行順巡回 (左→右→根)
void Postorder(int u){
    if(u == NIL) return;
    Postorder(T[u].left);
    Postorder(T[u].right);
    printf(" %d",u);
}