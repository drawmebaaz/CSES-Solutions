#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];   
    }
    vector<vector<bool>> dp (x+1,vector<bool>(x+1,false));
    dp[0][0] = true;
    int io = 0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            io = 1;
        }
        if (a[i] <= x){
            dp[1][a[i]] = true;
        }
        }
    if(io==1){
        dp[x][x] = true;
    }
    for(int i=1;i<=x;i++){
        for(int j = 1;j<=x;j++){
            for(int k=0;k<n;k++){
                if(i >= a[k]){
                    dp[j][i] = dp[j][i]||dp[j-1][i-a[k]];
                }
            }
        }
    }
    
    int ans = -1;
    for(int i=0;i<=x;i++){
        if(dp[i][x]){
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}