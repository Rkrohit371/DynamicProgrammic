#include<bits/stdc++.h>
using namespace std;

int func(string str, int n){
    vector<int>dp(n+1);
    dp[0] = 1;
    cout<<dp.size()<<" "<<n<<endl;
    map<char, int>mp;
    for(int i=1;i<dp.size();i++){
        char ch = str[i-1];
        dp[i] = 2*dp[i-1];
        if(mp.count(ch)){
            int num = mp[ch];
            dp[i] = dp[i] - dp[num-1];
        }
        mp[ch] = i;
    }
    return dp[n]-1;
}

int main(){
    string str;
    cin>>str;
    cout<<func(str, str.length());

    return 0;
}