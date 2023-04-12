// 0/1 Knapsack Problem
#include<bits/stdc++.h>
using namespace std;

class item {
    public: int weight, value, valueToWeightRatio;
};

bool compareValueToWeightRatio(item item1, item item2) {
    return (item1.valueToWeightRatio > item2.valueToWeightRatio);
}

void _01Knapsack(int n, item items[], int capacity) {
    sort(items, items + n, compareValueToWeightRatio);
    int totalWeight = 0, totalValue = 0;
    for(int i = 0; i < n; i++) {
        totalWeight += items[i].weight;
        totalValue += items[i].value;
        if(totalWeight > capacity) {
            totalWeight -= items[i].weight;
            totalValue -= items[i].value;
        }
    }

    cout << "Total Weight of items in the Knapsack: " << totalWeight << "\n";

    cout << "Total Value of items in the Knapsack: " << totalValue << "\n";
}

int main() {
    int n, capacity;
    item items[10];

    cout << "Input Number of Items: ";
    cin >> n;

    cout << "Input Capacity of the Knapsack: ";
    cin >> capacity;

    cout << "Input Weight and Value of items:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].valueToWeightRatio = items[i].value / items[i].weight;
    }

    _01Knapsack(n, items, capacity);

    return 0;
}