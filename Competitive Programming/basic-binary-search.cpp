# include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5} ;
    int l = 0 , r = (int)v.size() - 1 , ans = -1 , target = 5 ;
    while ( l <= r ){
        int mid = (l+r)/2 ;
        if ( v[mid] > target )
            r = mid - 1 ;
        else if ( v[mid] < target )
            l = mid + 1 ;
        else
            ans = mid , l = r + 1 ;
    }
    cout << ans << '\n' ;
    return 0;
}