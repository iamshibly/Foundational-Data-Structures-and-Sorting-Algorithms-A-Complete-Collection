#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *link;

};

struct node *add_Node(struct node *ptr, int data){

    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;

}

struct node *revers(struct node *head){

    struct node *previous = NULL;
    struct node *current = NULL;

    while(head != NULL){

        current = head -> link;
        head -> link = previous;
        previous = head;
        head = current;

    }

    head = previous;
    return head;

}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head -> data = 15;
    head -> link = NULL;

    struct node *ptr = head;
    ptr = add_Node(ptr,25);
    ptr = add_Node(ptr,56);
    ptr = add_Node(ptr,98);

    head = revers(head);

    ptr = head;

    if(head == NULL){

        printf("The list is Empty");

    }

    else{

        printf("Data: ");
        while(ptr != NULL){

            printf("%d ", ptr -> data);
            ptr = ptr -> link;

        }

    }

return 0;

}
