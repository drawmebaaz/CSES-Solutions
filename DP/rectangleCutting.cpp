#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define N 1000000

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<ll>> dp(a+1,vector<ll>(b+1,0));
    for(int i=1;i<=a;i++){
        dp[i][1] = i-1;   
    }
    for(int i=1;i<=b;i++){
        dp[1][i] = i-1;
    }
    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            if(i==j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
                
                for(int k=1;k<=a;k++){
                    if(i>=k){
                        dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);   
                    }
                }
                
                for(int k=1;k<=b;k++){
                    if(j>=k){
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);   
                    }
                }
            }
        }
    }
    
    cout << dp[a][b] << endl;
}