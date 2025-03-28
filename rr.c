#include <stdio.h>
#include <stdbool.h>

void findRoundRobin(int n, int bt[], int quantum, int tat[], int wt[]) {
    int remaining_bt[n], t = 0, i;
    for (i = 0; i < n; i++) remaining_bt[i] = bt[i];
    bool done;

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
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }
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
    int n, quantum, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], tat[n], wt[n];

    printf("Enter burst times for %d processes: ", n);
    for (i = 0; i < n; i++) scanf("%d", &burst_time[i]);

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    findRoundRobin(n, burst_time, quantum, tat, wt);
    displayResults(n, tat, wt);

    return 0;
}

