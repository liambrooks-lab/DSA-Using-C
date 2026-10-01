#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];      /* board[row] = column of the queen in that row */
int n, count = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == row - i)
            return 0;
    }
    return 1;
}

void printSolution(void) {
    printf("\nSolution %d:\n", count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", board[i] == j ? 'Q' : '.');
        printf("\n");
    }
}

void solve(int row) {
    if (row == n) {
        count++;
        printSolution();
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main(void) {
    printf("Enter the value of N (1 to %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input.\n");
        return 1;
    }

    solve(0);

    if (count == 0)
        printf("\nNo solution exists for N = %d.\n", n);
    else
        printf("\nTotal solutions for N = %d: %d\n", n, count);
    return 0;
}