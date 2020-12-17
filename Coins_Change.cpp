#include<bits/stdc++.h>
using namespace std;

int func(int coins[], int n, int amount){
    int dp[n+1][amount+1];
    for(int i=0;i<=amount;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}

int main(){
    int coins[] = {1,5,10,25};
    int n = sizeof(coins)/sizeof(coins[0]);
    // cout<<n<<endl;
    int amount;
    cin>>amount;
    
    cout<<func(coins, n, amount);

    return 0;
}