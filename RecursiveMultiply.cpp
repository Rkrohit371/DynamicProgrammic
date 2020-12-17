#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;

int biggerSmaller(int a, int b);

int func(int smaller, int bigger){
    if(smaller==0){
        return 0;
    }
    else if(smaller==1){
        return bigger;
    }
    string temp = to_string(smaller) + "|" + to_string(bigger);
    if(mp.count(temp)){
        return mp[temp];
    } 
    cout<<smaller<<" "<<bigger<<endl;
    int s = smaller >> 1;
    int side1 = biggerSmaller(s,bigger);
    int side2 = side1;
    if(smaller%2==1){
        side2 = func(smaller-s,bigger);
    }
    return mp[temp]=side1 + side2;
}

int biggerSmaller(int a, int b){
    int smaller = a > b ? b : a;
    int bigger = a > b ? a : b;
    return func(smaller, bigger);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<func(a,b);
    }
    return 0;
}