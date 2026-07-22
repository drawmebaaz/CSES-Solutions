#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];   
    }
    vector<ll> dp (x+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j] && dp[i-a[j]]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-a[j]] + 1);   
            }
        }
    }
    
    if(dp[x]==INT_MAX){
        cout << -1 << endl;
    }else{
        cout << dp[x] << endl;   
    }
    return 0;
}