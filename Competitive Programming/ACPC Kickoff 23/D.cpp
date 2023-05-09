/**
 *    author:  Mazen Hesham
 *    created: 06.05.2023 04:50:35
**/
# include <bits/stdc++.h>
# define int long long
# define all(x) x.begin(),x.end()

using namespace std;

const int M = 1e9 + 7 ;

void solve() {
    int n;
    cin >> n;
    pair<int, int> cur;
    cin >> cur.first >> cur.second;
    map<int, vector<int>> x, y;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        x[u].push_back(v);
        y[v].push_back(u);
    }
    for (auto &i: x)
        sort(i.second.begin(), i.second.end());
    for (auto &i: y)
        sort(i.second.begin(), i.second.end());
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'R') {
            auto ub = upper_bound(y[cur.second].begin(), y[cur.second].end(), cur.first);
            if (ub != y[cur.second].end())
                cur.first = *ub;
        } else if (c == 'L') {
            auto lb = lower_bound(y[cur.second].begin(), y[cur.second].end(), cur.first);
            if (lb != y[cur.second].begin()) {
                lb--;
                cur.first = *lb;
            }
        } else if (c == 'U') {
            auto ub = upper_bound(x[cur.first].begin(), x[cur.first].end(), cur.second);
            if (ub != x[cur.first].end())
                cur.second = *ub;
        } else {
            auto lb = lower_bound(x[cur.first].begin(), x[cur.first].end(), cur.second);
            if (lb != x[cur.first].begin()) {
                lb--;
                cur.second = *lb;
            }
        }
        cout << cur.first << " " << cur.second << '\n' ;
    }
}

signed main() {
    cin.tie(nullptr), cout.tie(nullptr), iostream::sync_with_stdio(false) ;
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}