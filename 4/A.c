#include <stdio.h>
#include <stdlib.h>
//線形探索

int linearSearch(int ,int *, int );

int main(){
    int i,j,n,q,cnt=0,key;
    int *s;

    scanf("%d",&n);

    s = (int *)malloc((n+1) * sizeof(int));

    for(i = 0; i < n; i++) scanf("%d",&s[i]);

    scanf("%d",&q);

    for(j = 0; j < q; j++){
        scanf("%d",&key);
        if(linearSearch(n,s,key)){
            cnt++;
        }

        /*cnt += linearSearch(n,s,key)*/
    }

    printf("%d\n",cnt);

    free(s);

    return 0;
}

int linearSearch(int n,int *A, int key){
    int i = 0;
    A[n] = key;

    while(A[i] != key) i++;

    if(i == n) return 0;

    return 1;
}