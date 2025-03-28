#include <stdio.h>

void findPriorityScheduling(int n, int bt[], int priority[], int tat[], int wt[]) {
    int i, j, temp;
    int p[n];

    for (i = 0; i < n; i++) p[i] = i;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
}

void displayResults(int n, int tat[], int wt[]) {
    int total_tat = 0, total_wt = 0, i;
    printf("Process\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], priority[n], tat[n], wt[n];

    printf("Enter burst times for %d processes: ", n);
    for (i = 0; i < n; i++) scanf("%d", &burst_time[i]);

    printf("Enter priorities for %d processes: ", n);
    for (i = 0; i < n; i++) scanf("%d", &priority[i]);

    findPriorityScheduling(n, burst_time, priority, tat, wt);
    displayResults(n, tat, wt);

    return 0;
}

