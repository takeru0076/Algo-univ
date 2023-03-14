#include <stdio.h>
//クイックソート、不安定(安定はマージ、バブル)
//配列全体を対象としてクイック、その後分割してクイックソート

typedef struct 
{
    int number;
    char lite;
}card;

card c[100001],d[100001];

int n;

void quicksort(int , int);
int partion(int ,int);
void merge(int, int, int);
void mergesort(int ,int);


int main(){
    scanf("%d",&n);

    int i,flag = 1;

    for(i=0; i<n; i++) {
        scanf(" %c%d",&c[i].lite,&c[i].number);
        d[i] = c[i];
    }

    quicksort(0,n-1);
    mergesort(0,n);

    for(i=0; i<n; i++){
        if(c[i].lite != d[i].lite){
            flag = 0;
        }
    }

    if(flag==1){
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }


    for(i=0; i<n; i++){
        printf("%c %d\n",c[i].lite,c[i].number);
    }

    return 0;
}

void quicksort(int p, int r){
    int q;
    if(p<r){
        q =partion(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}


int partion(int p, int r){
    int x =c[r].number;
    int i=p-1;
    int j;
    card tem;

    for(j=p; j<r; j++){
        if(c[j].number <= x){
            i++;
            tem=c[i];
            c[i] = c[j];
            c[j] = tem;
        }
    }
    tem = c[i+1];
    c[i+1] = c[r];
    c[r] = tem;
    return i+1;
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
    card l[n1],r[n2];

    int i,k,j;

    for(i=0; i<n1; i++) l[i] = d[left+i];

    for(i=0; i<n2; i++) r[i] = d[mid+i];

    l[n1].number = 2000000000;
    r[n2].number = 2000000000;

    i=0; j=0;
    for(k=left; k<right; k++){
        if(l[i].number <= r[j].number){
            d[k] = l[i];
            i++;
        } else{
            d[k] = r[j];
            j++;
        }
    }
}