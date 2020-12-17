#include<bits/stdc++.h>
using namespace std;

struct Box {
    int height;
    int width;
    int depth;
};

bool compare(Box a, Box b){
    return a.depth*a.width > b.depth*b.width;
}

int MaxHeight(Box arr[], int n){
    Box AllBox[3*n];
    int index=0;
    for(int i=0;i<n;i++){
        AllBox[index].height = arr[i].height;
        AllBox[index].depth = max(arr[i].depth, arr[i].width);
        AllBox[index].width = min(arr[i].width, arr[i].depth);
        index++; 

        AllBox[index].height = arr[i].depth;
        AllBox[index].depth = max(arr[i].height, arr[i].width);
        AllBox[index].width = min(arr[i].width, arr[i].height);
        index++;

        AllBox[index].height = arr[i].width;
        AllBox[index].depth = max(arr[i].depth, arr[i].height);
        AllBox[index].width = min(arr[i].height, arr[i].depth);
        index++;
    }
    n = n*3;
    sort(AllBox, AllBox+n, compare);
    int maxHeight[n];
    for(int i=0;i<n;i++){
        maxHeight[i] = AllBox[i].height;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(AllBox[i].width < AllBox[j].width && AllBox[i].depth < AllBox[j].depth && maxHeight[i] < maxHeight[j] + AllBox[i].height){
                maxHeight[i] = maxHeight[j] + AllBox[i].height;
            }
        }
    }
    int maxFinal = -1;
    for(int i=0;i<n;i++){
        maxFinal = max(maxFinal, maxHeight[i]);
    }
    return maxFinal;
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<AllBox[i].height<<" "<<AllBox[i].width<<" "<<AllBox[i].depth<<endl;
    // }
}

int main() {
    int h,w,d;
    int n;
    cin>>n;
    Box arr[n];
    for(int i=0;i<n;i++){
        cin>>h>>w>>d;
        arr[i].height = h;
        arr[i].width = w;
        arr[i].depth = d;
    }
    cout<<MaxHeight(arr, n);
    return 0;
}