#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//最長共通部分列
#define N 1000

int lcs();

char str1[1000],str2[1000];
int n;

int main(){
        scanf("%s%s",str1,str2);
        printf("%d\n",lcs());
    return 0;
}

int lcs(){
    int c[N+1][N+1];
    int m = (int)strlen(str1);
    int n = (int)strlen(str2);
    //printf("m=%d n=%d\n",m,n);
    int maxl=0;
    for(int i=0; i<=m; i++) c[i][0] = 0;
    for(int j=1; j<=n; j++) c[0][j] = 0;

    for(int i=1; i <= m; i++){
        for(int j =1; j <= n; j++){
            if(str1[i-1] == str2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                } else {
                    c[i][j] = c[i][j-1];
                }
            }
            if(maxl < c[i][j]){
                maxl = c[i][j];
            }
        }
    }
    return maxl;
}