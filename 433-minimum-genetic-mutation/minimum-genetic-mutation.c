#include <string.h>

int minMutation(char* startGene, char* endGene,
                char** bank, int bankSize) {
    char queue[11][9];
    int steps[11];
    int visited[11] = {0};

    int front = 0;
    int rear = 0;

    strcpy(queue[rear], startGene);
    steps[rear] = 0;
    rear++;

    while (front < rear) {
        char* current = queue[front];
        int currentSteps = steps[front];
        front++;

        if (strcmp(current, endGene) == 0)
            return currentSteps;

        for (int i = 0; i < bankSize; i++) {
            if (visited[i])
                continue;

            int diff = 0;

            for (int j = 0; j < 8; j++) {
                if (current[j] != bank[i][j])
                    diff++;
            }

            if (diff == 1) {
                visited[i] = 1;

                strcpy(queue[rear], bank[i]);
                steps[rear] = currentSteps + 1;
                rear++;
            }
        }
    }

    return -1;
}