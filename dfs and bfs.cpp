                    // EVERYTHING BELONGS TO ALMIGHTY ALLAH
#include<bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second 
#define ld long double
#define pb(x) push_back(x)
#define loop(n) for(ll i=0;i<n;i++)
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
#define ln '\n'
using namespace std;

ll n ; 
vector<ll> vis ;
void dfs(vector<vector<ll>> &v, ll node){
    if (vis[node]==1) return ;
    vis[node]=1 ;
    for(auto x:v[node]){
        dfs(v,x) ;
    }
    return ;
}
queue<ll>q ;
void bfs(vector<vector<ll>>&v,ll node){
    if (vis[node]==1) return ;
    vis[node]= 1 ;
    for(auto x:v[node]){
        q.push(x) ;
    }
    while(!q.empty()){
        ll node = q.front() ;
        q.pop() ;
        bfs(v,node) ;
    }
    return ;
}
void solve(){
    cin >> n  ;
    vector<vector<ll>> v(n+1) ;
    vis.resize(n+1,0) ;
    return ;
}

int main(){
    ll t =1 ;
    //cin >> t  ;
    while(t--) solve() ;
    return 0 ;
}
