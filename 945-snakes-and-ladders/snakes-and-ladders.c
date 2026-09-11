#include <stdlib.h>

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int total = n * n;

    int* visited = calloc(total + 1, sizeof(int));
    int* queue = malloc((total + 1) * sizeof(int));

    int front = 0;
    int rear = 0;

    queue[rear++] = 1;
    visited[1] = 1;

    int moves = 0;

    while (front < rear) {
        int levelSize = rear - front;

        for (int k = 0; k < levelSize; k++) {
            int current = queue[front++];

            if (current == total) {
                free(visited);
                free(queue);
                return moves;
            }

            for (int dice = 1; dice <= 6; dice++) {
                int next = current + dice;

                if (next > total)
                    break;

                // Convert square number to board coordinates.
                int row = n - 1 - (next - 1) / n;
                int col = (next - 1) % n;

                if ((n - 1 - row) % 2 == 1)
                    col = n - 1 - col;

                // Ladder or snake
                if (board[row][col] != -1)
                    next = board[row][col];

                if (!visited[next]) {
                    visited[next] = 1;
                    queue[rear++] = next;
                }
            }
        }

        moves++;
    }

    free(visited);
    free(queue);

    return -1;
}