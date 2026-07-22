#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    
    vector<ll> prev(m+2,0);
    vector<ll> cur(m+2,0);
    for(int j=1;j<=m;j++){
        if(a[0]==0){
            cur[j] = 1;
        }
        else if(j==a[0]){
            cur[j] = 1;
        }
    }

    for(int j=1;j<=m;j++){
        prev[j] = cur[j];
    }
    for(int i=1;i<n;i++){
        fill(cur.begin(), cur.end(), 0);
        for(int j=1;j<=m;j++){
            if(a[i]==0){
                cur[j] = (prev[j-1]+prev[j]+prev[j+1]) % MOD;
            }
            else if(j==a[i]){
                cur[j] = (prev[j-1]+prev[j]+prev[j+1]) % MOD;
            }
        }
        for(int j=1;j<=m;j++){
            prev[j] = cur[j];
        }
    }
    
    ll ways = 0;
    for(int j=1;j<=m;j++){
        ways=(ways+cur[j]) % MOD;
    }
    
    cout << ways << endl;
}