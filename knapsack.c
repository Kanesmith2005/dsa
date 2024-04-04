#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void* a, const void* b) {
    double ratioA = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double ratioB = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return (ratioB > ratioA) ? 1 : -1;
}

void knapsackGreedy(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);
    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            currentWeight += fraction * items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }

    printf("Optimal value in Knapsack: %.2lf\n", totalValue);
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    knapsackGreedy(items, n, capacity);

    return 0;
}
