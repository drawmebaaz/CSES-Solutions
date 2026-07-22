#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    if(a[0][0]=='*' || a[n-1][n-1]=='*'){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        dp[0][i] = dp[0][i-1];
        if(a[0][i]=='*'){
            dp[0][i] = 0;
        }
    }
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0];
        if(a[i][0]=='*'){
            dp[i][0] = 0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
            if(a[i][j]=='*'){
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}