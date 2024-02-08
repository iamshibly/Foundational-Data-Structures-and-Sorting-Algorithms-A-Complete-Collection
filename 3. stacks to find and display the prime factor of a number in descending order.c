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

void push(int n){
if(isFull()){
    printf("Stack Overflow.");
    exit(1);
}
top++;
stack[top]=n;
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

void prime_fact(int num){
int i=2;
// below this we are pushing all the prime factors of a number into a stack.
while(num!=1){
    while(num%i==0){
        push(i);
        num=num/i;
    }
    i++;
} //The while below is popping out all the prime factor from the stack
printf("Prime factors of the number in descending order are as follows: ");
while(top!=-1){
    printf("%d ",pop());
}
}

int main(){
int number;
printf("Please enter a positive number: ");
scanf("%d",&number);

prime_fact(number);
return 0;
}
