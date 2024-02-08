#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *insertAt_theEnd(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));

    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;

}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *ptr = head;
    ptr = insertAt_theEnd(ptr,60);
    ptr = insertAt_theEnd(ptr,77);
    ptr = insertAt_theEnd(ptr,98);

    ptr = head;

    printf("Data: ");

    while(ptr != NULL){

        printf("%d ", ptr -> data);
        ptr = ptr -> link;

    }

return 0;
}

