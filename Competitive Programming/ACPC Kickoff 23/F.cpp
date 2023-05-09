/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 04:10:06
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

void solve() {
    int n ; cin >> n ;
    vector<int> v(n) ;
    for (int i = 0; i < n; ++i) {
        int x ; cin >> x ;
        v[i] = x & 1 ;
    }
    int l = 0 , r = 0 , ans = -1 , sum = 0 ;
    while ( r < n ){
        sum += v[r++] ;
        while ( sum > 1 ){
            sum -= v[l++] ;
        }
        if ( sum ){
            ans = max(ans,r-l) ;
        }
    }
    cout << ans ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}