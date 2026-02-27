#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};
//FCFS//
void fcfs(struct Process p[], int n) {
    int time = 0;
    float total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++) {
        if(time < p[i].arrival)
            time = p[i].arrival;

        p[i].completion = time + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        time = p[i].completion;

        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
}
//Non primitive//
void sjf_non_preemptive(struct Process p[], int n) {
    int completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;

    while(completed < n) {
        int idx = -1;
        int min = INT_MAX;

        for(int i=0;i<n;i++) {
            if(p[i].arrival <= time && !visited[i] && p[i].burst < min) {
                min = p[i].burst;
                idx = i;
            }
        }

        if(idx != -1) {
            time += p[idx].burst;
            p[idx].completion = time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_wt += p[idx].waiting;
            total_tat += p[idx].turnaround;

            visited[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
}

/* SJF Preemptive */
void sjf_preemptive(struct Process p[], int n) {
    int completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;

    for(int i=0;i<n;i++)
        p[i].remaining = p[i].burst;

    while(completed < n) {
        int idx = -1;
        int min = INT_MAX;

        for(int i=0;i<n;i++) {
            if(p[i].arrival <= time && p[i].remaining > 0 &&
               p[i].remaining < min) {
                min = p[i].remaining;
                idx = i;
            }
        }

        if(idx != -1) {
            p[idx].remaining--;
            time++;

            if(p[idx].remaining == 0) {
                completed++;
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_wt += p[idx].waiting;
                total_tat += p[idx].turnaround;
            }
        } else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
}

/*  MAIN  */
int main() {
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
    }

    printf("\n1. FCFS\n2. SJF Non-Preemptive\n3. SJF Preemptive\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: fcfs(p, n); break;
        case 2: sjf_non_preemptive(p, n); break;
        case 3: sjf_preemptive(p, n); break;
        default: printf("Invalid choice!");
    }

    return 0;
}
