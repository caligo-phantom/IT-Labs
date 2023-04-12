// Container Loading Problem
#include<bits/stdc++.h>
using namespace std;

bool compareWeight(int wt1, int wt2) {
    return (wt1 > wt2);
}

void containerLoading(int n, int weight[], int capacity) {
    sort(weight, weight + n, compareWeight);
    int totalWeight = 0;
    for(int i = 0; i < n; i++) {
        totalWeight += weight[i];
        if(totalWeight > capacity) {
            totalWeight -= weight[i];
            break;
        }
    }

    cout << "Total weight the container can carry: " << totalWeight << '\n';
}

int main() {
    int n, weight[10], capacity;

    cout << "Input Number of Items: ";
    cin >> n;

    cout << "Input Capacity of Container: ";
    cin >> capacity;

    cout << "Input Weight of the items:\n";
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    
    containerLoading(n, weight, capacity);

    return 0;
}