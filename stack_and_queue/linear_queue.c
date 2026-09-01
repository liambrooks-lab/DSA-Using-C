#include <stdio.h>
#define LINEAR_LIMIT 5

int sequenceQueue[LINEAR_LIMIT];
int entryHeadPointer = -1, exitTailPointer = -1;

void pushQueue(int targetedValue) {
    if (exitTailPointer == LINEAR_LIMIT - 1) {
        printf("[-] System Exception: Queue linear framework bound limits hit overflow status.\n");
    } else {
        if (entryHeadPointer == -1) entryHeadPointer = 0;
        sequenceQueue[++exitTailPointer] = targetedValue;
        printf("[+] Queue item buffered successfully: %d\n", targetedValue);
    }
}

void popQueue() {
    if (entryHeadPointer == -1 || entryHeadPointer > exitTailPointer) {
        printf("[-] System Exception: Queue memory stack underflow detected.\n");
    } else {
        printf("[+] Successfully extracted sequence block: %d\n", sequenceQueue[entryHeadPointer++]);
    }
}

void renderQueueState() {
    if (entryHeadPointer == -1 || entryHeadPointer > exitTailPointer) {
        printf("[*] Trace Flag: Structural FIFO registers are empty.\n");
    } else {
        printf("\n--- Current Queue Traversal State ---\nFront -> ");
        for (int tracker = entryHeadPointer; tracker <= exitTailPointer; tracker++) {
            printf("[%d] ", sequenceQueue[tracker]);
        }
        printf("<- Rear\n");
    }
}

int main() {
    int userOperation, processElement;
    while(1) {
        printf("\n== Standard Linear FIFO Interface ==\n1. Enqueue\n2. Dequeue\n3. Display State\n4. Exit System\nCommand: ");
        scanf("%d", &userOperation);
        if(userOperation == 4) break;
        switch(userOperation) {
            case 1: printf("Input Data: "); scanf("%d", &processElement); pushQueue(processElement); break;
            case 2: popQueue(); break;
            case 3: renderQueueState(); break;
            default: printf("Error logs tracking active execution commands.\n");
        }
    }
    return 0;
}