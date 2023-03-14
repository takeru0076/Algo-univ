#include <stdio.h>
//最大公約数

int main(){
    int x,y,r,tem;
    scanf("%d%d",&x,&y);

    if(y > x){
        tem = x;
        x = y;
        y = tem;
    }

    while(1){
        r = x % y;
        if(r == 0)break;
        x = y;
        y = r;
    }
    printf("%d\n",y);
    return 0;
}