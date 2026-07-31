#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

void dfs(int node){
    int sz = 1;
    for(int child: adj[node]){
        dfs(child);
        sz += dp[child];
    }
    dp[node] = sz;
}

int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    dp.resize(n+1);
    vector<int> a(n);
    for(int i=0;i<n-1;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        adj[a[i]].push_back(i+2);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout << dp[i]-1 << " ";
    }
}