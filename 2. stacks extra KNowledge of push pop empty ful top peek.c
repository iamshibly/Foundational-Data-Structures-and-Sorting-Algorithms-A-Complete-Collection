#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];
int topN = -1;

// Function to push an element onto the stack
void push(int x) {
    if (topN == MAX_SIZE - 1) {
        // Stack overflow
        printf("Stack Overflow! Warning\n");
    } else {
        topN++;
        stack[topN] = x;
        printf("%d pushed onto the stack\n", x);
    }
}

// Function to pop an element from the stack
int pop() {
    if (topN == -1) {
        // Stack underflow
        printf("Stack Underflow! Warning\n");
        return -1; // Return an invalid value (you may choose a different approach)
    } else {
        int poppedElement = stack[topN];
        topN--;
        return poppedElement;
    }
}

// Function to get the top elemenf the stack without removing it
int top() {
    if (topN == -1) {
        // Stack is empty
        printf("Stack is empty\n");
        return -1; // Return an invalid value (you may choose a different approach)
    }
    else {

        return stack[topN];
    }
}

// Function to check if the stack is empty
int isEmpty() {
    if(topN==-1){
        return 1;}
        else{
        return 0;
    }
}
int isFull(){
    return topN== MAX_SIZE-1;}

int main() {

    push(10);
    push(20);
    push(30);
    push(50);
    push(60);
    printf("Top element: %d\n", top());  // Should print: 60

    // Print the top element without removing it

    // Pop some elements
    printf("%d popped out of the stack\n", pop());  // Popped: 60
    printf("%d popped out of the stack\n", pop());  // Popped: 50

    // Print the new top element without removing it
    printf("New top element: %d\n", top());  // Should print: 30

printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is the stack full? %s\n", isFull() ? "Yes" : "No");


    return 0;
}
