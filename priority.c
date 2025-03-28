#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int pr[]) {
    int temp, temp_bt, temp_pr;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp_pr = pr[i];
                pr[i] = pr[j];
                pr[j] = temp_pr;
                
                temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int n, int bt[], int pr[]) {
    int wt[n], tat[n];
    findWaitingTime(n, bt, wt, pr);
    findTurnAroundTime(n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n];
    printf("Enter burst times and priorities:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d - Priority: ", i + 1);
        scanf("%d", &pr[i]);
    }

    findAverageTime(n, bt, pr);
    return 0;
}

