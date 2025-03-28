#include <stdio.h>
#include <limits.h>

void findSJFPreemptive(int n, int at[], int bt[], int tat[], int wt[]) {
    int rt[n], complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void displayResults(int n, int tat[], int wt[]) {
    int total_tat = 0, total_wt = 0;
    printf("Process\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], tat[n], wt[n];

    printf("Enter arrival times for %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst times for %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    findSJFPreemptive(n, at, bt, tat, wt);
    displayResults(n, tat, wt);

    return 0;
}

