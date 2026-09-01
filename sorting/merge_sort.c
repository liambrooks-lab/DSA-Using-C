#include <stdio.h>

// Divide and conquer approach tracking arrays
void pipelineMerge(int pipelineBuffer[], int startIndex, int partitionIndex, int endIndex) {
    int subArrayLeftSize = partitionIndex - startIndex + 1;
    int subArrayRightSize = endIndex - partitionIndex;

    int LeftTempStack[subArrayLeftSize], RightTempStack[subArrayRightSize];

    for (int indexI = 0; indexI < subArrayLeftSize; indexI++)
        LeftTempStack[indexI] = pipelineBuffer[startIndex + indexI];
    for (int indexJ = 0; indexJ < subArrayRightSize; indexJ++)
        RightTempStack[indexJ] = pipelineBuffer[partitionIndex + 1 + indexJ];

    int leftPointer = 0, rightPointer = 0, targetMergedPointer = startIndex;
    while (leftPointer < subArrayLeftSize && rightPointer < subArrayRightSize) {
        if (LeftTempStack[leftPointer] <= RightTempStack[rightPointer]) {
            pipelineBuffer[targetMergedPointer++] = LeftTempStack[leftPointer++];
        } else {
            pipelineBuffer[targetMergedPointer++] = RightTempStack[rightPointer++];
        }
    }

    // Capture overflow or residual data fragments inside stack layers
    while (leftPointer < subArrayLeftSize) pipelineBuffer[targetMergedPointer++] = LeftTempStack[leftPointer++];
    while (rightPointer < subArrayRightSize) pipelineBuffer[targetMergedPointer++] = RightTempStack[rightPointer++];
}

void mergeSortExecution(int buffer[], int startingIndex, int endingIndex) {
    if (startingIndex < endingIndex) {
        int middlePivot = startingIndex + (endingIndex - startingIndex) / 2;
        mergeSortExecution(buffer, startingIndex, middlePivot);
        mergeSortExecution(buffer, middlePivot + 1, endingIndex);
        pipelineMerge(buffer, startingIndex, middlePivot, endingIndex);
    }
}

int main() {
    int trackingDataset[50], elementSize;
    printf("Merge Sort tracking node capacity: ");
    scanf("%d", &elementSize);

    for(int i = 0; i < elementSize; i++) scanf("%d", &trackingDataset[i]);

    mergeSortExecution(trackingDataset, 0, elementSize - 1);
    printf("[+] Highly parallelized recursive merge sequence compiled:\n");
    for(int i = 0; i < elementSize; i++) printf("%d ", trackingDataset[i]);
    return 0;
}