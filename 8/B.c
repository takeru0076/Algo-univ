#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二分探索木ー探索

typedef struct Node
{
    int key;
    struct Node *parent, *left, *right;
};

struct Node *root, *NIL;

void insert(int);
void Preorder(struct  Node *);
void Inorder(struct Node *);
struct Node * find (struct  Node *, int );

int main(){
    int m,v;;
    char str[10];
    scanf("%d",&m);

    for(int i=0; i<m; i++){
        scanf("%s",str);
        if(strcmp(str,"insert") == 0 ){
            scanf("%d",&v);
            insert(v);
        } else if (strcmp(str,"find") == 0 ){
            scanf("%d",&v);
            struct Node *t = find(root,v);
            if(t != NIL) printf("yes\n");
            else printf("no\n");
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
 struct Node * find(struct Node *u,int k){
     while(u != NIL && k != u->key){
         if(k < u->key) u = u->left;
         else u = u->right;
     }
     return u;
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