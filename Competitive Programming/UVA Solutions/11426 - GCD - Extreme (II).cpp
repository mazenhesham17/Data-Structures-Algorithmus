/**
 *    author:  Mazen Hesham
 *    created: 22.03.2023 01:56:13
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

vector<int> primes ;
vector<ll> coPrimes ;

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

int phi( int n ){
    int res = n ;
    while ( n > 1 ){
        int i = primes[n] ;
        while ( n % i == 0 ){
            n /= i ;
        }
        res -= res/i ;
    }
    return res ;
}

void pre( int n ){
    primes = sieve(n) ;
    coPrimes = vector<ll>(n) ;
    for (int i = 1; i < n; ++i) {
        coPrimes[i] = phi(i) ;
    }
    for (int i = 2; i < n; ++i) {
        coPrimes[i] += coPrimes[i-1] ;
    }
}

void solve() {
    pre(4e6+5) ;
    int n ;
    while ( cin >> n ){
        if ( !n )
            break;
        ll ans = 0 ;
        for (int i = 1; i <= n; ++i) {
            int cnt = n/i ;
            ans += (coPrimes[cnt]-1)*i ;
        }
        cout << ans << '\n' ;
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