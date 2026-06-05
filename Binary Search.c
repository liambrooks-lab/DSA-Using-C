#include <stdio.h>

// Case: O(log N)
int executionBinarySearch(const int sortedData[], int lowerBound, int upperBound, int target) {
    while (lowerBound <= upperBound) {
        int midPoint = lowerBound + (upperBound - lowerBound) / 2; // Prevents generic overflow issues

        if (sortedData[midPoint] == target) return midPoint;
        if (sortedData[midPoint] < target) lowerBound = midPoint + 1; // Shifting pointer to higher block
        else upperBound = midPoint - 1; // Drop lower execution segment
    }
    return -1;
}

int main() {
    int sequence[50], length, targetKey;
    printf("Enter size of pre-sorted sequence array: ");
    scanf("%d", &length);

    printf("Enter elements in perfectly sorted ascending pattern:\n");
    for(int i = 0; i < length; i++) scanf("%d", &sequence[i]);

    printf("Enter targeted search data: ");
    scanf("%d", &targetKey);

    int position = executionBinarySearch(sequence, 0, length - 1, targetKey);
    if(position != -1) printf("[+] Target detected inside pipeline at index: %d\n", position);
    else printf("[-] Core missing element across binary spectrum.\n");
    return 0;
}