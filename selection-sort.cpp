# include <iostream>
# include <vector>

using namespace std ;

template< typename T >
void selectionSort( vector<T> & arr ){
    int len = (int)arr.size() ;
    for (int i = 0; i < len; ++i) {
        int mini = i ;
        for (int j = i; j < len; ++j) {
            if ( arr[mini] > arr[j] )
                mini = j ;
        }
        swap(arr[i],arr[mini]) ;
    }
}

int main(){
    int len ; cin >> len ;
    vector<int> arr(len) ;
    for (int i = 0; i < len; ++i) {
        cin >> arr[i] ;
    }
    selectionSort(arr) ;
    for (int i = 0; i < len ; ++i) {
        cout << arr[i] << ' ' ;
    }
    cout << '\n' ;
    return 0 ;
}