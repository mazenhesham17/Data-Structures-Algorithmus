/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 04:05:10
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

void solve() {
    int n ; cin >> n ;
    ll sum = 0 ;
    vector<int> v ;
    for (int i = 0; i < n; ++i) {
        int x ; cin >> x ;
        if ( x & 1 ){
            v.push_back(x) ;
        }else{
            sum += x ;
        }
    }
    sort(all(v),greater<>()) ;
    n = v.size() ;
    for (int i = 0; i < n - ( n & 1 ); ++i) {
        sum += v[i] ;
    }
    cout << ( sum ? sum : -1 ) ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}