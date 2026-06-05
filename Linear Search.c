#include <stdio.h>

// Performance: O(n) worst-case processing complexity
int linearSearch(const int dataset[], int size, int target) {
    for (int index = 0; index < size; index++) {
        if (dataset[index] == target) {
            return index; // Returning reference index location immediately
        }
    }
    return -1; // Target missing inside data arrays
}

int main() {
    int totalElements, targetElement;
    int customDataset[100];

    printf("Enter sequence data limit: ");
    scanf("%d", &totalElements);

    printf("Populate %d linear sequence array nodes:\n", totalElements);
    for(int i = 0; i < totalElements; i++) {
        scanf("%d", &customDataset[i]);
    }

    printf("Enter the element value to search: ");
    scanf("%d", &targetElement);

    int resultIndex = linearSearch(customDataset, totalElements, targetElement);
    if(resultIndex != -1) {
        printf("[+] Trace Found: Component matched at absolute index: %d\n", resultIndex);
    } else {
        printf("[-] Trace Failure: Target mismatch across entire dataset arrays.\n");
    }
    return 0;
}