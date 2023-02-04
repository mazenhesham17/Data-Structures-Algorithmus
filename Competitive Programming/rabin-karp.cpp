const int M = 1e9 + 7 ;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % M;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % M;
        y = y >> 1;
        x = (x * x) % M;
    }
    return res % M;
}

// 31 53

ll push_back( ll hash , int ch , int base ){
    return ( ( hash * base )%M + ch )%M ;
}

// i is the length of the string
ll push_front( ll hash , int ch , int base , int i ){
    return (( hash + (ch * power(base, i) ) % M ) % M ) ;
}

// i is the length of the string - 1
ll pop_front( ll hash , int ch , int i , int base ){
    return (hash - (power(base, i) * ch ) % M + M ) % M ;
}

ll pop_back( ll hash , int ch , int base ){
    ll x = ( hash - ch + M  )%M ;
    return (x * power(base, M - 2) ) % M ;
}