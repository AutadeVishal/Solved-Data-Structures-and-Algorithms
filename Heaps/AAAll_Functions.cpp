#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class maxheap {
    int arr[100];
    int size;
public:
    maxheap() {
        size = 0;
    }

    void insert(int value) {
        size++;
        arr[size] = value;
        int i = size;
        while (i > 1) {
            int parent = i / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                return;
            }
        }
    }

    void heapifyDown(int arr[], int size, int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(arr, size, largest);
        }
    }

    void showarray() {
        for (int i = 1; i <= 10; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void show() {
        int level = 0;
        int elementsInLevel = 1;
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
            if (i == elementsInLevel) {
                cout << endl;
                level++;
                elementsInLevel += pow(2, level);
            }
        }
        cout << endl;
    }

    void deletefromheap() {
        if (size == 0) {
            cout << "Empty re Bhau" << endl;
            return;
        }
        swap(arr[1], arr[size--]);
        int i = 1;
        while (i <= size) {
            int leftchild = 2 * i;
            int rightchild = 2 * i + 1;
            int largest = i;

            if (leftchild <= size && arr[leftchild] > arr[largest]) {
                largest = leftchild;
            }
            if (rightchild <= size && arr[rightchild] > arr[largest]) {
                largest = rightchild;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void deletefromheapusingheapifydown() {
        if (size == 0) {
            cout << "Empty re Bhau" << endl;
            return;
        }
        swap(arr[1], arr[size--]);
        heapifyDown(arr, size, 1);
    }
};

int main() {
    maxheap h;
    int arr[10] = {10, 20, 30, 25, 5, 40, 35, 15};
    for (int i = 0; i < 10; i++) {
        h.insert(arr[i]);
    }
    h.show();
    h.deletefromheap();
    h.show();
    h.deletefromheapusingheapifydown();
    h.show();

    return 0;
}
