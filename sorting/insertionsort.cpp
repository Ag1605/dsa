#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {

    int n = arr.size();

    // Start from index 1 because
    // first element is considered sorted
    for (int i = 1; i < n; i++) {

        // Element that we want to insert
        int key = arr[i];

        // Start comparing with previous element
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            j--;
        }

        // Put key at its correct position
        arr[j + 1] = key;
    }
}

int main() {

    vector<int> arr = {5, 3, 4, 1, 2};

    insertionSort(arr);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}