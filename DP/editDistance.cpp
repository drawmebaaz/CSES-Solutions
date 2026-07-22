#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define N 1000000

int main(){
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;   
            }
        }
    }
    
    cout << dp[n][m] << endl;
}