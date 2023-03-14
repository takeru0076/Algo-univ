#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二分探索木-削除

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
void delete(struct Node *);
struct Node * minimum(struct Node *);
struct Node * successor(struct Node *);


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
        } else if(strcmp(str,"print") == 0 ){
            Inorder(root); printf("\n");
            Preorder(root); printf("\n");
        } else {
            scanf("%d",&v);
            delete(find(root,v));
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

struct Node * minimum(struct Node * x){
    while(x->left != NIL) x =x->left;
    return x;
}

struct Node * successor(struct Node * x){
    if(x->right != NIL) return minimum(x->right);
    struct Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void delete(struct Node *z){
    struct Node *y,*x;

    if(z->left == NIL || z->right == NIL) y = z;//yが子を持たないか、子を１つ持つ場合は入力節点のz
    else y = successor(z); //zが子を２つもつ場合はzの次節点

    if(y->left != NIL){
        x = y->left; //yに左の子があれば、xはyの左の子
    } else {
        x = y->right; //yに左の子がなければ、xはyの右の子
    }

    if(x != NIL){
        x->parent = y->parent; //xの親を設定する
    }

    if(y->parent == NIL){
        root = x;  //yが根の時、xを木の根をとする
    } else {
        if(y == y->parent->left){
            y->parent->left = x;  //yがその親pの左の子ならpの左の子をxとする
        } else {
            y->parent->right = x; //yがその親pの右の子なら、pの右の子をxとする
        }
    }

    if(y != z){ //zの次節点が削除された場合
        z->key = y->key; //yのデータをzにコピーする
    }
    //中間順巡回
    free(y);
}