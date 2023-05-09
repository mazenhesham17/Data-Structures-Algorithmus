/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 06:41:53
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 , N = 1e5 + 5 ;
int n , k , dp[N][11][11] ;

ll add( ll x , ll y ){
    return ( (x%M) + (y%M) )%M ;
}

int go( int i , int last , int picked ){
    if ( i == n )
        return 1 ;
    int &ret = dp[i][last][picked] ;
    if ( ~ret ) return ret ;
    ret = 0 ;
    for (int j = 0; j < picked; ++j) {
        ret = add( ret , go(i+1,last,picked) ) ;
    }
    for (int j = last + 1 ; j < k; ++j) {
        ret = add(ret , go(i+1,j,picked+1)) ;
    }
    return ret ;
}

void solve() {
    cin >> n >> k ;
    int ans = 0 ;
    ::memset(dp,-1,sizeof dp) ;
    for (int i = 0; i < k; ++i) {
        char x ; cin >> x ;
        ans = add(ans, go(1,i,1)) ;
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