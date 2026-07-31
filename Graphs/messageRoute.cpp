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
    vector<int> par(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    vis[1] = true;

    while(!q.empty() && q.front().first != n){
        int u = q.front().first;
        int count = q.front().second;
        q.pop();

        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v] = true;
                par[v] = u;
                q.push({v, count + 1});
            }
        }
    }

    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else{
        vector<int> path;
        int k = n;
        path.push_back(k);
        while(k!=1){
            k = par[k];
            path.push_back(k);
        }
        cout << path.size() << endl;
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout << path[i] << " ";
        }
    }
    
}