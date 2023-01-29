# include <iostream>
# include <vector>

using namespace std;

template<class T>
void medianOfThree(vector <T> &arr, int l, int r) {
    int mid = l + (r - l) / 2;
    if (arr[r] < arr[l])
        swap(arr[l], arr[r]);
    if (arr[mid] < arr[l])
        swap(arr[mid], arr[l]);
    if (arr[r] < arr[mid])
        swap(arr[mid], arr[r]);
    swap(arr[mid], arr[r]);
}

template<class T>
int partition(vector <T> &arr, int l, int r) {
    medianOfThree(arr, l, r);
    int pivot = arr[r], i = l - 1;
    while (l < r) {
        if (arr[l] < pivot) {
            i++;
            swap(arr[i], arr[l]);
        }
        l++;
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}


template<typename T>
void divide(vector <T> &arr, int l, int r) {
    if (l >= r)
        return;
    int mid = partition(arr, l, r);
    divide(arr, l, mid - 1);
    divide(arr, mid + 1, r);
}

template<typename T>
void quickSort(vector <T> &arr) {
    int len = (int) arr.size();
    divide(arr, 0, len - 1);
}

int main() {

    return 0;
}
