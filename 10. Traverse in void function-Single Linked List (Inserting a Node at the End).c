#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void insert_Atthe_end(struct node *head){

    struct node *ptr, *temp;
    ptr = head;

    temp = malloc(sizeof(struct node));
    temp -> data = 99;
    temp -> link = NULL;

    while(ptr -> link != NULL){
            ptr = ptr -> link;
    }

    ptr -> link = temp;

}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second -> data = 60;
    second -> link = NULL;
    head -> link = second;

    second = malloc(sizeof(struct node));
    second -> data = 77;
    second -> link = NULL;

    head -> link -> link = second;

    insert_Atthe_end(head);

    struct node *current = head;
    while (current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->link;
    }

return 0;
}
