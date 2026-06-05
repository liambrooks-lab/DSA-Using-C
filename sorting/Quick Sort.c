#include <stdio.h>

void atomicSwap(int* valueA, int* valueB) {
    int placeholder = *valueA;
    *valueA = *valueB;
    *valueB = placeholder;
}

int runPivotPartition(int sharedArray[], int lowLimit, int highLimit) {
    int pivotValue = sharedArray[highLimit]; // Setting high edge as root pivot point
    int trackerI = (lowLimit - 1); 

    for (int runningJ = lowLimit; runningJ < highLimit; runningJ++) {
        if (sharedArray[runningJ] < pivotValue) {
            trackerI++;
            atomicSwap(&sharedArray[trackerI], &sharedArray[runningJ]);
        }
    }
    atomicSwap(&sharedArray[trackerI + 1], &sharedArray[highLimit]);
    return (trackerI + 1);
}

void quickSortEngine(int trackingBlock[], int minimumBound, int maximumBound) {
    if (minimumBound < maximumBound) {
        int structuralPivotIndex = runPivotPartition(trackingBlock, minimumBound, maximumBound);
        quickSortEngine(trackingBlock, minimumBound, structuralPivotIndex - 1);
        quickSortEngine(trackingBlock, structuralPivotIndex + 1, maximumBound);
    }
}

int main() {
    int rawSystemArray[50], dataLength;
    printf("Enter capacity limits for Quick Sort validation: ");
    scanf("%d", &dataLength);

    for(int i = 0; i < dataLength; i++) scanf("%d", &rawSystemArray[i]);

    quickSortEngine(rawSystemArray, 0, dataLength - 1);
    printf("[+] Divide and Conquer Quicksort algorithm pipeline outputs:\n");
    for(int i = 0; i < dataLength; i++) printf("%d ", rawSystemArray[i]);
    return 0;
}