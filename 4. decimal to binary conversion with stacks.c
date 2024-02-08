
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX];
int top=-1;

int isFull(){
if(top==MAX-1)
{
    return 1;
}
else{
    return 0;
}
}

int isEmpty(){
if(top==-1)
{
    return 1;
}
else{
    return 0;
}
}

void push(int x){
if(isFull()){
    printf("Stack Overflow.");
    exit(1);
}
top++;
stack[top]=x;
}

int pop(){
int val;
if(isEmpty()){
    printf("Stack Underflow.");
    exit(1);
}
val=stack[top];
top--;
return val;
}

void binaryC(int num){
// below this while function we are pushing all the remainders into a stack by calling push function
while(num!=0){
    push(num%2);
    num=num/2;
} //The while below is popping out all the remainders from the stack and printing
printf("Binary Number: ");
while(top!=-1){
    printf("%d ",pop());
}
}

int main(){
int decimalN;
printf("Please enter a positive number: ");
scanf("%d",&decimalN);

binaryC(decimalN);
return 0;
}
