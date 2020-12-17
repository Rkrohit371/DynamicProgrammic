#include <bits/stdc++.h>
using namespace std;

/*
Input:
1
11
-2 -1 0 1 2 3 5 7 9 12 13

Output:
7

*/

int func(int arr[], int i, int j)
{
    if (i > j)
    {
        return -1;
    }
    int mid = i + (j - i) / 2;
    // cout<<mid<<endl;
    if (arr[mid] == mid)
    {
        return mid;
    }
    int leftIndex = min(mid - 1, arr[mid]);
    int left = func(arr, i, leftIndex);
    if (left >= 0)
    {
        return left;
    }
    int rightIndex = max(mid + 1, arr[mid]);
    int right = func(arr, rightIndex, j);
    return right;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << func(arr, 0, n - 1) << endl;
    }
    return 0;
}