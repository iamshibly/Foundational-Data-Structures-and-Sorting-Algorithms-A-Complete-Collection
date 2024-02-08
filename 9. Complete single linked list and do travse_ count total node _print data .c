#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
// Method 01- this method is time consuming
/*int main(){

    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second -> data = 60;
    second -> link = NULL;
    head -> link = second;

    struct node *third = malloc(sizeof(struct node));
    third -> data = 77;
    third -> link = NULL;
    second -> link = third;

    printf("Output= %d\n", head -> data);
    printf("Output= %d\n", second -> data);
    printf("Output= %d\n", third -> data);

return 0;
}*/

void printData_traverse_andCountTotal_node(struct node *head){

    int count = 0;

    if(head == NULL)
        printf("Linked List Is Empty");

    struct node *ptr = NULL;
    ptr = head;
    printf("Data: ");
    while(ptr != NULL){
            count++;// only for count node and traverse
            printf("%d ", ptr -> data);// traverse and print data
            ptr = ptr -> link;

    }

    printf("\nTotal node: %d", count);// only for count node and traverse

}

// Method 2
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

    printData_traverse_andCountTotal_node(head);

return 0;
}
