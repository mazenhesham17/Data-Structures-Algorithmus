# include <iostream>
# include <vector>

using namespace std ;

template< typename T >
void shellSort( vector<T> & arr ){
    int len = (int)arr.size() ;
    for (int gap = len/2  ; gap ; gap >>= 1 ) {
        for (int i = gap ; i < len; i++ ) {
            for (int j = i ; j >= gap && arr[j] < arr[j-gap] ; j -= gap ) {
                swap(arr[j],arr[j-gap]) ;
            }
        }
    }
}

int main(){
    int len ; cin >> len ;
    vector<int> arr(len) ;
    for (int i = 0; i < len; ++i) {
        cin >> arr[i] ;
    }
    shellSort(arr) ;
    for (int i = 0; i < len ; ++i) {
        cout << arr[i] << ' ' ;
    }
    cout << '\n' ;
    return 0 ;
}
