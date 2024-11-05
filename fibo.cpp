#include<bits/stdc++.h>
using namespace std;

int fiboRecursive(int n){
    if(n<2) return n;
    return fiboRecursive(n-1)+fiboRecursive(n-2);
}

int fiboIterative(int n){
    if(n<2) return n;
    vector<int> res(n+1,0);
    res[1]=1;
    for(int i=2; i<=n; i++) res[i]=res[i-1]+res[i-2];
    return res[n];
}

int main(){
    cout<<fiboRecursive(4);
    cout<<fiboIterative(4);
}