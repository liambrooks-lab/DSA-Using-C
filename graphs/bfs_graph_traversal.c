#include <stdio.h>
#define NODE_MAX 5

void runBreadthFirstSearchTraversal(int entryPointVertex, int targetGraphGrid[NODE_MAX][NODE_MAX]) {
    int trackVisitedBits[NODE_MAX] = {0};
    int executionFIFOQueue[NODE_MAX];
    int trackingQueueFront = 0, trackingQueueRear = 0;

    printf("\nInitializing Breadth First Search (BFS) Framework Flow: ");
    
    trackVisitedBits[entryPointVertex] = 1;
    executionFIFOQueue[trackingQueueRear++] = entryPointVertex;

    while (trackingQueueFront < trackingQueueRear) {
        int contextualActiveNode = executionFIFOQueue[trackingQueueFront++];
        printf("%d => ", contextualActiveNode);

        for (int dimensionalY = 0; dimensionalY < NODE_MAX; dimensionalY++) {
            if (targetGraphGrid[contextualActiveNode][dimensionalY] == 1 && !trackVisitedBits[dimensionalY]) {
                executionFIFOQueue[trackingQueueRear++] = dimensionalY;
                trackVisitedBits[dimensionalY] = 1; // Setting tracking flag safe register levels
            }
        }
    }
    printf("END_OF_QUEUE\n");
}

int main() {
    int environmentGraph[NODE_MAX][NODE_MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    runBreadthFirstSearchTraversal(0, environmentGraph);
    return 0;
}