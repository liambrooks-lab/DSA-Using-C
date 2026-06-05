#include <stdio.h>
#define STORAGE_POOL 5

int coreStackFrame[STORAGE_POOL];
int stackFramePointer = -1; // Standard stack trace index configurations

void safePush(int insertionData) {
    if (stackFramePointer == STORAGE_POOL - 1) {
        printf("[-] Thread Error: High Overflow condition detected inside storage limits.\n");
    } else {
        coreStackFrame[++stackFramePointer] = insertionData;
        printf("[+] Data packet logged inside stack frames: %d\n", insertionData);
    }
}

void validatedPop() {
    if (stackFramePointer == -1) {
        printf("[-] Thread Error: Underflow operational blocks discovered on execution stack.\n");
    } else {
        printf("[+] Freed/Popped context mapping element: %d\n", coreStackFrame[stackFramePointer--]);
    }
}

void viewActiveStackState() {
    if (stackFramePointer == -1) {
        printf("[*] Pipeline Warning: Active execution framework is blank.\n");
    } else {
        printf("\n--- Current Stack Frame Structures ---\n");
        for (int referencePointer = stackFramePointer; referencePointer >= 0; referencePointer--) {
            printf("|  %d  |\n", coreStackFrame[referencePointer]);
        }
        printf("-------\n");
    }
}

int main() {
    int optionMenu, trackingValue;
    while(1) {
        printf("\n== System Stack Core Interlock Engine ==\n1. PUSH\n2. POP\n3. DISPLAY\n4. TERMINATE RUN\nSelect Task: ");
        scanf("%d", &optionMenu);
        if(optionMenu == 4) break;
        switch(optionMenu) {
            case 1: printf("Enter value: "); scanf("%d", &trackingValue); safePush(trackingValue); break;
            case 2: validatedPop(); break;
            case 3: viewActiveStackState(); break;
            default: printf("Unknown command registers execution fail.\n");
        }
    }
    return 0;
}