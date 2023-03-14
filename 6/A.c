#include <stdio.h>
//計数ソート

int a[20000001];
int b[20000001];
int c[10001];

int main(){
    int n,i,j;
    scanf("%d",&n);

    for(i=1; i<=n; i++) scanf("%d",&a[i]);

    for(i=0; i<=10000; i++) c[i]=0;

    for(j=1; j<=n; j++){
        c[a[j]]++;
    }

    for(i=1; i<=10000; i++) c[i] = c[i] +c[i-1];

    for(j=1; j<=n; j++){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }

    for(i=1; i<=n; i++) {
        printf("%d",b[i]);
        if(i!=n) printf(" ");
        if(i==n) printf("\n");
    }
    return 0;
}