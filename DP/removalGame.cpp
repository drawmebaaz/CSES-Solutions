#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i] = a[i];
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            dp[i][j] = max(
                a[i] - dp[i+1][j],
                a[j] - dp[i][j-1]
            );
        }
    }
    
    cout << (sum+dp[0][n-1])/2 << endl;
}