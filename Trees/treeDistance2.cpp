#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> ans;
vector<ll> sz;
vector<vector<ll>> adj;

void dfs1(ll u,ll parent,ll depth){
    ans[1] += depth;
    sz[u] = 1;
    for(ll v:adj[u]){
        if(v==parent)continue;
        dfs1(v,u,depth+1);
        sz[u] += sz[v];
    }
}

void dfs2(ll u,ll parent,ll n){
    for(ll v:adj[u]){
        if(v==parent)continue;
        ans[v] = ans[u] + n - 2*sz[v];
        dfs2(v,u,n);
    }
}

int main(){
    ll n;
    cin >> n;
    adj.resize(n+1,{});
    for(ll i=0;i<n-1;i++){
        ll a;
        ll b;
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans.resize(n+1,0);
    sz.resize(n+1,0);
    dfs1(1,-1,0);
    dfs2(1,-1,n);

    for(ll i=1;i<=n;i++){
        cout << ans[i] << " ";
    }

    return 0;
}