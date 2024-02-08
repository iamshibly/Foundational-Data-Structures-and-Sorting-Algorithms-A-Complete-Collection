#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int array[MAX_SIZE];
int topN = -1;

void push(int x){
if (topN == MAX_SIZE - 1){
    printf("Stack Overflow! Warning\n");
}
else{
    topN++;
    array[topN] = x;
    printf("Number pushed onto the stack is: %d\n", x);
    }
}

int pop(){
if (topN == -1){
    printf("Stack Underflow! Warning\n");
    return -1;
}
else{
    int poppedN = array[topN];
    topN--;
    return poppedN;
}
}

int top(){
return array[topN];
}

int isEmpty(){
if(topN==-1){
    return 1;
}
else{
    return 0;
}
}

int main(){

push(10);
push(20);
push(30);
push(40);
push(50);


printf("Top element: %d\n", top());

printf("%d popped out of the stack\n", pop());
printf("%d popped out of the stack\n", pop());

printf("New top element: %d\n", top());

printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

return 0;
}
