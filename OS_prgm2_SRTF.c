

Srtf


#include <stdio.h>

struct process {
    int id, at, bt, ct, tat, wt, rt, rem;
};

int main() {


    int n;
    print("DEEPSHEKAR M U");

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i = 0; i < n; i++) {

        p[i].id = i + 1;

        printf("Arrival Time of P%d: ", p[i].id);
        scanf("%d", &p[i].at);

        printf("Burst Time of P%d: ", p[i].id);
        scanf("%d", &p[i].bt);

        p[i].rem = p[i].bt;
        p[i].rt = -1;
    }

    int completed = 0, time = 0;
    int sumTAT = 0, sumWT = 0, sumRT = 0;

    while(completed != n) {

        int idx = -1;
        int minRem = 9999;

        for(int i = 0; i < n; i++) {

            if(p[i].at <= time && p[i].rem > 0) {

                if(p[i].rem < minRem) {
                    minRem = p[i].rem;
                    idx = i;
                }
            }
        }

        if(idx != -1) {

            if(p[idx].rt == -1) {
                p[idx].rt = time - p[idx].at;
                sumRT += p[idx].rt;
            }

            p[idx].rem--;
            time++;

            if(p[idx].rem == 0) {

                p[idx].ct = time;

                p[idx].tat = p[idx].ct - p[idx].at;

                p[idx].wt = p[idx].tat - p[idx].bt;

                sumTAT += p[idx].tat;
                sumWT += p[idx].wt;

                completed++;
            }
        }
        else {
            time++;
        }
    }

    printf("\nAvg TAT: %.2f\n", (float)sumTAT/n);
    printf("Avg WT: %.2f\n", (float)sumWT/n);
    printf("Avg RT: %.2f\n", (float)sumRT/n);

    return 0;
}
