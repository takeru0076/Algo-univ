#include <stdio.h>
#define SOSUU 1
#define NOSOSUU 0
//素数
int sosuuch(int);

int main(){
    int n,s,i,kosuu=0;

    scanf("%d",&n);


    for(i = n-1; i >= 0; i--){
    scanf("%d",&s);
    kosuu += sosuuch(s);
    }

    printf("%d\n",kosuu);
    return 0;
}

int sosuuch(int s){
    int i,j;
       if(s==2 || s==3){
           return SOSUU;
        }
        if(s%2==0){
            return NOSOSUU;
        }

        for(j=3; j*j<=s; j+=2){
           if(s%j==0){
               return NOSOSUU;
            }
        }
    return SOSUU;
}