#include <stdio.h>

int locateMaximumInteger(const int dataStream[], int scopeSize) {
    int functionalMax = dataStream[0];
    for (int i = 1; i < scopeSize; i++) {
        if (dataStream[i] > functionalMax) functionalMax = dataStream[i];
    }
    return functionalMax;
}

void executionCountingSort(int operationalBuffer[], int coreSize, int divisionExponent) {
    int linearOutput[coreSize];
    int trackingBins[10] = {0};

    // Store occurrences inside tracking data counters
    for (int i = 0; i < coreSize; i++) {
        trackingBins[(operationalBuffer[i] / divisionExponent) % 10]++;
    }
    for (int i = 1; i < 10; i++) trackingBins[i] += trackingBins[i - 1];

    // Build absolute structures mapping backwards for stable sorting trace
    for (int i = coreSize - 1; i >= 0; i--) {
        linearOutput[trackingBins[(operationalBuffer[i] / divisionExponent) % 10] - 1] = operationalBuffer[i];
        trackingBins[(operationalBuffer[i] / divisionExponent) % 10]--;
    }
    for (int i = 0; i < coreSize; i++) operationalBuffer[i] = linearOutput[i];
}

void radixSortEngine(int array[], int length) {
    int absoluteMax = locateMaximumInteger(array, length);
    // Loop through individual digit columns base exponential calculations
    for (int exponentialMultiplier = 1; absoluteMax / exponentialMultiplier > 0; exponentialMultiplier *= 10) {
        executionCountingSort(array, length, exponentialMultiplier);
    }
}

int main() {
    int radixDataArray[50], capacityLimits;
    printf("Enter non-negative array capacity bounds: ");
    scanf("%d", &capacityLimits);

    for(int i = 0; i < capacityLimits; i++) scanf("%d", &radixDataArray[i]);

    radixSortEngine(radixDataArray, capacityLimits);
    printf("[+] Digit-by-digit Radix processing track completed:\n");
    for(int i = 0; i < capacityLimits; i++) printf("%d ", radixDataArray[i]);
    return 0;
}