#include <stdio.h>
#include <stdlib.h>

int main(void){
    char new [50];

    printf("Input string pls: ");
    fgets(new, sizeof new, stdin);
    int i = 0; 
    while(new[i]!='\0'){
        printf("%c ", new[i]);
        i++;
    }


}