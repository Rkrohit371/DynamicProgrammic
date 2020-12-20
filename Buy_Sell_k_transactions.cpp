#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&arr, int n, int k){
    int dp[k+1][n];
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else {
                int maxv = 0;
                for(int p=0;p<j;p++){
                    maxv = max(maxv, dp[i-1][p] + arr[j]-arr[p]);
                }
                dp[i][j] = max(dp[i][j-1], maxv);
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[k][n-1];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<func(arr, n, k);

    return 0;
}