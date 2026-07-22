#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<bool> dp(sum+1,false);
    dp[0] = true;
    for(ll j=0;j<n;j++){
        for(ll i=0;i<=sum;i++){
            if(i>=a[j]){
                dp[i] = dp[i]||dp[i-a[j]];
            }
        }
    }
    
    ll count = 0;
    vector<ll> ans;
    for(ll i=1;i<=sum;i++){
        if(dp[i]){
            count++;
            ans.push_back(i);
        }
    }
    
    cout << count << endl;
    for(ll i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}