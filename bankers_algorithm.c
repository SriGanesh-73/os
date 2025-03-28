#include <stdio.h>
#include <stdbool.h>

void calculateNeed(int processes, int resources, int max[][resources], int allocation[][resources], int need[][resources]) {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void displayTable(int processes, int resources, int allocation[][resources], int max[][resources], int need[][resources], int available[]) {
    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for (int i = 0; i < resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

bool isSafe(int processes, int resources, int allocation[][resources], int need[][resources], int available[]) {
    bool finish[processes];
    for (int i = 0; i < processes; i++) {
        finish[i] = false;
    }

    int work[resources];
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    int safeSequence[processes];
    int count = 0;

    while (count < processes) {
        bool found = false;

        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canFinish = true;
                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("\nThe system is not in a safe state.\n");
            return false;
        }
    }

    printf("\nThe system is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main() {
    int processes, resources;

    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    int allocation[processes][resources];
    int max[processes][resources];
    int need[processes][resources];
    int available[resources];

    printf("\nEnter the Allocation Matrix (row by row):\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter the Max Matrix (row by row):\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the Available Resources (space-separated):\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    calculateNeed(processes, resources, max, allocation, need);
    displayTable(processes, resources, allocation, max, need, available);
    isSafe(processes, resources, allocation, need, available);

    return 0;
}

