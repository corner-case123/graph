                    // EVERYTHING BELONGS TO ALMIGHTY ALLAH

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

// the idea is to use an indegree (the video link take_u_forward)
// the algo is very amazing and intuitive 
vll as  , indegree ; 
queue<ll> q ;
void topo_sort(vector<vector<ll>> &v){
    while(!q.empty()){
        ll Node  = q.front() ;
        for(auto x:v[Node]){
            indegree[x]-- ;
            if (indegree[x]==0){
                q.push(x) ;
            }
        }
        as.push_back(Node) ;
        q.pop() ;
    }
    return ;
}
void solve(){
    ll n , m ; cin >> n >> m  ;
    vector<vector<ll>> v(n+1) ; 
    indegree.resize(n+1,0) ;
    loop(m){
        ll x ,y ; cin >> x >> y ;
        v[x].push_back(y) ;
        indegree[y]++ ;
    }
    for(ll i=1;i<=n;i++){
        if (indegree[i]==0){
            q.push(i) ;
        }
    }
    topo_sort(v) ;
    for(auto x:as){
        cout << x << " " ;
    }
    cout << ln ;
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