# include <iostream>
# include <vector>

using namespace std;

int main() {
    int len;
    cin >> len;
    vector<int> arr(len);
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    shellSort(arr);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}
