#include<bits/stdc++.h>
using namespace std;

string func(string str, int n){
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    // for(int i=0;i<=n;i++){
    //     dp[i][0] = 0;
    //     dp[0][i] = 0;
    // }
    // int p=1,k=1;
    // while(p <= n && k <= n){
    //     dp[p][k] = 0;
    //     p++;
    //     k++;
    // }
    int length = 0, index=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(str[i-1] == str[j-1] && dp[i-1][j-1] < (j-i)){
                dp[i][j] = 1+dp[i-1][j-1];
                if(length < dp[i][j]){
                    length = dp[i][j];
                    index = max(i, index);
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    string res;
    for(int i=index-length +1;i<=index;i++){
        res.push_back(str[i]);
    }
    return res;
}

int main(){
    string str;
    cin>>str;
    cout<<func(str, str.length());

    return 0;
}