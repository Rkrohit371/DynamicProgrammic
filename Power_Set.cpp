#include<bits/stdc++.h>
using namespace std;
set<string>st;

/*
Input:
3
1 2 3

Output:
1
1 2
1 2 3
1 3
2
2 3
3

*/

void func(vector<int>&arr, int i, int n, string op=""){
    if(i==n){
        st.insert(op);
        return;
    }
    string first = op;
    string second = op;
    second = second +" "+ to_string(arr[i]);
    func(arr, i+1, n, first);
    func(arr, i+1, n, second);

}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(arr, 0, n);
    for(auto i:st){
        if(i.length()==0){
            cout<<i;
        } else cout<<i.substr(1)<<endl;
    }
    return 0;
}