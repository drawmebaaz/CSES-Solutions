#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n , x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    
    vector<vector<int>> dp(n+1,vector<int>(x+1)); //till ith index maximum pages with total weight j = dp[i][j]
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int take = 0;
            int not_take = dp[i-1][j];
    
            if(j >= a[i-1]){
                take = dp[i-1][j-a[i-1]] + b[i-1];
            }
    
            dp[i][j] = max(take, not_take);
        }
    }
    
    cout << dp[n][x] << endl;
    return 0;
}