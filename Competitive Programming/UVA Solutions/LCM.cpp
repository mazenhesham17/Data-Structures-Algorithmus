/**
 *    author:  Mazen Hesham
 *    created: 22.03.2023 02:53:55
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int N = 1e6 + 5 , M = 10 ;

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

vector<int> factorize( int n ){
    vector<int> res ;
    while ( n > 1 ){
        res.push_back( primes[n] ) ;
        n /= primes[n] ;
    }
    return res ;
}

void solve() {
    primes = sieve(N) ;
    vector<int> mem(N,1) ;
    map<int,int> m1 , mod ;
    for (int i = 2; i < N ; ++i) {
        auto temp = factorize(i) ;
        map<int,int> m2 ;
        for ( auto &it : temp ){
            m2[it]++ ;
        }
        for ( auto &it : m2 ){
            int old = m1[it.first] ;
            m1[it.first] = max(m1[it.first],it.second) ;
            if ( it.first != 2 && it.first != 5 )
                mod[(it.first)%M] += m1[it.first] - old ;
        }
        int p ;
        if ( m1[2] > m1[5] ){
            p = binPow(2,m1[2]-m1[5]) ;
            p %= M ;
        }else{
            p = binPow(5,m1[5]-m1[2]) ;
            p %= M ;
        }
        // calculate the last digit
        for ( auto &it : mod ){
            p *= binPow(it.first,it.second) ;
            p %= M ;
        }
        mem[i] = p ;
    }
    int n ;
    while ( cin >> n ){
        if ( !n )
            break;
        cout << mem[n] << '\n' ;
    }
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}