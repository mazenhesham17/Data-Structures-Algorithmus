/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 10:43:22
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 998244353 ;

ll add( ll x , ll y ){
    return ( (x%M) + (y%M) )%M ;
}

ll mins( ll x , ll y ){
    return ( (x%M) + (-y%M + M) )%M ;
}

ll mul( ll x , ll y ){
    return ( (x%M) * (y%M) )%M ;
}


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

void solve() {
    int n ; cin >> n ;
    set<int> st ;
    for (int i = 0; i < n; ++i) {
        int x ; cin >> x ;
        st.insert(x) ;
    }
    n = (int)st.size() ;
    ll ans = binPow(3,n) ;
    ans = mins(ans,3) ;
    ans = mul(ans, binPow(6,M-2) ) ;
    cout << ans << '\n' ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; cin >> t ;
    while (t--)
        solve();
    return 0;
}
