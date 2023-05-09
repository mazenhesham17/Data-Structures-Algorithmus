/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 05:07:23
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 ;

void solve() {
    int n , k  ; cin >> n >> k ;
    map<int,int> mp ;
    for (int i = 0; i < n; ++i) {
        int x ; cin >> x ;
        mp[x]++ ;
    }
    vector<int> v ;
    for ( auto &it : mp ){
        v.push_back(it.second) ;
    }
    sort(all(v)) ;
    int cnt = v.size() ;
    for (int i = 0; i < v.size(); ++i) {
        if ( v[i] <= k ){
            cnt-- ;
            k -= v[i] ;
        }
    }
    cout << cnt ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}