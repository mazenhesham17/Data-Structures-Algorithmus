vector<int> primes ;

vector<int> sieve( int n ){
    vector<int> sieve( n + 1 ) ;
    vector<int> pr ;
    for (int i = 2; i <= n; ++i) {
        if ( sieve[i] == 0 ){
            sieve[i] = i ;
            pr.push_back(i) ;
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= sieve[i] && i*pr[j] <= n ; ++j) {
            sieve[i*pr[j]] = pr[j] ;
        }
    }
    return sieve ;
}

vector<int> factorize( int n , vector<int> &pre ){
    vector<int> res ;
    while ( n > 1 ){
        res.push_back( pre[n] ) ;
        n /= pre[n] ;
    }
    return res ;
}

void util( int i , int div , vector<pair<int,int>> &factors , vector<int> &d ){
    if ( i == factors.size() ){
        d.push_back(div) ;
        return;
    }
    for (int j = 0; j <= factors[i].second ; ++j) {
        util(i+1, div, factors , d ) ;
        div *= factors[i].first ;
    }
}

vector<int> divisors( int n , vector<int> &pre ){
    vector<int> res ;
    while ( n > 1 ){
        res.push_back( pre[n] ) ;
        n /= pre[n] ;
    }
    vector<pair<int,int>> v ;
    for ( auto &it : res ){
        if ( v.empty() || v.back().first != it )
            v.emplace_back(it,1) ;
        else
            v.back().second++ ;
    }
    res.clear() ;
    util(0,1,v,res) ;
    return res ;
}