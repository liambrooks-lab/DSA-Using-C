#include <stdio.h>
#define VER_LIMIT 6

int trackingVisitedStateArray[VER_LIMIT] = {0};
int internalSystemMatrix[VER_LIMIT][VER_LIMIT] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0}
};

void runDepthFirstSearchTraversal(int operationalNodeIndex) {
    printf("Vertex-[%d] -> ", operationalNodeIndex);
    trackingVisitedStateArray[operationalNodeIndex] = 1; // Mark block index path status as traced

    for (int trackingIndex = 0; trackingIndex < VER_LIMIT; trackingIndex++) {
        if (internalSystemMatrix[operationalNodeIndex][trackingIndex] == 1 && !trackingVisitedStateArray[trackingIndex]) {
            runDepthFirstSearchTraversal(trackingIndex); // Recursive tracking branch operations execution
        }
    }
}

int main() {
    printf("Initializing Depth First Search (DFS) Traversal Pipelines from Node [0]:\n");
    runDepthFirstSearchTraversal(0);
    printf("COMPLETED\n");
    return 0;
}