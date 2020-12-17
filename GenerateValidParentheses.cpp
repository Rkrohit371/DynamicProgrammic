#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
multiset<string> st;

void func(int n, int open, int close, string res = "")
{
    if (open == n && close == n)
    {
        cout << res << endl;
        // st.insert(res);
        return;
    }
    // cout<<res<<endl;
    if (open < n)
    {
        func(n, open + 1, close, res + "(");
    }
    if (open > close)
    {
        func(n, open, close + 1, res + ")");
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        func(n, 0, 0);
    }
    return 0;
}