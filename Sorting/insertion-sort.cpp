# include <iostream>
# include <vector>

using namespace std;

template<typename T>
void insertionSort(vector <T> &arr) {
    int len = (int) arr.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

int main() {

    return 0;
}
