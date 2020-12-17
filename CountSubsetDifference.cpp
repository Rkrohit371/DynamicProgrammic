#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    int diff;
    cin >> diff;
    int final = (total + diff) / 2;
    cout << func(arr, final, n);
    return 0;
}