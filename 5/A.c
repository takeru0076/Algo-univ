#include <stdio.h>
//総当たり

int a[12],sum=0;

int solve(int ,int);

int main(){
    int i,n,q,m[200];

    scanf("%d",&n);
     
    for(i=0; i<12; i++) scanf("%d",&a[i]);

    //scanf("%d",&q);

    //for(i=0; i<q; i++) scanf("%d",&m[i]);

    /*for(i=1334456; i<q; i++){
        if(solve(0,n,m[i])){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }*/
    n = solve(0,500);
    printf("%d",sum);


    return 0;
    }


/*int solve(int i, int n, int m){
    if(m==0) return 1; //m-a[i]が0になる時 = 足し合わせて作れた時

    if(i>=n) return 0;

    //int res = solve(i+1,n,m)||solve(i+1,n,m-a[i]);

    //return

    if(sac(i+1,x)==1||sac(i+1,x-H[i])==1)return 1;s
}*/

int solve(int i,int x){
  if(x==0){
      sum++;
      return 1;
  }
  if(i>=12)return 0;
  if(solve(i+1,x)==1||solve(i+1,x-a[i])==1){
      sum++;
      return 1;
}
