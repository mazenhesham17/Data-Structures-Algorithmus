/**
 *    author:  Mazen Hesham
 *    created: 29.03.2023 00:13:10
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

int n , tc ;
vector<int> temp ;
set<int> p = {2,3,5,7,11,13,17,19,23,29,31,37} , vis ;

void back(){
    if ( temp.size() == n && p.count(temp.back()+1) ){
        for (int i = 0; i < n; ++i) {
            cout << temp[i] << ( i == n - 1 ? '\n' : ' ' ) ;
        }
        return;
    }
    for (int j = 2; j <= n; ++j) {
        if ( vis.count(j) || !p.count(temp.back()+j) ) continue;
        vis.insert(j) ;
        temp.push_back(j) ;
        back() ;
        temp.pop_back() ;
        vis.erase(j) ;
    }
}

void solve() {
    while ( cin >> n ){
        if ( tc )
            cout << '\n' ;
        cout << "Case " << ++tc << ":" << '\n' ;
        temp = {1} ;
        back() ;
    }
}

int main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}