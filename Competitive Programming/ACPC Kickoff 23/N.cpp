/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 08:08:10
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

const int N = 1e7 + 5 ;
pair<int,int> arr[N] ;

void pre(){
    for (int i = 0; i < N; ++i) {
        arr[i].first = -1 ;
    }
    int cnt = 0 ;
    arr[0] = arr[1] = {0,0} ;
    for (int i = 2; i < N; ++i) {
        if ( arr[i].first == -1 ){
            arr[i] = {i,++cnt} ;
            for (int j = 2*i ; j < N; j += i ) {
                arr[j] = {i,cnt} ;
            }
        }
    }
}

void solve() {
    int n , q ; cin >> n >> q ;
    vector<int> v(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] ;
    }
    ll r = 0 , b = 0 ;
    for (int i = 0; i < q; ++i) {
        pair<int,int> x = arr[v[i%n]] ;
        if ( x.first > 0 ){
            v[i%n] /= x.first ;
        }
        if ( x.second & 1 ){
            r += x.first ;
        }else{
            b += x.first ;
        }
        cout << ( r >= b ? "R" : "B" ) << '\n' ;
    }
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    pre() ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}