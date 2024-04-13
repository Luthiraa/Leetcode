#include <stdio.h>
#include <stdlib.h>

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    // Calculate total apples
    int totalApples = 0; 
    for (int i = 0; i < appleSize; i++){
        totalApples += apple[i];
    }

    // Calculate total capacity
    int totalCapacity = 0;
    for (int i = 0; i < capacitySize; i++){
        totalCapacity += capacity[i];
    }

    // If total capacity is less than total apples, return -1
    if (totalCapacity < totalApples) {
        return -1;
    }

    // Sort capacity
    int * sortedCapacity = malloc(capacitySize * sizeof(int));
    for (int i = 0; i < capacitySize; i++){
        sortedCapacity[i] = capacity[i];
    }
    for (int i = capacitySize - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (sortedCapacity[j] > sortedCapacity[j + 1]){
                int temp = sortedCapacity[j];
                sortedCapacity[j] = sortedCapacity[j + 1];
                sortedCapacity[j + 1] = temp;
            }
        }
    }

    // Calculate minimum boxes
    int numBoxes = 0; 
    for (int i = 0, j = capacitySize - 1; i < capacitySize; i++, j--){
        if (totalApples == 0){
            free(sortedCapacity);
            return numBoxes;
        } else {
            totalApples -= sortedCapacity[j];
            numBoxes++;
        }
    }

    free(sortedCapacity);
    return numBoxes;   
}

int main(void){
    int apples [] = {1, 2, 4, 5, 9};
    int capacity [] = {10, 5, 12};
    int appleSize = sizeof(apples) / sizeof(int);
    int capacitySize = sizeof(capacity) / sizeof(int);
    int min = minimumBoxes(apples, appleSize, capacity, capacitySize);
    if (min == -1) {
        printf("Not enough capacity for all apples.\n");
    } else {
        printf("Minimum number of boxes: %d\n", min);
    }
}