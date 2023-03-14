#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二分探索木ー挿入
typedef struct Node
{
    int key;
    struct Node *parent, *left, *right;
};

struct Node *root, *NIL; //NIl = NULL

void insert(int );
void Preorder(struct  Node *);
void Inorder(struct Node *);

int main(){
    int m,v;;
    char str[10];
    scanf("%d",&m);

    for(int i=0; i<m; i++){
        scanf("%s",str);
         if(strcmp(str,"insert") == 0 ){
            scanf("%d",&v);
            insert(v);
        } else {
            Inorder(root); printf("\n");
            Preorder(root); printf("\n");
        }
    }
    return 0;
}

void insert(int k){
    struct Node *y = NIL;
    struct Node *x = root;
    struct Node *z;

    z = (struct Node *)malloc(sizeof(struct Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if(y == NIL){
        root = z;
    } else if(z->key < y->key){
        y->left = z;
    } else {
        y->right = z;
    }

}

void Preorder(struct Node *u){
    if(u == NIL) return;
    printf(" %d",u->key);
    Preorder(u->left);
    Preorder(u->right);
}

void Inorder(struct Node *u){
    if(u == NIL) return;
    Inorder(u->left);
    printf(" %d",u->key);
    Inorder(u->right);
}