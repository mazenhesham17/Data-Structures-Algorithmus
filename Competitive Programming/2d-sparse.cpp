// 2d sparse table return minimum element
template< typename T >
class MatrixSparse{
private:
    vector<vector<vector<vector<T>>>> table ;
    vector<short> lg ;
public:
    MatrixSparse( vector<vector<T>> &grid ){
        int n = (int)grid.size() ;
        int m = (int)grid.front().size() ;
        int mx = max(n,m) ;
        // preprocess the log2
        lg = vector<short>(mx+1) ;
        lg[1] = 0 ;
        for (int i = 2; i <= mx; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        int lgn = __lg(n) ;
        int lgm = __lg(m) ;
        table = vector<vector<vector<vector<T>>>>(lgn+1,vector<vector<vector<T>>>
                (n+1,vector<vector<T>>
                        (lgm+1,vector<T>
                                (m+1)))) ;
        // init value
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                table[0][i][0][j] = grid[i][j] ;
            }
            for (int k = 1; k <= lgm ; ++k) {
                for (int j = 0; j + ( 1 << k ) <= m; ++j) {
                    table[0][i][k][j] = min(table[0][i][k-1][j],table[0][i][k-1][ j + ( 1 << (k - 1) )]) ;
                }
            }
        }

        for (int i = 1; i <= lgn ; ++i) {
            for (int j = 0; j + ( 1 << i ) <= n; ++j) {
                for (int k = 0; k <= lgm; ++k) {
                    for (int l = 0; l <= m; ++l) {
                        table[i][j][k][l] = min(table[i-1][j][k][l],table[i-1][j + ( 1 << ( i - 1 ) ) ][k][l]) ;
                    }
                }
            }
        }
    }

    T query( int x1 , int y1 , int x2 , int y2 ){
        int x = lg[x2 - x1 + 1] , y = lg[y2 - y1 + 1] ;
        T res = min(table[x][x1][y][y1],table[x][x1][y][y2 - ( 1 << y ) + 1 ]) ;
        res = min(res,min(table[x][x2 - ( 1 << x ) + 1 ][y][y1],table[x][x2 - ( 1 << x ) + 1 ][y][ y2 - ( 1 << y ) + 1 ])) ;
        return res ;
    }
};