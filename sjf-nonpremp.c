#include <stdio.h>

void findSJFNonPreemptive(int n, int bt[], int tat[], int wt[], int ct[]) {
    int i, j, temp;
    int p[n];

    for (i = 0; i < n; i++) p[i] = i;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    ct[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        ct[i] = ct[i - 1] + bt[i];
    }
    for (i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
}

void displayResults(int n, int tat[], int wt[], int ct[]) {
    int total_tat = 0, total_wt = 0, i;
    printf("Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, tat[i] - wt[i], ct[i], tat[i], wt[i]);
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

    int burst_time[n], tat[n], wt[n], ct[n];

    printf("Enter burst times for %d processes: ", n);
    for (i = 0; i < n; i++) scanf("%d", &burst_time[i]);

    findSJFNonPreemptive(n, burst_time, tat, wt, ct);
    displayResults(n, tat, wt, ct);

    return 0;
}
