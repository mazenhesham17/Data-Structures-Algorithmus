// condition is the negation of what desired
vector<int> build_next( vector<int>&v ){
    int n = (int)v.size() ;
    vector<int> next(n) ;
    stack<int> st ;
    st.push(n) ;
    for (int i = n - 1 ; i > -1 ; --i) {
        while ( st.top() != n && v[st.top()] >= v[i] ) st.pop() ;
        next[i] = st.top() ;
        st.push(i) ;
    }
    return next ;
}

vector<int> build_prev( vector<int>&v ){
    int n = (int)v.size() ;
    vector<int> prev(n) ;
    stack<int> st ;
    st.push(-1) ;
    for (int i = 0; i < n; ++i) {
        while ( st.top() != -1 && v[st.top()] >= v[i] ) st.pop() ;
        prev[i] = st.top() ;
        st.push(i) ;
    }
    return prev ;
}