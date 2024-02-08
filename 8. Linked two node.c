#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){

    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second -> data = 60;
    second -> link = NULL;
    head -> link = second;

    printf("Output= %d\n", head -> data);
    printf("Output= %d\n", second -> data);


return 0;
}
