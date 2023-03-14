#include <stdio.h>
#include <stdlib.h>
//逆ポーランド

#define MAX 1000

typedef struct{
    int data[MAX];
    int top;
}stack;

void check (int, stack *);
void push (int, stack *);
int pop (stack *);
int sum=0;


int main(){
    int input;
    stack poll;

    poll.top = 0;

    while(1){
        if(scanf("%d",&input) != 1){
            break;
        }
            //check(input,&poll);
            check(input,&poll);
    }
    printf("%d\n",sum);
    return 0;
}


/*void check (char *input, stack *s){
    if(input [0] == '+'){
        int x = pop(s), y = pop(s);
        push(x+y, s);
    } else if(input [0] == '-'){
        int x = pop(s), y = pop(s);
        push(y-x, s);
    } else if(input [0] == '*'){
        int x = pop(s), y = pop(s);
        push(x*y, s);
    } else {
        push(atoi(input),s);
    }
}*/

void check(int input,stack *s){
    if(input > 0){
        push(input,s);
        sum = sum + input;
    } 
    if(input ==0){
        int x = pop(s);
        sum = sum - x;
    }
}



void push (int item, stack *s){
    s->data[s->top] = item;
    s->top++;
}




int pop(stack *s){
        s->top--;
        return s->data[s->top];
}