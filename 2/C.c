#include <stdio.h>
#include <stdlib.h>
//安定

typedef struct {
    char kind;
    int number;
}card;

void BubbleSort(card *, int);
void selectionSort(card *,int);
int stablech(card *, card *, int );

int main(){
    int n,i,flag;

    scanf("%d",&n);

    card *play_1,*play_2;

    play_1 = (card *)malloc(n * sizeof(card));
    play_2 = (card *)malloc(n * sizeof(card));

    for(i = 0; i < n; i++){
        scanf(" %c%d",&play_1[i].kind,&play_1[i].number);
        play_2[i] = play_1[i];
    }

    BubbleSort(play_1,n);

    for(i = 0; i < n; i++){
        printf("%c%d",play_1[i].kind,play_1[i].number);

        if(i == n-1){
            printf("\n");
        }
        if(i < n-1){
            printf(" ");
        }
    }

    printf("Stable\n");

    selectionSort(play_2,n);

    for(i = 0; i < n; i++){
        printf("%c%d",play_2[i].kind,play_2[i].number);

        if(i == n-1){
            printf("\n");
        }
        if(i < n-1){
            printf(" ");
        }
    }

    flag = stablech(play_1,play_2,n);
    
    if(flag == 1){
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    free(play_1);   
    free(play_2);

    return 0;
}



void BubbleSort(card *play_1, int n){
    int i,j;
    card tem;
    for(i = 0; i < n; i++){
        for(j = n -1; j >= i + 1; j--){
            if(play_1[j].number < play_1[j-1].number){
                tem = play_1[j];
                play_1[j] = play_1[j-1];
                play_1[j-1] = tem;
            }
        }
    }
}




void selectionSort(card *play2, int n){
    int i,j, minj;
    card tem;

    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(play2[j].number < play2[minj].number){
                minj = j;
            }
        }
        if(i != minj){
            tem = play2[i];
            play2[i] = play2[minj];
            play2[minj] = tem;
        }
    }
}




int stablech(card *play_1,card *play_2,int n){
  int i;
  for(i = 0; i < n; i++){
    if(play_1[i].number != play_2[i].number || play_1[i].kind != play_2[i].kind) return 0;
  }
  return 1;
}