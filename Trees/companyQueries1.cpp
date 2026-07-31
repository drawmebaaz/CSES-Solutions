#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
const int LOG = 20; // 2^20 > 200,000 (Max value of N)

// up[i][j] will store the (2^j)-th ancestor of node i.
// Global arrays are initialized to 0 by default.
// 0 will represent a non-existent ancestor (since valid nodes are 1 to N).
int up[MAXN][LOG];

int main() {
    // Fast I/O is critical for CSES problems with large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    // Read the direct bosses (2^0-th ancestor)
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }

    // Precompute the binary lifting table
    // up[i][j] = up[ up[i][j-1] ][ j-1 ]
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    // Process each query
    while (q--) {
        int x, k;
        cin >> x >> k;
        
        // Jump upwards by looking at the set bits of k
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                x = up[x][j];
            }
        }
        
        // If x is 0, we've jumped past the general director (root)
        if (x == 0) {
            cout << -1 << "\n";
        } else {
            cout << x << "\n";
        }
    }

    return 0;
}