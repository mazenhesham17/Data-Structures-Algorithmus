# include <iostream>
# include <vector>

using namespace std;

template<typename T>
void selectionSort(vector <T> &arr) {
    int len = (int) arr.size();
    for (int i = 0; i < len; ++i) {
        int mini = i;
        for (int j = i; j < len; ++j) {
            if (arr[mini] > arr[j])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}

int main() {

    return 0;
}