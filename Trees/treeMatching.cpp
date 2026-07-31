#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
int dp[N][2];

void dfs(int u, int p) {
    int sum = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sum += max(dp[v][0], dp[v][1]);
    }
    dp[u][0] = sum;
    dp[u][1] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;

        dp[u][1] = max(dp[u][1],
                       sum - max(dp[v][0], dp[v][1])
                           + dp[v][0] + 1);
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]);
}