#include <stdio.h>

long long int makefibonacci(int);
int n;
long long int f[100];

int main(){
    for(int i=0; i<100; i++) f[i] = -100;
    scanf("%d",&n);
    long long int result = makefibonacci(n);
    printf("%ld\n",result);
    return 0;
}

long long int makefibonacci(int n){
    if(n ==0 || n == 1){
        return 1;
    }

    if(f[n] != -100) {
        return f[n];
    }

    return f[n] = makefibonacci(n-2)+makefibonacci(n-1);
}