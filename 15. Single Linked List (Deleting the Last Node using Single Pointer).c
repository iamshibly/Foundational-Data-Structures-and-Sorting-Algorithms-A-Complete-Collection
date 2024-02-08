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

void del_last(struct node *head){

    if(head == NULL)
        printf("List is empty");

    else if(head -> link == NULL){
        free(head);
        head = NULL;
    }

    else{

    struct node *temp = head;
    while(temp -> link -> link != NULL){

        temp = temp -> link;

    }

    free(temp -> link);
    temp -> link = NULL;

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

    struct node *temp = head;
    del_last(head);

    ptr = head;

    printf("Data: ");

    while(ptr != NULL){

        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }

return 0;
}
