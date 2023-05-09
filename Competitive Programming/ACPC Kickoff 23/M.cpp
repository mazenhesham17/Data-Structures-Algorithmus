/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 04:23:17
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
    string a , b ; cin >> a >> b ;
    cout << b ;
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}