#include<bits/stdc++.h>
using namespace std;
int N = 5;

bool valid(vector<vector<int>>&grid, int col, int row){
    for(int i=0;i<N;i++){
        if(grid[i][col]==1){
            return false;
        }
    }
    int r = row;
    int c = col;
    while(r >= 0 && c >= 0){
        if(grid[r][c]==1){
            return false;
        }
        r--;
        c--;
    }
    r = row;
    c = col;
    while(r >= 0 && c < N){
        if(grid[r][c]==1){
            return false;
        }
        r--;
        c++;
    }
    return true;
}

void func(vector<vector<int>>&grid, int index){
    if(index == N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    } else {
        for(int c=0;c<N;c++){
            if(valid(grid, c, index)){
                grid[index][c]=1;
                func(grid, index+1);
                grid[index][c]=0;
            }
        }
    }
}

int main(){
    vector<vector<int>>grid(N, vector<int>(N,0));
    func(grid, 0);
    return 0;
}