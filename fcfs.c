#include <stdio.h>

void findFCFS(int n, int bt[], int wt[], int tat[]) {
    int i;
    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void displayResults(int n, int tat[], int wt[]) {
    int total_tat = 0, total_wt = 0, i;
    printf("Process\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, tat[i] - wt[i], tat[i], wt[i]);
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

    int burst_time[n], wt[n], tat[n];

    printf("Enter burst times for %d processes: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    findFCFS(n, burst_time, wt, tat);
    displayResults(n, tat, wt);

    return 0;
}

