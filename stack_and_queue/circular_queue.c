#include <stdio.h>
#define CIR_LIMIT 5

int trackingCircularBuffer[CIR_LIMIT];
int headIndexMarker = -1, tailIndexMarker = -1;

void executeCircularEnqueue(int dataFrame) {
    if ((tailIndexMarker + 1) % CIR_LIMIT == headIndexMarker) {
        printf("[-] Boundary Overflow: Circular layout data bounds reached.\n");
    } else {
        if (headIndexMarker == -1) headIndexMarker = 0;
        tailIndexMarker = (tailIndexMarker + 1) % CIR_LIMIT;
        trackingCircularBuffer[tailIndexMarker] = dataFrame;
        printf("[+] Wrapped data packet locked inside ring slot: %d\n", dataFrame);
    }
}

void executeCircularDequeue() {
    if (headIndexMarker == -1) {
        printf("[-] Boundary Underflow: No tracking records inside circular loops.\n");
    } else {
        printf("[+] Freed data element track slot: %d\n", trackingCircularBuffer[headIndexMarker]);
        if (headIndexMarker == tailIndexMarker) {
            headIndexMarker = tailIndexMarker = -1; // Zero out memory registers on clean sweep
        } else {
            headIndexMarker = (headIndexMarker + 1) % CIR_LIMIT;
        }
    }
}

void viewCircularStructures() {
    if (headIndexMarker == -1) {
        printf("[*] Pipe Report: Ring structural blocks empty.\n");
    } else {
        printf("\n--- Active Ring Memory Frame Slots ---\n");
        int dynamicTracker = headIndexMarker;
        while (1) {
            printf("[%d] Value: %d\n", dynamicTracker, trackingCircularBuffer[dynamicTracker]);
            if (dynamicTracker == tailIndexMarker) break;
            dynamicTracker = (dynamicTracker + 1) % CIR_LIMIT;
        }
    }
}

int main() {
    int choiceRegister, dynamicPayload;
    while(1) {
        printf("\n== High-Availability Circular Ring Array Buffer ==\n1. Circular Enqueue\n2. Circular Dequeue\n3. Display State Map\n4. Kill Thread\nAction: ");
        scanf("%d", &choiceRegister);
        if(choiceRegister == 4) break;
        switch(choiceRegister) {
            case 1: printf("Payload data: "); scanf("%d", &dynamicPayload); executeCircularEnqueue(dynamicPayload); break;
            case 2: executeCircularDequeue(); break;
            case 3: viewCircularStructures(); break;
            default: printf("Operational parsing command error.\n");
        }
    }
    return 0;
}