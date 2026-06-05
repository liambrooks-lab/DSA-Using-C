#include <stdio.h>
#include <stdlib.h>

struct RingNode {
    int dataValueSegment;
    struct RingNode* nextLinkOffset;
};

void structuralRingAppend(struct RingNode** entryHeadLocator, int dataPayload) {
    struct RingNode* uniqueNodeCell = (struct RingNode*)malloc(sizeof(struct RingNode));
    uniqueNodeCell->dataValueSegment = dataPayload;
    
    if (*entryHeadLocator == NULL) {
        *entryHeadLocator = uniqueNodeCell;
        uniqueNodeCell->nextLinkOffset = *entryHeadLocator; // Point back to self to close ring loops
        return;
    }

    struct RingNode* traversalScout = *entryHeadLocator;
    while (traversalScout->nextLinkOffset != *entryHeadLocator) {
        traversalScout = traversalScout->nextLinkOffset;
    }
    traversalScout->nextLinkOffset = uniqueNodeCell;
    uniqueNodeCell->nextLinkOffset = *entryHeadLocator; // Re-link head reference boundary
}

void renderCircularLoopElements(struct RingNode* primaryRootHead) {
    if (primaryRootHead == NULL) {
        printf("[-] Structure Diagnostic: Active structural circular ring list contains 0 items.\n");
        return;
    }
    struct RingNode* trackerMarker = primaryRootHead;
    printf("\n--- Circular Ring Elements Continuous Pipelines ---\n");
    do {
        printf("[%d] -> ", trackerMarker->dataValueSegment);
        trackerMarker = trackerMarker->nextLinkOffset;
    } while (trackerMarker != primaryRootHead);
    printf("(LOOP BACK TO ACTIVE ROOT NODE HEAD)\n");
}

int main() {
    struct RingNode* ringInitializationPointer = NULL;
    structuralRingAppend(&ringInitializationPointer, 55);
    structuralRingAppend(&ringInitializationPointer, 66);
    structuralRingAppend(&ringInitializationPointer, 77);
    renderCircularLoopElements(ringInitializationPointer);
    return 0;
}