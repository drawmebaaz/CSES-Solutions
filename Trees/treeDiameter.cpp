#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
int maxDist = INT_MIN;
int farNode;
#define ll long long
 
void dfs(int u,int parent, int dist) {
    if (dist > maxDist) {
        maxDist = dist;
        farNode = u;
    }
 
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, dist + 1);
    }
}
 
int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    vector<int> a(n);
    for(int i=0;i<n-1;i++){
        int a;
        int b;
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int i;
    dfs(1,-1,0);
    
    dfs(farNode, -1, 0);
    cout << maxDist << endl;
}