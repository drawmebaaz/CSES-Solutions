#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int par, int n, int m, vector<bool> &vis,vector<vector<int>> &adj) {
    vis[u] = true;

    for (auto v:adj[u]){
        if(!vis[v]){
            dfs(v,u,n,m,vis,adj);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1, false);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }

    int count = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            count++;
            dfs(i, -1, n, m, vis, adj);
        }
    }

    cout << count-1 << endl;
    for(int i=0;i<count-1;i++){
        cout << ans[i] << " " << ans[i+1];
        cout << endl;
    }
    
}