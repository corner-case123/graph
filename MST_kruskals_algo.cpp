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

// kruskals is used to find MST (minimum spanning tree)
// minimum : the sum of the edges of the tree is minimum possible
// spanning tree: there is one tree (no loops and one connected component)

vll par , sz  ;
void make(ll node){
    // initializing a group
    par[node] = node ;
    sz[node] =  1 ;
}
ll find(ll node){
    if (par[node]==node) return node ;
    // path compression
    return par[node] = find(par[node]) ;
}
void Union(ll a,ll b){
    // union by size 
    ll par_a = find(a) , par_b = find(b) ;
    if (par_a == par_b) return ;
    if (sz[par_a]<sz[par_b]) swap(par_a,par_b) ;
    par[par_b] = par_a ;
    sz[par_a] += sz[par_b] ;
}
void kruskals(){   
    ll n , m ; cin >> n ;
    par.resize(n+1) ;
    sz.resize(n+1) ;
    for(ll i=1;i<=n;i++){
        make(i) ;
    }
    vector<pair<ll,pair<ll,ll>>> v  ;
    ll cost =  0  ;
    loop(m){
        ll x , y , wt; cin  >> x >> y >> wt ;
        v.push_back({wt,{x,y}}) ;
    }
    sort(v.begin(),v.end()) ;
    for(auto x:v){
        ll wt = x.ff  , u = x.ss.ff , v  = x.ss.ss ;
        if (find(u)==find(v)) continue ;
        Union(u,v) ;
        cost += wt ;
    }
    cout << cost << ln ;
    return ;
}

int main(){
    ll t =1 ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin >> t  ;
    while(t--) kruskals() ;
    return 0 ;
}