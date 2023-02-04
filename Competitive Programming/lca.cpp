int n , l ;
vector<int> depth ;
vector<vector<int>> par , G ;

void pr(){
    depth = vector<int>(n) ;
    l = 0 ;
    while ( ( 1 << l ) <= n ) l++ ;
    par = vector<vector<int>>( n , vector<int>(l+1)) ;
    G = vector<vector<int>>(n) ;
}

void dfs( int u , int p ){
    par[u][0] = p ;
    for ( auto &v : G[u] ){
        if ( v != p ){
            depth[v] = depth[u] + 1 ;
            dfs(v,u) ;
        }
    }
}

void init( int root ){
    depth[root] = 0 ;
    dfs(root,-1) ;
    for (int i = 1; i <= l; ++i) {
        for (int j = 0; j < n; ++j) {
            if ( ~par[j][i-1] )
                par[j][i] = par[par[j][i-1]][i-1] ;
            else
                par[j][i] = -1 ;
        }
    }
}

int kthAncestor( int u , int k ){
    k = min( depth[u] , k ) ;
    for (int i = 0; ( 1 << i ) <= k; ++i) {
        if ( ( k >> i ) & 1 ){
            u = par[u][i] ;
        }
    }
    return u ;
}

int LCA( int u , int v ){
    if ( depth[u] < depth[v] ) swap(u,v) ;
    int dif = min( depth[u] , depth[u] - depth[v]) ;
    u = kthAncestor(u,dif) ;
    if ( u == v ) return u ;
    int m = ceil(log2(depth[u])) ;
    for (int i = m ; ~i ; --i) {
        if ( par[u][i] != par[v][i] ){
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }
    return par[u][0] ;
}

int getDist( int u , int v ){
    return depth[u] + depth[v] - 2*depth[LCA(u,v)] ;
}