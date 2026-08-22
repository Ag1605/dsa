#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {

    int n = arr.size();

    // Outer loop = number of passes
    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;

        // Compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {

            // If current element is greater
            // than next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping happened,
        // array is already sorted
        if (!swapped)
            break;
    }
}

int main() {

    vector<int> arr = {5, 1, 4, 2, 8};

    bubbleSort(arr);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}