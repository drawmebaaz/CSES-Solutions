//dp solution

#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define ll long long
#define N 1000000
 
string dfs(vector<vector<char>> &a, int i, int j, int n, vector<vector<string>> &dp){
    if(dp[i][j] != ""){
        return dp[i][j];
    }
    if(i == n-1 && j == n-1){
        dp[i][j] = string(1,a[i][j]);
        return dp[i][j];
    }
    if(i == n-1){
        dp[i][j] = string(1,a[i][j]) + dfs(a,i,j+1,n,dp);
        return dp[i][j];
    }
    if(j == n-1){
        dp[i][j] = string(1,a[i][j]) + dfs(a,i+1,j,n,dp);
        return dp[i][j];
    }
    return dp[i][j] = string(1,a[i][j]) + min({dfs(a,i+1,j,n,dp),dfs(a,i,j+1,n,dp)});
}
 
int main(){
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<string>> dp(n,vector<string>(n,""));
    string ans = dfs(a,0,0,n,dp);
    cout << ans << endl;
    return 0;
}

//optimised solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    vector<pair<int,int>> cur;
    cur.push_back({0,0});
    vis[0][0] = true;

    string ans;
    ans += a[0][0];

    while(ans.size() < 2*n-1){

        char mn = 'Z'+1;

        // Find smallest next character
        for(auto [x,y] : cur){
            if(x+1<n)
                mn = min(mn,a[x+1][y]);
            if(y+1<n)
                mn = min(mn,a[x][y+1]);
        }

        ans += mn;

        vector<pair<int,int>> nxt;

        for(auto [x,y] : cur){

            if(x+1<n && !vis[x+1][y] && a[x+1][y]==mn){
                vis[x+1][y]=true;
                nxt.push_back({x+1,y});
            }

            if(y+1<n && !vis[x][y+1] && a[x][y+1]==mn){
                vis[x][y+1]=true;
                nxt.push_back({x,y+1});
            }

        }

        cur.swap(nxt);
    }

    cout << ans << '\n';
}