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

// dsu is basically a grouping algorithm
// where each group has one root node 
// when two group are merged their roots are connected 
// root of two newly connected groups is selected based on their size
// path compression : when the root of a node is found using find(node)
// all the nodes in the path to root node are updated as well (their root node is updated)

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
void solve(){   
    ll n , m ; cin >> n ;
    par.resize(n+1) ;
    sz.resize(n+1) ;
    for(ll i=1;i<=n;i++){
        make(i) ;
    }
    loop(m){
        ll x , y ; cin  >> x >> y ;
    }
    return ;
}

int main(){
    ll t =1 ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin >> t  ;
    while(t--) solve() ;
    return 0 ;
}