#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(vector<int> &arr, int k, long long pageLimit) {

    // Start with the first student.
    int cnt = 1;

    // Pages currently assigned to the current student.
    long long pageSum = 0;

    for(int i = 0; i < arr.size(); i++) {

        // If adding this book exceeds the page limit,
        // give this book to the next student.
        if(pageSum + arr[i] > pageLimit) {

            cnt++;

            // Start the new student with this book.
            pageSum = arr[i];

        }
        else {

            // Add the current book to the current student.
            pageSum += arr[i];
        }
    }

    // If we can allocate the books using k or fewer students,
    // then this page limit is possible.
    return cnt <= k;
}


int findPages(vector<int> &arr, int k) {

    // If there are more students than books,
    // every student cannot receive at least one book.
    if(k > arr.size()) {
        return -1;
    }

    // Minimum possible answer:
    // At least one student must take the largest book.
    long long left =
        *max_element(arr.begin(), arr.end());

    // Maximum possible answer:
    // One student could take all books.
    long long right =
        accumulate(arr.begin(), arr.end(), 0LL);

    // Store the best answer found.
    long long ans = right;

    // Binary search for the minimum possible
    // maximum number of pages.
    while(left <= right) {

        long long mid =
            left + (right - left) / 2;

        // Can we allocate all books to at most k students
        // if no student gets more than 'mid' pages?
        if(check(arr, k, mid)) {

            // 'mid' works.
            ans = mid;

            // Try to find an even smaller page limit.
            right = mid - 1;

        }
        else {

            // 'mid' is too small.
            // We need to allow more pages.
            left = mid + 1;
        }
    }

    return (int)ans;
}


int main() {

    vector<int> arr = {12, 34, 67, 90};

    int k = 2;

    cout << findPages(arr, k);

    return 0;
}