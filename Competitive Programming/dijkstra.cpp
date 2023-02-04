# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll M = 1e12 ;

int main() {
    int n , m ; cin >> n >> m ;
    vector<vector<pair<int,ll>>> G(n) ;
    for (int i = 0; i < m; ++i) {
        ll w ; int u , v ;
        cin >> u >> v >> w ;
        u-- , v-- ;
        G[u].push_back({v,w}) ;
        G[v].push_back({u,w}) ;
    }
    vector<ll> dis(n,M) ;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q ;
    dis[0] = 0 ;
    q.push({0,0}) ;
    while ( !q.empty() ){
        auto cur = q.top() ;
        q.pop() ;
        ll dist = cur.first ;
        int u = cur.second ;
        if ( dis[u] != dist )
            continue;
        for ( auto &child : G[u] ){
            int v = child.first ;
            ll w = child.second ;
            if ( dis[v] > dis[u] + w ){
                dis[v] = dis[u] + w ;
                q.push({dis[v],v}) ;
            }
        }
    }
    return 0;
}