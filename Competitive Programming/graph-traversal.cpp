# include <bits/stdc++.h>

using namespace std;

const int M = 1e9 ;

vector<vector<int>> G ;
vector<int> depth ;

void dfs( int u ){
    for ( auto &v : G[u] ){
        if ( depth[v] != -1 ){
            depth[v] = depth[u] + 1 ;
            dfs(v) ;
        }
    }
}

int main() {
    int n , m ; cin >> n >> m ;
    G = vector<vector<int>>(n) ;
    for (int i = 0; i < m; ++i) {
        int u , v ; cin >> u >> v ;
        u-- , v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    // dfs
    depth = vector<int>(n,-1) ;
    depth[0] = 0 ;
    dfs(0) ;
    // bfs
    vector<int> dis(n,M) ;
    dis[0] = 0 ;
    queue<int> q ;
    q.push(0) ;
    while ( !q.empty() ){
        int cur = q.front() ;
        q.pop() ;
        for ( auto &v : G[cur] ){
            if ( dis[v] > dis[cur] + 1 ){
                dis[v] = dis[cur] + 1 ;
                q.push(v) ;
            }
        }
    }
    return 0;
}