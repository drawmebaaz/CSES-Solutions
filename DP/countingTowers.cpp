#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define N 1000000

int main(){
    int t;
    cin >> t;
    vector<vector<ll>>dp (N+1,vector<ll>(2,0));
    dp[1][0] = 1;
    dp[1][1] = 1;
        
    for(int i=2;i<=N;i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%MOD;
    }

    while(t--){
        int n;
        cin >> n;
        
        ll ans = (dp[n][0] + dp[n][1])%MOD;
        cout << ans << endl;        
    }
}