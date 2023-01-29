# include <iostream>
# include <vector>

using namespace std;

template<typename T>
void bubbleSort(vector <T> &arr) {
    int len = (int) arr.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < len - i; ++j) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

int main() {

    return 0;
}