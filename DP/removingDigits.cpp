#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int k = i;
        while(k){
            int digit = k%10;
            k/=10;
            if(i>=digit && dp[i-digit]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-digit]+1);   
            }
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}