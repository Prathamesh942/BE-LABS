#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[0]/a[1] > b[0]/b[1];
}

int fractionalKnapsack(vector<vector<int>> items, int capacity){
    sort(items.begin(), items.end(), comp);
    int res=0;
    int n=items.size();
    for(int i=0; i<n; i++){
        if(capacity > items[i][0]){
            res+=items[i][1];
        }else{
            res+=items[i][1]*(capacity/items[i][0]);
            break;
        }
    }
    return res;
}

int fractional01(vector<vector<int>> items, int capacity){
    int n=items.size();
    vector<vector<int>> dp(n+1, vector<int> (capacity+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            dp[i][j] = dp[i-1][j];
            if(items[i-1][1]<j) dp[i][j]=max(dp[i][j], items[i-1][1]+dp[i-1][j-items[i-1][1]]);
        }
    }
    return dp[n][capacity];
}

int main(){
    vector<vector<int>> items = {{10,20},{25,90},{50,60},{40,100},{40,40}};
    //weight, price
    // cout<<fractionalKnapsack(items,100);
    cout<<fractional01(items,100);
}