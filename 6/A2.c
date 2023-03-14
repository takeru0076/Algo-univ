#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0; i<VMAX+1; i++) C[i]=0;

  for(j=0; j<n; j++){
      scanf("hu",A[i]);
  }

  return 0;
}
