# include <iostream>
# include <vector>

using namespace std;

template<class T>
class Heap {
private:
    T *arr;
    int capacity;
    int sz;

    int parent(int u) {
        return (u - 1) / 2;
    }

    int left(int u) {
        return 2 * u + 1;
    }

    int right(int u) {
        return 2 * u + 2;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int target = i;
        if (l < sz && arr[l] < arr[target])
            target = l;
        if (r < sz && arr[r] < arr[target])
            target = r;
        if (target != i) {
            swap(arr[i], arr[target]);
            heapify(target);
        }
    }

    void build(vector<int> &v) {
        sz = (int) v.size();
        capacity = sz + 10;
        arr = new T[capacity];
        for (int i = 0; i < sz; ++i) {
            arr[i] = v[i];
        }
        for (int i = sz / 2 - 1; i > -1; --i) {
            heapify(i);
        }
    }

public:
    Heap(int capacity = 10) {
        this->capacity = capacity;
        sz = 0;
        arr = new T[capacity];
    }

    Heap(vector<int> &v) {
        build(v);
    }


    T &top() {
        return arr[0];
    }

    bool empty() {
        return sz == 0;
    }

    int size() {
        return sz;
    }

    void push(T &element) {
        if (sz == capacity) {
            cout << "Out of Space\n";
            return;
        }
        int id = sz++;
        // put the element in the last place
        arr[id] = element;
        // swap until the min heap is not violated
        while (id && arr[parent(id)] > arr[id]) {
            swap(arr[id], arr[parent(id)]);
            id = parent(id);
        }
    }

    void pop() {
        swap(arr[0], arr[--sz]);
        heapify(0);
    }

    void sort(vector <T> &v) {
        build(v);
        for (int i = 0; i < (int) v.size(); ++i) {
            v[i] = top();
            pop();
        }
    }

    ~Heap() {
        delete[] arr;
    }
};

template<class T>
void heapSort(vector <T> &arr) {
    Heap<T> heap;
    heap.sort(arr);
}

int main() {

    return 0;
}
