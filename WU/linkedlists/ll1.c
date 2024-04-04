#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value; 
    struct Node * next;
}Node; 

Node * createNode (int value){
    Node * newnode = malloc(sizeof(Node));
    if (newnode!=NULL){
        newnode ->value = value; 
        newnode->next = NULL; 
    }
    return newnode;
}

int main(void){
    
    int numnodes; 
    printf("Enter number of nodes: ");
    scanf(" %d",&numnodes);

    Node * head = NULL;
    Node * temp = NULL;
    int getvalue;
    for (int i =0; i<numnodes; i++){
        printf("Enter value: ");
        scanf(" %d",&getvalue);
        if(i == 0){
            head = createNode(getvalue);
            temp = head;
        } else {
            temp->next = createNode(getvalue);
            temp = temp->next;
        }
    }
    temp = head;
    while(temp != NULL){
        printf("Value : %d\n", temp->value);
        temp = temp->next;
    }
    return 0;
}
