#include <stdio.h>
#define GRAPH_MATRIX_SIZE 10

void configureEmptyGraphLayout(int adjacencyBuffer[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE], int totalVerticesCount) {
    for (int dimensionX = 0; dimensionX < totalVerticesCount; dimensionX++) {
        for (int dimensionY = 0; dimensionY < totalVerticesCount; dimensionY++) {
            adjacencyBuffer[dimensionX][dimensionY] = 0;
        }
    }
}

void linkingBidirectionalEdges(int adjMatrix[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE], int sourceVertex, int destinationVertex) {
    adjMatrix[sourceVertex][destinationVertex] = 1;
    adjMatrix[destinationVertex][sourceVertex] = 1; // Direct bidirectional link matrix mapping mapping
}

void printConfiguredGraphMatrix(int trackingGrid[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE], int scopeLimit) {
    printf("\n--- System Graph Adjacency Matrix Mapping Outputs ---\n");
    for (int rowPointer = 0; rowPointer < scopeLimit; rowPointer++) {
        for (int colPointer = 0; colPointer < scopeLimit; colPointer++) {
            printf("%d ", trackingGrid[rowPointer][colPointer]);
        }
        printf("\n");
    }
}

int main() {
    int workingMatrixGrid[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE];
    int nodesVertexCount = 4;

    configureEmptyGraphLayout(workingMatrixGrid, nodesVertexCount);
    linkingBidirectionalEdges(workingMatrixGrid, 0, 1);
    linkingBidirectionalEdges(workingMatrixGrid, 0, 3);
    linkingBidirectionalEdges(workingMatrixGrid, 1, 2);
    linkingBidirectionalEdges(workingMatrixGrid, 2, 3);

    printConfiguredGraphMatrix(workingMatrixGrid, nodesVertexCount);
    return 0;
}