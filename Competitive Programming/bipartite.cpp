vector<vector<int>> G ;
vector<int> color ;
bool isBipartite = true ;

void dfs( int n , bool c ){
    for ( auto &it : G[n] ){
        if ( color[it] != -1 ){
            dfs(it,!c) ;
        }
        if ( color[it] == c ){
            isBipartite = false ;
            return;
        }
    }
}