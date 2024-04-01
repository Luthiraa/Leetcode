#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char new[50];
    printf("Input please: ");
    fgets(new, sizeof new, stdin);

    int j = 0;
    char reverse[50];

    for (int i = strlen(new) - 1; i >= 0; i--) { //length of the string in new sizeof returns rize n byte where strlen is size of null terminating string
        reverse[j] = new[i];
        printf("%c ", reverse[j]);
        j++;
     
    }

}