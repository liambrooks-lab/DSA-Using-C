#include <stdio.h>

void optimizedBubbleSort(int array[], int size) {
    // Flag to trace optimization path; minimizes execution loops if array gets sorted early
    int stateSwapped; 
    for (int step = 0; step < size - 1; step++) {
        stateSwapped = 0;
        for (int index = 0; index < size - step - 1; index++) {
            if (array[index] > array[index + 1]) {
                int registerTemp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = registerTemp;
                stateSwapped = 1;
            }
        }
        if (stateSwapped == 0) break; // Optimization break if array is fully structurally balanced
    }
}

int main() {
    int dataBuffer[50], capacity;
    printf("Bubble Sort Engine initialization length: ");
    scanf("%d", &capacity);

    for(int i = 0; i < capacity; i++) scanf("%d", &dataBuffer[i]);

    optimizedBubbleSort(dataBuffer, capacity);
    printf("[+] Bubble Sort execution block completed:\n");
    for(int i = 0; i < capacity; i++) printf("%d ", dataBuffer[i]);
    return 0;
}