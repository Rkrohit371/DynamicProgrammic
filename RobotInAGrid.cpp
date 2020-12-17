#include <bits/stdc++.h>
using namespace std;
int n, m;

/*
Input:
5 5
0 0 0 1 1
1 0 0 0 0
0 0 1 0 1
0 1 0 1 0
0 0 0 0 0

Output:
True
1 1 0 0 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
1 1 1 1 1

*/

bool move(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
{
    if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || vis[i][j] == 1 || grid[i][j] == 1)
    {
        return false;
    }
    // cout<<i<<" "<<j<<endl;
    vis[i][j] = 1;
    if (i == n - 1 && j == m - 1)
    {
        return true;
    }
    if (move(grid, vis, i + 1, j)) // Down Move
    {
        return true;
    }
    if (move(grid, vis, i, j + 1)) // Right Move
    {
        return true;
    }
    if (move(grid, vis, i, j - 1)) // Left Move
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if (move(grid, vis, 0, 0))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}