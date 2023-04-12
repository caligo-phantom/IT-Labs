// Given n tasks and an infinite supply of machines on which these tasks can be performed. Each task has start time Si and finish time Fi, Si < Fi. [Si , Fi ] is the processing interval for task i. Two tasks i & j overlap iff their processing intervals overlap at a point other than start or finish time. Schedule the tasks using minimum number of machines.
#include<bits/stdc++.h>    // header file that includes commonly used libraries
using namespace std;

class Task {   // defining a Task class with two attributes: start and finish
    public: 
        int start, finish;
};

bool Comparetasks(Task t1, Task t2) {  // function that compares tasks based on their start time
    return (t1.start < t2.start);
}

void printtasks(Task arr[], int n) {  // function that prints the task allocation for each machine
    sort(arr, arr+n, Comparetasks);  // sorting the tasks in ascending order of their start time
    int i = 0;
    bool selected[n];  // boolean array to keep track of which tasks have been selected
    for(i = 0; i < n; i++) {
        selected[i] = false;  // initializing the boolean array to false
    }
    int k = 0, j;
    for(i = 0; i < n; i++) {   // allocating tasks to machines using a greedy algorithm
        if(selected[i]) {   // if the task has already been allocated, move to the next task
            continue;
        }
        cout << "========================================";
        cout << "\n" << "Task Allocation: For Machine" << k + 1 << "\n";
        cout << "(" << arr[i].start << "," << arr[i].finish << ")" << "\n";   // printing the current task
        for(j = i + 1; j < n; j++) {
            if(selected[j]) {   // if the next task has already been allocated, move to the next task
                continue;
            }
            if(arr[i].finish <= arr[j].start) {   // checking if the current task can be allocated to the current machine
                i = j;
                selected[j] = 1;   // marking the next task as selected
                cout << "(" << arr[j].start << "," << arr[j].finish << ")" << "\n";  // printing the next task
            }
        }
        i = ++k;
        cout << "========================================";
    }
    cout << "\n" << "Total Machines Used " << k;  // printing the total number of machines used
}

int main() {
    Task arr[10];   // array of Task objects
    int n;
    cout << "Enter the number of Total Number of Tasks";
    cin >> n;
    cout << "Enter Start and Finish time of each machine";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;  // taking input from the user
    }
    printtasks(arr, n);   // calling the printtasks function
    return 0;
}