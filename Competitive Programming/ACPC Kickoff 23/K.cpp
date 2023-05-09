/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 08:29:35
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 ;

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

ll linearSum( ll x ){
    ll res = mul(x,x+1) ;
    res = mul(res, binPow(2,M-2)) ;
    return res ;
}

ll squareSum( ll x ){
    ll res = mul(x,x+1) ;
    res = mul(res,2*x+1) ;
    res = mul(res, binPow(6,M-2) ) ;
    return res ;
}

void solve() {
    int n ; cin >> n ;
    ll ans = mul(8, squareSum(n/2)) ;
    if ( n & 1 ){
        // sum = sigma 8*i^2 + 2*i
        ans = add(ans, mul(2, linearSum(n/2)) ) ;
    }else{
        // sum = sigma 8*i^2 - 6*i + 1
        ans = mins(ans, mul(6, linearSum(n/2))) ;
        ans = add(ans,n/2) ;
    }
    cout << ans << '\n' ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; cin >> t ;
    while (t--)
        solve();
    return 0;
}