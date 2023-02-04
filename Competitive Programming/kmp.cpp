vector<int> build( string &s ){
    int n = (int)s.size() ;
    vector<int> lps(n) ;
    int b = 0 ;
    for (int i = 1; i < n; ++i) {
        while ( b > 0 && s[b] != s[i] ) b = lps[b-1] ;
        if ( s[b] == s[i] ) b++ ;
        lps[i] = b ;
    }
    return lps ;
}

vector<int> kmp( string &s , string &t ){
    int n = (int)s.size() , m = (int)t.size() ;
    vector<int> ans ;
    auto lps = build(s) ;
    int i = 0 , j = 0 ;
    while ( i < n ){
        if ( s[i] == t[j] ) i++ , j++ ;
        if ( j == m ) ans.push_back(i-j) , j = lps[j-1] ;
        else if (  i < n && s[i] != t[j] ) {
            if ( j ) j = lps[j-1] ;
            else i++ ;
        }
    }
    return ans ;
}