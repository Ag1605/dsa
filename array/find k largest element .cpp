#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& arr, int k) {
    int n = arr.size();
    nth_element(arr.begin(), arr.begin() + (n - k), arr.end());
    return arr[n - k];
}


// nth element dont sort the array but it puts the kth largest element at the correct position lol 



int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(arr, k);
}
