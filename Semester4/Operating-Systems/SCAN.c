#include <stdio.h>

int absoluteValue(int);

int main() {
    int queue[25], n, headposition, i, j, k;
    int seek = 0, maxrange, difference, temp;
    int queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxrange);
    
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &headposition);

    printf("Enter the disk positions to be read (queue):\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if (temp > headposition) {
            queue1[temp1++] = temp;
        } else {
            queue2[temp2++] = temp;
        }
    }

    // Sort queue1 in ascending order
    for (i = 0; i < temp1 - 1; i++) {
        for (j = i + 1; j < temp1; j++) {
            if (queue1[i] > queue1[j]) {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    // Sort queue2 in descending order
    for (i = 0; i < temp2 - 1; i++) {
        for (j = i + 1; j < temp2; j++) {
            if (queue2[i] < queue2[j]) {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    // Assemble full queue for LOOK (moving right first)
    k = 1;
    for (i = 0; i < temp1; i++)
        queue[k++] = queue1[i];

    for (i = 0; i < temp2; i++)
        queue[k++] = queue2[i];

    queue[0] = headposition;

    // Calculate seek operations
    for (j = 0; j < k - 1; j++) {
        difference = absoluteValue(queue[j + 1] - queue[j]);
        seek += difference;
        printf("Disk head moves from position %d to %d with Seek %d\n",
               queue[j], queue[j + 1], difference);
    }

    averageSeekTime = (float)seek / n;
    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", averageSeekTime);

    return 0;
}

int absoluteValue(int x) {
    return (x >= 0) ? x : -x;
}
