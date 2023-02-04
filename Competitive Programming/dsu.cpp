struct DSU{
    vector<int> parent  ;
    DSU( int n ){
        parent = vector<int>(n) ;
        for (int i = 0; i < n; ++i) {
            parent[i] = i ;
        }
    }
    int get( int a ){
        return parent[a] = ( parent[a] == a ? a : get(parent[a])) ;
    }
    bool same( int a , int b ){
        return ( get(a) == get(b) ) ;
    }
    void join( int a , int b ){
        a = get(a) , b = get(b) ;
        if ( a != b ){
            parent[a] = b ;
        }
    }
};