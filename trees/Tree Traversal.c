#include <stdio.h>
#include <stdlib.h>

struct BinaryNodeStructure {
    int coreDataMetrics;
    struct BinaryNodeStructure* leftBranchLink;
    struct BinaryNodeStructure* rightBranchLink;
};

struct BinaryNodeStructure* generateTreeNodeInstance(int assignedValue) {
    struct BinaryNodeStructure* allocatedMemoryInstance = (struct BinaryNodeStructure*)malloc(sizeof(struct BinaryNodeStructure));
    allocatedMemoryInstance->coreDataMetrics = assignedValue;
    allocatedMemoryInstance->leftBranchLink = NULL;
    allocatedMemoryInstance->rightBranchLink = NULL;
    return allocatedMemoryInstance;
}

void handleInorderSequence(struct BinaryNodeStructure* currentActiveNode) {
    if (currentActiveNode == NULL) return;
    handleInorderSequence(currentActiveNode->leftBranchLink);
    printf("%d -> ", currentActiveNode->coreDataMetrics);
    handleInorderSequence(currentActiveNode->rightBranchLink);
}

void handlePreorderSequence(struct BinaryNodeStructure* currentActiveNode) {
    if (currentActiveNode == NULL) return;
    printf("%d -> ", currentActiveNode->coreDataMetrics);
    handlePreorderSequence(currentActiveNode->leftBranchLink);
    handlePreorderSequence(currentActiveNode->rightBranchLink);
}

void handlePostorderSequence(struct BinaryNodeStructure* currentActiveNode) {
    if (currentActiveNode == NULL) return;
    handlePostorderSequence(currentActiveNode->leftBranchLink);
    handlePostorderSequence(currentActiveNode->rightBranchLink);
    printf("%d -> ", currentActiveNode->coreDataMetrics);
}

int main() {
    struct BinaryNodeStructure* binaryTreeExecutionRoot = generateTreeNodeInstance(100);
    binaryTreeExecutionRoot->leftBranchLink = generateTreeNodeInstance(50);
    binaryTreeExecutionRoot->rightBranchLink = generateTreeNodeInstance(150);

    printf("\n[+] Structured Inorder Verification Stream: ");
    handleInorderSequence(binaryTreeExecutionRoot); printf("END\n");

    printf("[+] Structured Preorder Verification Stream: ");
    handlePreorderSequence(binaryTreeExecutionRoot); printf("END\n");

    printf("[+] Structured Postorder Verification Stream: ");
    handlePostorderSequence(binaryTreeExecutionRoot); printf("END\n");
    return 0;
}