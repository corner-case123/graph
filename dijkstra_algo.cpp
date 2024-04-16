        // diff between dijkstra and bfs is the use of priority_queue instead of queue
        // actually the idea is same as bfs (where the distance from source is the priority)
        // in short -> bfs is (0-1)dijkstra or (simplified dijkstra)
        // but in weighted graph (the distance between two adjacent nodes is not 1 (any random value))

#include<bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second 
#define ld long double
#define pb(x) push_back(x)
#define loop(n) for(ll i=0;i<n;i++)
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
#define  pll pair<ll,ll>
#define ln '\n'
using namespace std;

struct node{
    ll me ; 
    ll dis ; 
} ;
ll n , m  ;


vll vis ; 
vector<vector<pll>> v ; 
priority_queue<pll,vector<pll>,greater<pll>> q  ;
void dijkstra(vector<vector<pll>> &v,node Node){
    if (Node.dis>=vis[Node.me]) return ;
    vis[Node.me] = Node.dis ;
    for(auto x:v[Node.me]){
        pll N ; N.ss = x.ff ; N.ff = (Node.dis+x.ss) ;
        q.push(N) ;
    }
    while(!q.empty()){
        node N ; N.me = q.top().ss ; N.dis =  q.top().ff ;
        q.pop() ;
        dijkstra(v,N) ;
    }
    return ;
}

void solve(){
    cin >> n >> m ;
    v.resize(n+1) ;
    vis.resize(n+1,LLONG_MAX) ;
    loop(m){
        ll x , y , c ;  cin >> x >> y >> c ;
        v[x].push_back({y,c}) ;
    }
    node Node ; Node.me = 1 ; Node.dis = 0 ;
    dijkstra(v,Node) ;
    for(ll i=1;i<=n;i++){
        cout << vis[i] << ' ' ;
    }
    cout << ln ;
    return ;
}

int main(){
    ll t = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ;
    //cin >> t  ;
    while(t--) solve();
    return 0;
}
