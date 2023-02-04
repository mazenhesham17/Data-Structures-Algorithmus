# include <bits/stdc++.h>

using namespace std;

int main() {
    auto valid = [&]( int mid ){
        return true ; // validation function
    };
    int s = -1 , e = 10 + 1 ; // s = start -1 , e = end + 1
    while ( e - s != 1 ){
        int mid = s + (e-s)/2 ; // handle overflow
        if ( valid(mid) ) // FFFFTTTTT
            e = mid ;
        else
            s = mid ;
    }
    cout << e << '\n' ;
    return 0;
}