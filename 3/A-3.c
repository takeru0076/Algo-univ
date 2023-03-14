#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef struct{
    char data[MAX];
    int top;
}stack;

char push(stack *);
int pop (stack *);
void check(stack *);


int main(){
    stack *poll;
    char c;
    while(1){ 
        c = push(poll);
        if(c == EOF){
            break;
        }
        check(poll);

    }

    printf("%d",pop(poll));
    return 0;

}

char push (stack *s){
    char item[100];
    if(s->top < MAX-1){
        scanf("%s",item);
        s->top++;
        s->data[s->top] = item;
    }

    if(item == EOF){
        return EOF;
    } else {
        return 'c';
    }
}


void check(stack *s){
    int a,b;
    if(s->data[s->top] == '+'){
        a = pop(s);
        s->top++;
        s->data[s->top] = a;

        b = pop(s);
        s->top++;
        s->data[s->top] = b;

        s->top++;
        s->data[s->top] = (int)s->data[s->top-1] +(int) s->data[s->top-2];

    } else if(s->data[s->top] == '-'){
        a = pop(s);
        s->top++;
        s->data[s->top] = a;

        b = pop(s);
        s->top++;
        s->data[s->top] = b;

        
        s->top++;
        s->data[s->top] = (int)s->data[s->top-1] - (int)s->data[s->top-2];

    } else if(s->data[s->top] == '*'){
        a = pop(s);
        s->top++;
        s->data[s->top] = a;

        b = pop(s);
        s->top++;
        s->data[s->top] = b;
        
        s->top++;
        s->data[s->top] = (int)s->data[s->top-1] - (int)s->data[s->top-2];

    } else {
        s->data[s->top] = atoi(&s->data[s->top]);
    }
}




int pop (stack *s){
        s->top--;
        return s->data[s->top];
}