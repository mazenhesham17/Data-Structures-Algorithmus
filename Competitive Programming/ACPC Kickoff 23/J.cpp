/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 05:25:42
**/
# include <bits/stdc++.h>
# define int long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 ;

void solve() {
    int n ; cin >> n ;
    vector<int> v(n) ;
    map<int,int> pos ;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] ;
        pos[v[i]] = i ;
    }
    vector<int> dif(n) ;
    for (int i = 1; i < n; ++i) {
        dif[i-1] = ( v[i] - v[i-1] ) ;
    }
    for (int i = n - 2; i > -1 ; --i) {
        dif[i] = max( dif[i] , dif[i+1] ) ;
    }
    int q ; cin >> q ;
    while ( q-- ){
        int x , k ; cin >> x >> k ;
        cout << ( dif[pos[x]] <= k ? "YES" : "NO" ) << '\n' ;
    }
}

signed main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}