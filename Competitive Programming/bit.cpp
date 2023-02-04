struct BIT{
    int n ;
    vector<ll> v ;
    BIT( int _n ) : n(_n) , v( 1 << int(__lg(n)+1)) {}
    void add ( int i , ll m ){
        for ( ++i ; i <= n ; i += ( i & -i ) ){
            v[i-1] += m ;
        }
    }
    ll point( int i ){
        ll sum = 0 ;
        for ( i++ ; i ; i -= ( i & -i ) )
            sum += v[i-1] ;
        return sum ;
    }
    int lower_bound( ll m ){
        int i = 0 ;
        for (int j = n ; j ; j >>= 1 ) {
            if ( m > v[i+j-1] )
                m -= v[i+j-1] , i += j ;
        }
        return i ;
    }
};