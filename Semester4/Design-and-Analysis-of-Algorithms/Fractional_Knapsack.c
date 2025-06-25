#include <stdio.h>

struct Item {
    int weight, value;
};

void knapsack(struct Item items[], int n, int W) {
    int i;
    float total = 0.0, fraction;
    printf("\nItems included:\n");

    for (i = 0; i < n && W > 0; i++) {
        if (items[i].weight <= W) {
            printf("Item %d -> 100%%\n", i + 1);
            total += items[i].value;
            W -= items[i].weight;
        } else {
            fraction = (float)W / items[i].weight;
            total += items[i].value * fraction;
            printf("Item %d -> %.2f%%\n", i + 1, fraction * 100);
            break;
        }
    }
    printf("Total profit: %.2f\n", total);
}

int main() {
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items)/sizeof(items[0]);
    int W = 50;
    printf("\nJash Parikh, C065, 60004220080\n");
    knapsack(items, n, W);
    return 0;
}
