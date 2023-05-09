/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 06:18:33
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 ;

ll mul( ll x , ll y ){
    return ( (x%M) * (y%M) )%M ;
}

void solve() {
    int n , m , k ; cin >> n >> m >> k ;
    vector<ll> v(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] ;
        v[i] = abs(v[i]) ;
    }
    sort(all(v),greater<>()) ;
    ll p = 1 ;
    for (int i = 0; i < m; ++i) {
        p = mul(p,v[i]) ;
    }
    cout << p%M ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}