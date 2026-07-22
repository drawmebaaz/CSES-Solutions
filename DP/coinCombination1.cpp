#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];   
    }
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int k=0;k<n;k++){ 
            if(i-a[k]>=0){
                dp[i] += dp[i-a[k]];   
                dp[i] %= MOD;
            }
        }
    }
    
    cout << dp[x] << endl;
    return 0;
}