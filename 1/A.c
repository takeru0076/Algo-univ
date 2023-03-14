#include <stdio.h>
#include <stdlib.h>
//挿入ソート
void insertionSort(int *, int);

int main(){
    int i,n,*array;

    scanf("%d",&n);

    array = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }

    insertionSort(array,n);  
    free(array);
    return 0;
}

void insertionSort(int *array,int n){
    int i,j,m,key;

    for(m = 0; m < n; m++){
        printf("%d",array[m]);
        if(m < n-1){
            printf(" ");
        }
        if(m == n-1){
            printf("\n");
        }
    }

    for(i =1; i <= n-1; i++){
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;

        for(m = 0; m < n; m++){
        printf("%d",array[m]);
        if(m < n-1){
            printf(" ");
        }
        if(m == n-1){
            printf("\n");
        }
    }
    }
}