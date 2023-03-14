#include <stdio.h>
//連鎖行列積

#define INF (1<<21)

int main(){
    int n,N=101,p[N],m[N][N];
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d%d",&p[i-1],&p[i]);
    }

    for(int i=1; i <= n; i++) m[i][i]=0; //初期値を設定
    for(int l =2; l <= n; l++){//
        for(int i =1; i <= n-l+1; i++){//連鎖長がlのもでループ
            int j = i + l -1;//
            m[i][j] = INF;//
            for(int k = i; k <= j-1; k++){//
                if(m[i][j] > m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]){//
                    m[i][j] = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];//
                }//m[i][j]を求める
            }
        }
    }

    printf("%d\n",m[1][n]);
    return 0;
}

//(Mn-1Mn) を計算するための方法はただ 1 通りであり、rn-1 × rn × rn+1 回の掛け算が必要