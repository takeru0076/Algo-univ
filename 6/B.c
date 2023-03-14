#include <stdio.h>
//パーティション、基準は一番最後に入力されたやつ

int s[100000];

int  partion(int , int );

int main(){
    int n,res;
    scanf("%d",&n);

    for(int i=0; i<n; i++) scanf("%d",&s[i]);

        res = partion(0,n-1);

        for(int i=0; i<n; i++){
            if(i==res) printf("[");
            printf("%d",s[i]);
            if(i==res) printf("]");

            if(i!=n-1) printf(" ");
            if(i==n-1) printf("\n");
        }

    return 0;
}

int partion(int p, int r){
    int x =s[r];
    int i=p-1;
    int tem,j;

    for(j=p; j<r; j++){
        if(s[j] <= x){
            i++;
            tem=s[i];
            s[i] = s[j];
            s[j] = tem;
        }
    }
    tem = s[i+1];
    s[i+1] = s[r];
    s[r] = tem;
    return i+1;
}