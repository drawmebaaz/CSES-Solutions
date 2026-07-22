#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define N 1000000

int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    vector<ll> ans;
    int i = n;
    int j = m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << dp[n][m] << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}