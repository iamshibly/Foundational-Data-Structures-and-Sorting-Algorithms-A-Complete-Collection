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

void del_position(struct node **head, int position){

    struct node *current = *head;
    struct node *previous = *head;

    if(head == NULL)
        printf("List is empty");

    else if(position == 1){//to delete the first node

        *head = current ->link;
        free(current);
        current = NULL;

    }

    else{

        while(position != 1){

            previous = current;
            current = current ->link;
            position--;

        }

        previous -> link = current -> link;
        free(current);
        current = NULL;

    }

}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head -> data = 15;
    head -> link = NULL;

    struct node *ptr = head;
    ptr = add_Node(ptr,25);
    ptr = add_Node(ptr,76);
    ptr = add_Node(ptr,99);

    int position = 3;
    del_position(&head,position);

    ptr = head;

    printf("Data: ");

    while(ptr != NULL){

        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }

return 0;

}
