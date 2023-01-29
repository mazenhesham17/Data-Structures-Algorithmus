# include <iostream>
# include <vector>

using namespace std;

template<typename T>
void shellSort(vector <T> &arr) {
    int len = (int) arr.size();
    for (int gap = len / 2; gap; gap >>= 1) {
        for (int i = gap; i < len; i++) {
            for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap) {
                swap(arr[j], arr[j - gap]);
            }
        }
    }
}

int main() {

    return 0;
}
