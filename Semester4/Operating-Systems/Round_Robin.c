#include <stdio.h>
#include <stdlib.h>

#define n 100

int queue[n];
int front = -1;
int rear = -1;

void enqueue(int queue[], int val) {
    if (rear == -1) front++;
    queue[++rear] = val;
}

void dequeue(int queue[]) {
    if (front != -1) {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

struct process {
    int pid, arr, bt, ct, turn, wt, r, flag;
};

struct chart {
    int pid, timet;
};

void printLines(struct chart c[], int m, int l) {
    int i, j, t = 0;
    printf(" ");
    for (i = 0; i < l + 1; i++) {
        for (j = 0; j < c[i].timet - t; j++) {
            printf("--");
        }
        t = c[i].timet;
        printf(" ");
    }
    printf("\n");
}

int main() {
    struct process p[n], temp, p_temp[n];
    struct chart c[n];
    int i, j, k, l = 0, m, x, q, timet, t = 0, completed = 0, count = 0, found;
    double avgtt, avgwt, ttt = 0, twt = 0;

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter no. of processes: ");
    scanf("%d", &m);
    printf("Enter quantum: ");
    scanf("%d", &q);

    printf("Enter Process ID, Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].arr, &p[i].bt);
        p[i].r = p[i].bt;
        p[i].flag = 0;
    }

    // Sort by arrival time
    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            if (p[j].arr < p[i].arr) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (timet = 0; completed < m; timet++) {
        if (front == -1 || rear == -1) {
            k = 0;
            for (i = 0; i < m; i++) {
                found = 0;
                if (p[i].arr <= timet && p[i].flag != 1) {
                    for (j = front; j <= rear; j++) {
                        if (queue[j] == p[i].pid) {
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) enqueue(queue, p[i].pid);
                    k++;
                }
            }
        }

        if (k > 0) {
            for (i = 0; i < m; i++) {
                if (queue[front] == p[i].pid && p[i].flag != 1) {
                    if (p[i].r > q) {
                        p[i].r -= q;
                        timet += (q - 1);
                    } else if (p[i].r == q) {
                        timet += (q - 1);
                        p[i].r = 0;
                        p[i].flag = 1;
                        p[i].ct = timet + 1;
                        p[i].turn = p[i].ct - p[i].arr;
                        p[i].wt = p[i].turn - p[i].bt;
                        completed++;
                    } else {
                        if (p[i].r != 1) timet += (p[i].r - 1);
                        p[i].r = 0;
                        p[i].flag = 1;
                        p[i].ct = timet + 1;
                        p[i].turn = p[i].ct - p[i].arr;
                        p[i].wt = p[i].turn - p[i].bt;
                        completed++;
                    }

                    // Enqueue any new arrivals during execution
                    k = 0;
                    for (x = 0; x < m; x++) {
                        found = 0;
                        if (p[x].arr <= (timet + 1) && p[x].flag != 1) {
                            for (j = front; j <= rear; j++) {
                                if (queue[j] == p[x].pid) {
                                    found = 1;
                                    break;
                                }
                            }
                            if (found == 0) enqueue(queue, p[x].pid);
                            k++;
                        }
                    }

                    if (c[l].pid != queue[front]) {
                        l++;
                        c[l].pid = queue[front];
                    }
                    c[l].timet = timet + 1;

                    dequeue(queue);
                    if (p[i].flag != 1) enqueue(queue, p[i].pid);
                    break;
                }
            }
        } else {
            if (timet == 0) {
                c[l].pid = 0;
                c[l].timet = timet + 1;
            } else {
                if (c[l].pid != 0) {
                    l++;
                    c[l].pid = 0;
                }
                c[l].timet = timet + 1;
            }
        }
    }

    // Output
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",
            p[i].pid, p[i].arr, p[i].bt, p[i].ct, p[i].turn, p[i].wt);
        ttt += p[i].turn;
        twt += p[i].wt;
    }

    avgtt = ttt / m;
    avgwt = twt / m;

    // Gantt chart
    printf("\nGantt chart\n");
    printLines(c, m, l);
    printf("|");

    t = 0;
    for (i = 0; i < l + 1; i++) {
        if (c[i].pid == 0) {
            for (j = 0; j < c[i].timet - t; j++) printf("//");
            t = c[i].timet;
            printf("|");
        } else {
            for (j = 0; j < c[i].timet - t - 1; j++) printf(" ");
            printf("P%d", c[i].pid);
            for (j = 0; j < c[i].timet - t - 1; j++) printf(" ");
            t = c[i].timet;
            printf("|");
        }
    }

    printf("\n");
    printLines(c, m, l);
    printf("0");
    t = 0;
    for (i = 0; i < l + 1; i++) {
        for (j = 0; j < c[i].timet - t; j++) printf(" ");
        t = c[i].timet;
        printf("%d", c[i].timet);
    }

    printf("\n\nTotal turnaround time : %.3lf\nTotal Waiting time : %.3lf\n", avgtt, avgwt);
    return 0;
}
