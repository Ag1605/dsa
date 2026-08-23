#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {

    int n = arr.size();

    // i represents the position
    // where minimum element should go
    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        // Find minimum element
        // in remaining unsorted part
        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Put minimum element
        // at correct position
        swap(arr[i], arr[minIndex]);
    }
}

int main() {

    vector<int> arr = {5, 3, 8, 4, 2};

    selectionSort(arr);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}