#include <bits/stdc++.h>
using namespace std;
int dp[101]; // Storing the result in case of DP

int func(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    cout << n << endl;
    return dp[n] = func(n - 1) + func(n - 2) + func(n - 3); // For DP
    //    return func(n-1)+func(n-2)+func(n-3); //For recursion
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp)); // Initializing dp table with -1
        cout << func(n) << endl;
    }
    return 0;
}