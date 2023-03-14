#include <stdio.h>
#include <stdlib.h>
//バブルソート(安定)

int bubblesort(int *, int);


int main(){
    int i,n,*sort,count;

    sort=(int *)malloc(1000 * sizeof(int));

    for(i = 0; i < 1000; i++){
        scanf("%d",&sort[i]);
    }

    count = bubblesort(sort,1000);

    /*for(i = 0; i < 1000; i++){
        printf("%d",sort[i]);
        if(i < n-1){
            printf(" ");
        }
        
        if(i == n-1){
            printf("\n");
        }
    }*/


    printf("%d .      %d .     %d\n",sort[999],sort[998],sort[997]);

    free(sort);
    return 0;
}

int bubblesort(int *sort,int n){
    int flag=1,j,count=0,tem;

    while(flag){
        flag = 0;
        for(j = n-1; j >= 1; j--){
            if(sort[j] < sort[j-1]){
                tem = sort[j];
                sort[j] = sort[j-1];
                sort[j-1] = tem;
                count++;
                flag = 1;
            }
        }
    }
    return count;
}