#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);

    int left = 0;
    int right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        if (abs(arr[left]) > abs(arr[right])) {
            result[pos] = arr[left] * arr[left];
            left++;
        } else {
            result[pos] = arr[right] * arr[right];
            right--;
        }
        pos--;
    }

    return result;
}

int main() {
    vector<int> arr = {-7, -3, 2, 3, 11};

    vector<int> ans = sortedSquares(arr);

    for (int x : ans) {
        cout << x << " ";
    }
}