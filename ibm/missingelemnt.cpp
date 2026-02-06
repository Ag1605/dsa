#include <bits/stdc++.h>
using namespace std;

int findMissing(int arr[], int n) {
    int xor1 = 0;   // XOR of array elements
    int xor2 = 0;   // XOR of numbers from 1 to n+1

    // XOR all array elements
    for (int i = 0; i < n; i++) {
        xor1 ^= arr[i];
    }

    // XOR numbers from 1 to n+1
    for (int i = 1; i <= n + 1; i++) {
        xor2 ^= i;
    }

    // Missing number
    return xor1 ^ xor2;
}

int main() {
    int arr[] = {3, 7, 1, 2, 8, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing Element: " << findMissing(arr, n);
    return 0;
}
