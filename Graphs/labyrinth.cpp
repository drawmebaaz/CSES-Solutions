#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m));

    queue<pair<int, int>> q;

    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == '#')
                vis[i][j] = true;

            if (a[i][j] == 'A')
                start = {i, j};

            if (a[i][j] == 'B')
                end = {i, j};
        }
    }

    q.push(start);
    vis[start.first][start.second] = true;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};

    bool possible = false;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (a[i][j] == 'B') {
            possible = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int r = i + dx[k];
            int c = j + dy[k];

            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]) {
                vis[r][c] = true;
                par[r][c] = make_pair(i, j);
                move[r][c] = dir[k];
                q.push({r, c});
            }
        }
    }

    if (!possible) {
        cout << "NO\n";
        return 0;
    }

    string ans;

    pair<int, int> cur = end;

    while (cur != start) {
        ans += move[cur.first][cur.second];
        cur = par[cur.first][cur.second];
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";

    return 0;
}
