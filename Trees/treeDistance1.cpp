#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> downDist, upDist, ans;

void dfs1(int u, int p) {
    downDist[u] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        downDist[u] = max(downDist[u], 1 + downDist[v]);
    }
}

void dfs2(int u, int p) {
    int mx1 = -1, mx2 = -1;

    // Find the largest and second largest down values among children
    for (int v : adj[u]) {
        if (v == p) continue;

        int val = downDist[v];
        if (val >= mx1) {
            mx2 = mx1;
            mx1 = val;
        } else if (val > mx2) {
            mx2 = val;
        }
    }

    for (int v : adj[u]) {
        if (v == p) continue;

        int use = mx1;
        if (downDist[v] == mx1)
            use = mx2;

        // Option 1: go upward through parent
        // Option 2: go to another sibling subtree
        upDist[v] = max(upDist[u] + 1,
                        (use == -1 ? 0 : use + 2));

        dfs2(v, u);
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    downDist.assign(n + 1, 0);
    upDist.assign(n + 1, 0);
    ans.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);

    upDist[1] = 0;
    dfs2(1, -1);

    for (int i = 1; i <= n; i++) {
        ans[i] = max(downDist[i], upDist[i]);
        cout << ans[i] << " ";
    }
    cout << endl;
}