#include <stdio.h>
#include <stdlib.h>

//Implementation due to solution described in XV OI book page 63
//
//functions are for integer stack without size limit(may cause memory problems when not controling stack size)

int stacktop = -1;

int isEmpty(void);
int pop(int *stack);
int top(int *stack);
void push(int *stack, int data);


int main(){
    
    int nofbuildings, trash, posters = 0;
    scanf("%d",&nofbuildings);
    int *stack = malloc(nofbuildings*sizeof(int));
    
    for (int i = 0; i<nofbuildings; i++) {
        
        int newheight;
        scanf("%d %d",&trash,&newheight);
        
        while (!isEmpty() && top(stack) > newheight) {
            pop(stack);
        }
        
        if (isEmpty() || top(stack) < newheight) {
            push(stack, newheight);
            posters ++;
        }
    }
    printf("%d",posters);
    
    return 0;
}



int isEmpty(void){
    if(stacktop == -1){
        return 1;
    } else {
        return 0;
    }
}

int pop(int *stack){
    int data;
    if (!isEmpty()) {
        data = stack[stacktop];
        stacktop --;
        return data;
    } else {
        printf("Error: could not retrieve data\n");
        return -1;
    }
}

int top(int *stack){
    return stack[stacktop];
}

void push(int *stack, int data){
    stacktop ++;
    stack[stacktop] = data;
}
