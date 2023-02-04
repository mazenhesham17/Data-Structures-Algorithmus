# define ll long long

const int M = 1e9 + 7 ;

ll binPow( ll n , ll b ){
    ll res = 1 ;
    while ( b ){
        if ( b & 1 )
            res = ( (res%M) * (n%M) )%M ;
        n = ( (n%M) * (n%M) ) % M ;
        b >>= 1 ;
    }
    return res % M ;
}

ll add( ll x , ll y ){
    return ((x%M) + (y%M))%M ;
}

ll sub( ll x , ll y ){
    return ((x%M) + (-y%M+M)%M + M )%M ;
}

ll mul( ll x , ll y ){
    return ((x%M) * (y%M))%M ;
}

ll divide( ll x , ll y ){
    return ( (x%M) * binPow(y,M-2) )%M ;
}
