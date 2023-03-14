#include <stdio.h>
#include <string.h>

#define M 1000000
#define TRUE 1
#define FALSE 0

char H[M][100];
int n;

void insert(char []);
int find(char []);

int main(){
    scanf("%d",&n);

    char order[12],str[100];
    int i;

    for ( i = 0; i < M; i++ ) H[i][0] = '\0';

    for(i = 0; i < n; i++){
        scanf("%s %s",order,str);
        if(order[0] == 'i'){
            insert(str);
        } else {
            if(find(str)){
                printf("yes\n");
            } else{
                printf("no\n");
            }
        }
    }
    return 0;
}

void insert(char str[100]){
    static int i = 0;
    strcpy(H[i],str);
    i++;
}

int find(char str[100]){
    int i = 0;
    strcpy(H[n],str);

    while(strcmp(H[i],str) != 0) i++;

    if(i == n) return FALSE;

    return TRUE;
}