// Matrix Chain Multiplication
#include <bits/stdc++.h>
using namespace std;

int matrixChainOrder(int p[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int k;
    int mini = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        mini = min(count, mini);
    }
    return mini;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "Minimum number of multiplications is "
         << matrixChainOrder(arr, 1, N);
    return 0;
}