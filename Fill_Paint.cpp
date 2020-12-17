#include<bits/stdc++.h>
using namespace std;
int n,m;

void fillColor(vector<vector<int>>&mat, int x, int y, int prevColor, int newColor){
    if(x >= n || x < 0 || y >= m || y < 0 || mat[x][y] == newColor || mat[x][y] != prevColor){
        return;
    }

    mat[x][y] = newColor;
    fillColor(mat, x, y+1, prevColor, newColor);
    fillColor(mat, x, y-1, prevColor, newColor);
    fillColor(mat, x-1, y, prevColor, newColor);
    fillColor(mat, x+1, y, prevColor, newColor);
}

void func(vector<vector<int>>&mat, int x, int y, int newColor){
    int prevColor = mat[x][y];
    fillColor(mat, x, y, prevColor, newColor);
    return;
}

int main(){
    cin>>n>>m;
    vector<vector<int>>mat(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    int x,y,newColor;
    cin>>x>>y>>newColor;
    func(mat, x, y, newColor);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}