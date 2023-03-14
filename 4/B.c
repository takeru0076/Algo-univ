#include <stdio.h>
#include <stdlib.h>

int binarySearch(int * ,int, int);

int main(){
    int n;
    int *s;

    scanf ("%d",&n);
    s = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d",&s[i]);

    int q,key,sum=0;
    scanf("%d",&q);
    for(int j = 0; j < q; j++){
        scanf("%d",&key);
        sum += binarySearch(s,n,key);
    }

    printf("%d\n",sum);

    free(s);

    return 0;
}

int binarySearch(int *s, int n, int key){
    int left = 0, right = n;
    int mid;

    while (left < right){
        mid = (left + right) / 2;
        if(s[mid] == key) {
            return 1;
        } else if (key < s[mid]){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}