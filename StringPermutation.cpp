#include <bits/stdc++.h>
using namespace std;

void method1(string prefix, string str, set<string> &res)
{
    if (str.length() == 0)
    {
        res.insert(prefix);
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string before = str.substr(0, i);
        string after = str.substr(i + 1, str.length());
        char c = str[i];
        method1(prefix + c, before+after, res);
    }
    return;
}

void method2(string str, int low, int high, set<string> &res)
{
    if (low == high)
    {
        res.insert(str);
    }
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap(str[low], str[i]);
            method2(str, low + 1, high, res);
            swap(str[low], str[i]);
        }
    }
    return;
}

int main()
{
    string str;
    cin>>str;
    set<string> res;
    method1("", str, res);
    for(auto word:res){
        cout<<word<<endl;
    }
    res.clear();
    cout<<"--------"<<endl;
    method2(str, 0, str.length() - 1, res);
    for(auto word:res){
        cout<<word<<endl;
    }
    return 0;
}