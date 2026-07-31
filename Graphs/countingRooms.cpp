#include <bits/stdc++.h>
using namespace std;
 
void dfs(int i,int j,int n,int m,vector<vector<bool>> &vis){
    vis[i][j] = true;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    
    for(int k=0;k<4;k++){
        if((i+dx[k])>=0 && (i+dx[k])<n && (j+dy[k]) >=0 && (j+dy[k]) <m && (!vis[i+dx[k]][j+dy[k]])){
            dfs(i+dx[k],j+dy[k],n,m,vis);   
        }
    }
}
 
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a (n,vector<char>(m,' '));
    vector<vector<bool>> vis (n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#'){
                vis[i][j] = true;
            }
        }
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                count++;
                dfs(i,j,n,m,vis);
            }
        }
    }
    
    cout << count << endl;
}