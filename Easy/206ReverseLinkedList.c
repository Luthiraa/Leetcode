#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value; 
    int * next;
}Node;


int * createNode(int value){
    Node * newnode = malloc(sizeof(Node));
    if (newnode !=NULL){
        newnode ->value = value; 
        newnode->next = NULL;
    }
    return newnode;
}

int main(void){
    Node * head = NULL;
    head = createNode(1);
    head->next = createNode(2);

    printf("%d ->>>%d", head->value,head->next->value);
}