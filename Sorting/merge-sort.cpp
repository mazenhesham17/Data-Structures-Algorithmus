# include <iostream>
# include <vector>

using namespace std;

template<typename T>
void merge(vector <T> &arr, int l, int mid, int r) {
    vector<int> temp(r - l + 1);
    int lp = l, rp = mid + 1, tp = 0;
    while (lp <= mid && rp <= r) {
        if (arr[lp] < arr[rp]) {
            temp[tp++] = arr[lp++];
        } else {
            temp[tp++] = arr[rp++];
        }
    }
    while (lp <= mid) {
        temp[tp++] = arr[lp++];
    }
    while (rp <= r) {
        temp[tp++] = arr[rp++];
        tp++, rp++;
    }
    for (int i = l; i <= r; ++i) {
        arr[i] = temp[i - l];
    }
}

template<typename T>
void divide(vector <T> &arr, int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    divide(arr, l, mid);
    divide(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(vector <T> &arr) {
    int len = (int) arr.size();
    divide(arr, 0, len - 1);
}

int main() {

    return 0;
}
