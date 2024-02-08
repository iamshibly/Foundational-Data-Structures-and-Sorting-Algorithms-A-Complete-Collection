#include<stdio.h>
#include<stdlib.h>
#define MAX 8
int queue[MAX], front=-1, rear=-1;
int enqueue(int data){
if(isFull()){
    printf("Queue Overflow.\n");
    return 0;
}
else{
if(front==-1)
    front=0;
rear++;
queue[rear]=data;
return 1;
}
}
/*int enqueue(int data){
if(isFull()){
    printf("Queue Overflow.\n");
}
else if(front==-1){
front=rear=0;
queue[rear]=data;
}
else {
rear++;
queue[rear]=data;
}
}*/
int dequeue(){
int data;
if(isEmpty()){
    printf("Queue Underflow.\n");
    return 0;
}
else{
data=queue[front];
front++;
return data;
}
}
int isEmpty(){
if(front==-1 || front==rear+1)
    return 1;
else
    return 0;
}
int isFull(){
if(rear==MAX-1)
    return 1;

else
    return 0;
}
int peek(){
if(isEmpty())
    return 0;
else
    return queue[front];
}
void print(){//void traverse()
int i;
if(isEmpty()){
    exit(1);}//return 0;
else{
    printf("Queue: ");
    for(i=front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
}
//to delete all the queue at once*************************************
/*void emptyQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}*/
 int main(){
 enqueue(30);
 enqueue(50);
 enqueue(70);
 enqueue(80);
 enqueue(100);
 enqueue(66);
 enqueue(77);
 printf("The first element of the queue is %d\n", peek());
 print();
 printf("Deleted element is: %d\n", dequeue());
 print();
 printf("Is the Queue empty? %s\n", isEmpty() ? "Yes" : "No");
 printf("Is the Queue full? %s\n", isFull() ? "Yes" : "No");
 print();
 //emptyQueue();
 return 0;
 }

