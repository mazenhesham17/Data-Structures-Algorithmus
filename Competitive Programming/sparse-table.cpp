// sparse table return index for the minimum or maximum

template< class T > // 0-based
struct Sparse{
    vector<T> v ;
    vector<vector<int>> table ;
    vector<int> lg ;
    bool flag ;
    Sparse( vector<T> &_v , bool _max ){
        flag = _max ;
        v = _v ;
        int n = (int)v.size() ;
        int k = __lg(n) ;
        table = vector<vector<int>> ( n + 1 , vector<int>(k + 1 ) ) ;
        for (int i = 0; i < n; ++i) {
            table[i][0] = i ;
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j + ( 1 << i ) <= n ; ++j) {
                if ( flag ){
                    if ( v[table[j][i-1]] > v[table[j + ( 1 << ( i - 1 ) )][i-1]] ){
                        table[j][i] = table[j][i-1] ;
                    }else{
                        table[j][i] = table[j + ( 1 << ( i - 1 ) )][i-1] ;
                    }
                }else{
                    if ( v[table[j][i-1]] < v[table[j + ( 1 << ( i - 1 ) )][i-1]] ){
                        table[j][i] = table[j][i-1] ;
                    }else{
                        table[j][i] = table[j + ( 1 << ( i - 1 ) )][i-1] ;
                    }
                }
            }
        }
        lg = vector<int>(n+1) ;
        lg[1] = 0 ;
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i/2] + 1 ;
        }
    }

    T query( int l , int r ){
        int m = lg[r-l+1] , id ;
        if ( flag ){
            if ( v[table[l][m]] > v[table[ r - ( 1 << m ) + 1 ][m]] ){
                id = table[l][m] ;
            }else{
                id = table[ r - ( 1 << m ) + 1 ][m] ;
            }
        }else{
            if ( v[table[l][m]] < v[table[ r - ( 1 << m ) + 1 ][m]] ){
                id = table[l][m] ;
            }else{
                id = table[ r - ( 1 << m ) + 1 ][m] ;
            }
        }
        return id ;
    }
};