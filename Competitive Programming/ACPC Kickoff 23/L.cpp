/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 05:11:27
**/
# include <bits/stdc++.h>
# define int long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 ;

void solve() {
    int n ; cin >> n ;
    int odd = 0 , even = 0 ;
    for (int i = 0; i < n; ++i) {
        int x ; cin >> x ;
        if ( x & 1 )
            odd++ ;
        else
            even++ ;
    }
    odd = min(odd,even) ;
    cout << ( odd & 1 ? "Odd" : "Even" ) ;
}

signed main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}