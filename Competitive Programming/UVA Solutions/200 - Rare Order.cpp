/**
 *    author:  Mazen Hesham
 *    created: 23.03.2023 02:15:27
**/
# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

map<char,vector<char>> G ;
map<char,bool> vis ;
string ans ;

void dfs( char u ){
    vis[u] = true ;
    for ( auto &v : G[u] ){
        if ( vis[v] ) continue;
        dfs(v) ;
    }
    ans.push_back(u) ;
}

void solve() {
    string s ;
    vector<string> v ;
    while ( cin >> s && s != "#" ){
        v.push_back(s) ;
    }
    int n = (int)v.size() ;
    for (int i = 1; i < n; ++i) {
        auto a = v[i-1] , b = v[i] ;
        for (int j = 0; j < min(a.size(),b.size()); ++j) {
            if ( a[j] != b[j] ){
                G[a[j]].push_back(b[j]) ;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (char j : v[i]) {
            if ( !vis[j] ){
                dfs(j) ;
            }
        }
    }
    reverse(all(ans)) ;
    cout << ans << '\n' ;
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