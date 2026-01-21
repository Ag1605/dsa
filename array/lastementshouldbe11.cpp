#include <bits/stdc++.h>
using namespace std;

void moveOnesToEnd(vector<int>& arr) {
    int index = 0;

    // Place all non-1 elements first
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 1) {
            arr[index++] = arr[i];
        }
    }

    // Fill remaining positions with 1
    while (index < arr.size()) {
        arr[index++] = 1;
    }
}

int main() {
    vector<int> arr = {1, 0, 1, 2, 1, 3, 4};
    moveOnesToEnd(arr);

    for (int x : arr)
        cout << x << " ";
}
