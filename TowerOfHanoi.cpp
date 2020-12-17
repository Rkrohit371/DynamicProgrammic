<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

void func(int n, string s, string d, string h){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<s<<"->"<<d<<endl;
        return ;
    }
    func(n-1, s, h, d);
    cout<<"Move disk "<<n<<" from "<<s<<"->"<<d<<endl;
    func(n-1,h,d,s);
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        func(n, "Start", "Dest", "Helper");
    }
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

void func(int n, string s, string d, string h){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<s<<"->"<<d<<endl;
        return ;
    }
    func(n-1, s, h, d);
    cout<<"Move disk "<<n<<" from "<<s<<"->"<<d<<endl;
    func(n-1,h,d,s);
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        func(n, "Start", "Dest", "Helper");
    }
    return 0;
>>>>>>> 30dcc0ac1d76bbcf77fa6e514e2ce49e10b66b7f
}