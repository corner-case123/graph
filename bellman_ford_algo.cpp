                    // EVERYTHING BELONGS TO ALMIGHTY ALLAH
// bellman-ford is also a dp-based soution (like floyd-warshall)
// it can deal negative edges but not negative cycle
//the detection of a negative cycle is that on the n-th iteration the dis array gets update
// because normally the dis array can get update maximum on the n-1 th iteration
#include<bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second 
#define ld long double
#define pb(x) push_back(x)
#define loop(n) for(ll i=0;i<n;i++)
#define vll vector<ll> 
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define ln '\n'
using namespace std;

ll inf = 1e12 ;
vll dis ; 
void bellman_ford(){
    ll n , m ; cin >> n >> m ;
    dis.resize(n+1,inf) ;
    vector<vector<pll>> v ;
    dis[1] = 0  ; // source 
    loop(m){
        ll x ,y , wt ;  cin >> x >> y >> wt ;
        v[x].push_back({y,wt}) ;
        v[y].push_back({x,wt}) ;
    }
    loop(n-1){
        for(ll i=1;i<=n;i++){
            for(auto x:v[i]){
                if (dis[i]!=inf and dis[i]+x.ss<dis[x.ff]){
                    dis[x.ff] = dis[i] + x.ss ;
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(auto x:v[i]){
            if (dis[i]!=inf and dis[i]+x.ss<dis[x.ff]){
                cout << -1 << ln ;
                return ;
            }
        }
    }
    return ;
}

int main(){
    ll t =1 ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin >> t  ;
    while(t--) bellman_ford() ;
    return 0 ;
}