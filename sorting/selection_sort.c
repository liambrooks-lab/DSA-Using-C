#include <stdio.h>

void selectionSortEngine(int trackingBuffer[], int length) {
    for (int anchorIndex = 0; anchorIndex < length - 1; anchorIndex++) {
        int lowestValueIndex = anchorIndex; // Assume current index holds lower boundary data
        for (int searchIndex = anchorIndex + 1; searchIndex < length; searchIndex++) {
            if (trackingBuffer[searchIndex] < trackingBuffer[lowestValueIndex]) {
                lowestValueIndex = searchIndex; // Update the memory locator link
            }
        }
        // Swapping data values securely via traditional shift registers
        int storageRegister = trackingBuffer[lowestValueIndex];
        trackingBuffer[lowestValueIndex] = trackingBuffer[anchorIndex];
        trackingBuffer[anchorIndex] = storageRegister;
    }
}

int main() {
    int dataset[50], itemsCount;
    printf("Selection Sort dynamic initialization capacity: ");
    scanf("%d", &itemsCount);

    for(int i = 0; i < itemsCount; i++) scanf("%d", &dataset[i]);

    selectionSortEngine(dataset, itemsCount);
    printf("[+] Selection execution context processed successfully:\n");
    for(int i = 0; i < itemsCount; i++) printf("%d ", dataset[i]);
    return 0;
}