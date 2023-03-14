#include <stdio.h>
#include <stdlib.h>
//選択ソート(不安定)
int selectionSort(int *, int);

int main(){
    int i,n,cnt,*array;

    scanf("%d",&n);

    array = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }

    cnt = selectionSort(array, n);

    for(i = 0; i < n; i++){
        printf("%d",array[i]);
        if(i < n-1){
            printf(" ");
        } else {
            printf("\n");
        }
    }

    printf("%d\n",cnt);

    free(array);

    return 0;
}

int selectionSort(int *s,int n){
    int i,j, minj,tem,cnt=0;

    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(s[j] < s[minj]){
                minj = j;
            }
        }
        if(i != minj){
            tem = s[i];
            s[i] = s[minj];
            s[minj] = tem;
            cnt++;
        }
    }

    return cnt;
}