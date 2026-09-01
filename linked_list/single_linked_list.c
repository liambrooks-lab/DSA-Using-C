#include <stdlib.h>
#include <stdio.h>

struct Node {
    int nodeDataField;
    struct Node* linkPointerAddress;
};

void dynamicInsertAtEnd(struct Node** rootHeadRef, int assignedValue) {
    struct Node* allocatedNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* internalPointerTracker = *rootHeadRef;
    
    allocatedNode->nodeDataField = assignedValue;
    allocatedNode->linkPointerAddress = NULL;

    if (*rootHeadRef == NULL) {
        *rootHeadRef = allocatedNode;
        return;
    }
    while (internalPointerTracker->linkPointerAddress != NULL) {
        internalPointerTracker = internalPointerTracker->linkPointerAddress;
    }
    internalPointerTracker->linkPointerAddress = allocatedNode;
}

void renderSingleLinkedList(struct Node* entryPointer) {
    printf("\n--- Single Linked Data Structure Streams ---\n");
    while (entryPointer != NULL) {
        printf("[%d] -> ", entryPointer->nodeDataField);
        entryPointer = entryPointer->linkPointerAddress;
    }
    printf("NULL (End Of Stream)\n");
}

int main() {
    struct Node* primaryHeadNode = NULL;
    int selection, elementInput;
    while(1) {
        printf("\n== Custom Dynamic SLL Architecture Interface ==\n1. Append Storage Element\n2. Stream Display Data\n3. Clear Runtime Environment\nChoice: ");
        scanf("%d", &selection);
        if(selection == 3) break;
        if(selection == 1) {
            printf("Enter node integer context: ");
            scanf("%d", &elementInput);
            dynamicInsertAtEnd(&primaryHeadNode, elementInput);
        } else if(selection == 2) {
            renderSingleLinkedList(primaryHeadNode);
        }
    }
    return 0;
}