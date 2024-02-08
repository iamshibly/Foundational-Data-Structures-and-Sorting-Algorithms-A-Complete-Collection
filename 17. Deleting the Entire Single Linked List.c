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

struct node *del_list(struct node *head){

    if(head == NULL)
        printf("List is empty");

    else {

        struct node *temp = head;
        while(temp != NULL){

            temp = temp -> link;
            free(head);
            head = temp;

        }

    }

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

    head = del_list(head);

    ptr = head;

    if(head == NULL)

        printf("The list is Empty");

return 0;
}
