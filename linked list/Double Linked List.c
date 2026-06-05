#include <stdio.h>
#include <stdlib.h>

struct DoubleNode {
    int payloadData;
    struct DoubleNode* nextNodeLink;
    struct DoubleNode* prevNodeLink;
};

void insertAtDoubleLinkedListTail(struct DoubleNode** coreHeadNode, int numericalPayload) {
    struct DoubleNode* targetNodeAllocation = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
    struct DoubleNode* dynamicSeeker = *coreHeadNode;

    targetNodeAllocation->payloadData = numericalPayload;
    targetNodeAllocation->nextNodeLink = NULL;

    if (*coreHeadNode == NULL) {
        targetNodeAllocation->prevNodeLink = NULL;
        *coreHeadNode = targetNodeAllocation;
        return;
    }
    while (dynamicSeeker->nextNodeLink != NULL) {
        dynamicSeeker = dynamicSeeker->nextNodeLink;
    }
    dynamicSeeker->nextNodeLink = targetNodeAllocation;
    targetNodeAllocation->prevNodeLink = dynamicSeeker;
}

void monitorDoubleLinkedListStream(struct DoubleNode* structuralReader) {
    printf("\n[+] Bi-directional structural list state trace:\n");
    while (structuralReader != NULL) {
        printf("NULL <= [%d] => ", structuralReader->payloadData);
        structuralReader = structuralReader->nextNodeLink;
    }
    printf("NULL\n");
}

int main() {
    struct DoubleNode* entryDLLPointer = NULL;
    insertAtDoubleLinkedListTail(&entryDLLPointer, 1024);
    insertAtDoubleLinkedListTail(&entryDLLPointer, 2048);
    monitorDoubleLinkedListStream(entryDLLPointer);
    return 0;
}