const int N = 2e5 + 5 , SEGN = 4*N ;

int seg[SEGN] ;
int n ;
vector<int> v ;

void build( int si = 0 , int ss = 0 , int se = n - 1 ){
    if ( ss == se ){
        seg[si] = v[ss] ;
        return;
    }
    int md = ss + (se - ss) / 2, lf = 2 * si + 1, rt = 2 * si + 2;
    build(lf,ss,md) ;
    build(rt,md+1,se) ;
    seg[si] = seg[lf] + seg[rt] ;
}

int query( int qs , int qe , int si = 0 , int ss = 0 , int se = n - 1 ){
    if ( ss > qe || se < qs )
        return 0 ;
    if ( ss >= qs && se <= qe )
        return seg[si] ;
    int md = ss + (se - ss) / 2, lf = 2 * si + 1, rt = 2 * si + 2;
    return query(qs,qe,lf,ss,md) + query(qs,qe,rt,md+1,se) ;
}

void update( int qi , int v , int si = 0 , int ss = 0 , int se = n - 1 ){
    if ( ss == se ){
        seg[si] = v ;
        return;
    }
    int md = ss + (se - ss) / 2, lf = 2 * si + 1, rt = 2 * si + 2;
    if ( qi <= md )
        update(qi,v,lf,ss,md) ;
    else
        update(qi,v,rt,md+1,se) ;
    seg[si] = seg[lf] + seg[rt] ;
}