#include <stdio.h>
#define MAX_SIZE 50

// Function prototypes to maintain standard design principles
void processOneDArray();
void processTwoDMatrix();

int main() {
    int choice;
    printf("=== Intermediate Array Operations Hub ===\n");
    printf("1. Execute 1D Array Core Operations\n");
    printf("2. Execute 2D Matrix Core Operations\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: processOneDArray(); break;
        case 2: processTwoDMatrix(); break;
        default: printf("[-] Invalid tracking choice execution terminated.\n");
    }
    return 0;
}

void processOneDArray() {
    int arr[MAX_SIZE], n, sum = 0;
    float average;

    printf("\nEnter total number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Initializing tracking loop for safe insertion
    printf("Enter %d array elements:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / n;
    printf("\n--- Metrics Computation ---\n");
    printf("[+] Aggregated Sum: %d\n", sum);
    printf("[+] Calculated Average: %.2f\n", average);
}

void processTwoDMatrix() {
    int matrix[10][10], rows, cols;
    
    printf("\nEnter Matrix Row and Column configurations: ");
    scanf("%d %d", &rows, &cols);

    // Dynamic extraction of matrix elements
    printf("Populate the matrix metadata:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n--- Computed Adjacency/Matrix View ---\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}