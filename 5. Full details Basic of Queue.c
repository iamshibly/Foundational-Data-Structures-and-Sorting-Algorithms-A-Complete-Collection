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
    exit(1);
else
    return queue[front];
}
void print(){
int i;
if(isEmpty()){
    exit(1);}
else{
    printf("Queue: \n");
    for(i=front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
}
 int main(){
 int choice,data;
 while(1){
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print the first element\n");
    printf("4. Print all the elements\n");
    printf("5. Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
case 1:
    printf("Enter the element to be added in the queue: ");
    scanf("%d", &data);
    enqueue(data);
    printf("Element is added in the queue successfully.\n");
    break;
case 2:
    data=dequeue();
    printf("Deleted element is: %d\n", data);
    break;
case 3:
    printf("The first element of the queue is %d\n", peek());
    break;
case 4:
    print();
    break;
case 5:
    exit(1);
default:
    printf("Wrong choice\n");
    }
 }
 return 0;
 }
