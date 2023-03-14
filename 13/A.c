#include <stdio.h>
#include <stdbool.h>

#define N 8
#define FREE -1 
#define NOT_FREE 1 //NOT＿FREE＝襲撃されている。

int row[N],col[N],dpos[2*N-1],dneg[2*N-1]; //row = 行、col = 列、dpos = 左下方向、dneg = 右下方向
bool X[N][N];

//全てFREEならQ設置可能
void initialize();
void printBoard();
void recursive(int i);

int main(){
    initialize();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            X[i][j] = false;
        }
    }
    int k;
    scanf("%d",&k);

    for(int i=0; i<k; i++){
        int r,c;
        scanf("%d%d",&r,&c);
        X[r][c] = true;
    }

    recursive(0);
    return 0;
}

void initialize(){
    for(int i= 0;i< N; i++){
        row[i] = FREE;
        col[i] = FREE;
    }

    for(int i=0; i<2*N-1; i++){//対角線のほん数
        dpos[i] = FREE; 
        dneg[i] = FREE;
    }
}

void printBoard(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(X[i][j]){
                if(row[i] != j) return;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(row[i] == j) printf("Q");
            else printf(".");
        }
        printf("\n");
    }
}

void recursive(int i){
    if(i == N){
        printBoard();
        return;
    }

    for(int j=0; j<N; j++){
        //(i,j)が他のQに襲撃されている場合は無視。
        if(NOT_FREE == col[j] || NOT_FREE == dpos[i+j] || NOT_FREE == dneg[i-j+N-1]) continue;
        //(i,j)にクイーンを配置
        row[i] = j;
        col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
        //次の行を試す
        recursive(i+1);
        //(i,j)に配置されているQを取り除く
        row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
    }
    //Qの配置に失敗
}