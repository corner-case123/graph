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

void dijkstra(vector<vector<pll>>& graph, vll& dist, ll start) {
    // pll is the elements of the priority_queue 
    // vector<pll> is the conatiner used by the queue
    // greater<pll> is the comparator function to set the priority 
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll u_dist = pq.top().first;
        pq.pop();

        if (u_dist > dist[u]) continue;

        for (auto& neighbor : graph[u]) {
            ll v = neighbor.first;
            ll uv_weight = neighbor.second;

            if (dist[u] + uv_weight < dist[v]) {
                dist[v] = dist[u] + uv_weight;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1);
    vll dist(n + 1, LLONG_MAX);

    loop(m) {
        ll x, y, c;
        cin >> x >> y >> c;
        graph[x].push_back({y, c});
    }

    dijkstra(graph, dist, 1);

    for(ll i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << ln;
}

int main(){
    ll t = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(t--) solve();
    return 0;
}
