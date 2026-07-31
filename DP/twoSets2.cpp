#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ll n;
    cin >> n;
    
    ll sum = 0;
    for(ll i=1;i<=n;i++){
        sum += i;
    }

    if(sum%2!=0){
        cout << 0 << endl;
        return 0;
    }

    ll k = sum/2;

    vector<ll> dp(k+1,0);
    dp[0] = 1;
    for(ll j=1;j<n;j++){
        for(ll i=k;i>=1;i--){
            if(i>=j){
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }
    
    cout << dp[k] << endl;
}