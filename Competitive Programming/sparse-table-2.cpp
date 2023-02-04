// sparse table return gcd
template< class T >
struct Sparse{
    vector<T> v ;
    vector<vector<T>> table ;
    vector<int> lg ;
    Sparse( vector<T> &_v ){
        v = _v ;
        int n = (int)v.size() ;
        int k = __lg(n) ;
        table = vector<vector<T>> ( n + 1 , vector<T>(k + 1 ) ) ;
        for (int i = 0; i < n; ++i) {
            table[i][0] = v[i] ;
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j + ( 1 << i ) <= n ; ++j) {
                table[j][i] = __gcd(table[j][i-1],table[j + ( 1 << ( i - 1 ) )][i-1]) ;
            }
        }
        lg = vector<int>(n+1) ;
        lg[1] = 0 ;
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i/2] + 1 ;
        }
    }

    T query( int l , int r ){
        int m = lg[r-l+1] ;
        return __gcd( table[l][m],table[ r - ( 1 << m ) + 1 ][m] ) ;
    }
};