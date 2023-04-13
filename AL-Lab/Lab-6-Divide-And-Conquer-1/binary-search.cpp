#include<bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int l, int r, int x) {
    while(l <= r) {
        int m = l + (r - 1) / 2;

        if(arr[m] == x) 
            return m;
        if(arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n, ele, arr[20];
    cout << "Enter the total number of elements";
    cin >> n;
    cout << "Enter the elements in ascending order";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search";
    cin  >> ele;
    int result = binSearch(arr, 0, n - 1, ele);
    if(result == -1) {
        cout << "Element is not present in array";  
        exit(0);
    }
    cout << "Element is present at index " << result + 1;
    return 0;
}