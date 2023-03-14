#include <stdio.h>
//マージソート

int s[5000000];
int cnt=0;

void merge(int, int, int);

void mergesort(int ,int);

int main(){
    int i,n;

    scanf("%d",&n);

    for(i=0; i<n; i++) scanf("%d",&s[i]);

    mergesort(0,n);

    for(i=0; i<n; i++){
        printf("%d",s[i]);
        if(i!=n-1) printf(" ");
        if(i==n-1) printf("\n");
    }

    printf("%d\n",cnt);

    return 0;
}

void mergesort(int left,int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergesort(left,mid);
        mergesort(mid,right);
        merge(left,mid,right);
    }
}

void merge (int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int l[n1],r[n2];

    int i,k,j;

    for(i=0; i<n1; i++) l[i] = s[left+i];

    for(i=0; i<n2; i++) r[i] = s[mid+i];

    l[n1] = 2000000000;
    r[n2] = 2000000000;

    i=0; j=0;
    for(k=left; k<right; k++){
        cnt++;
        if(l[i] <= r[j]){
            s[k] = l[i];
            i++;
        } else{
            s[k] = r[j];
            j++;
        }
    }
}