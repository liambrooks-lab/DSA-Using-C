#include <stdio.h>

void insertionSortEngine(int rawData[], int payloadSize) {
    for (int activePointer = 1; activePointer < payloadSize; activePointer++) {
        int targetedKey = rawData[activePointer];
        int comparativeIndex = activePointer - 1;

        // Shift preceding elements backward if larger than current key
        while (comparativeIndex >= 0 && rawData[comparativeIndex] > targetedKey) {
            rawData[comparativeIndex + 1] = rawData[comparativeIndex];
            comparativeIndex--;
        }
        rawData[comparativeIndex + 1] = targetedKey; // Insert tracking target key safe variable
    }
}

int main() {
    int dataSegment[50], allocations;
    printf("Insertion Sort size tracking parameter: ");
    scanf("%d", &allocations);

    for(int i = 0; i < allocations; i++) scanf("%d", &dataSegment[i]);

    insertionSortEngine(dataSegment, allocations);
    printf("[+] Insertion mapping processing complete:\n");
    for(int i = 0; i < allocations; i++) printf("%d ", dataSegment[i]);
    return 0;
}