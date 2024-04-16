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

ll  inf = 1e12 ;
ll n , m ,q ; 
void solve(){
    cin >> n >> m >> q;
    ll dis[n+1][n+1] ;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            if (i == j) dis[i][j] = 0;  
            else dis[i][j] = inf;
        }
    }
    loop(m){
        ll  x ,y , wt ; 
        cin >> x >> y >> wt ;
        dis[x][y] = min(dis[x][y],wt) ;
        dis[y][x] = min(dis[y][x],wt) ;
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]) ;
            }
        }
    }
    while(q--){
        ll x , y ; cin >> x >> y ;
        cout << ((dis[x][y]>=inf)?-1:dis[x][y]) << ln ;
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