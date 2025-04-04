#include <stdio.h>
#include <stdbool.h>

void findRoundRobin(int n, int bt[], int quantum, int tat[], int wt[], int ct[]) {
    int remaining_bt[n], t = 0, i;
    for (i = 0; i < n; i++) remaining_bt[i] = bt[i];
    bool done;
    int completion[n]; // Store the completion time

    while (true) {
        done = true;
        for (i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = false;
                if (remaining_bt[i] > quantum) {
                    t += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    t += remaining_bt[i];
                    wt[i] = t - bt[i];
                    completion[i] = t; // Store completion time
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        ct[i] = completion[i]; //copy calculated completion time to ct array.
    }
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
    int n, quantum, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], tat[n], wt[n], ct[n];

    printf("Enter burst times for %d processes: ", n);
    for (i = 0; i < n; i++) scanf("%d", &burst_time[i]);

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    findRoundRobin(n, burst_time, quantum, tat, wt, ct);
    displayResults(n, tat, wt, ct);

    return 0;
}
