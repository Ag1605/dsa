#include <iostream>
using namespace std;

int NthRoot(int N, int M) {

    int low = 1, high = M;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        long long value = 1;

        // Compute mid^N safely
        for (int i = 1; i <= N; i++) {
            value *= mid;

            if (value > M)  // Stop early if exceeding
                break;
        }

        if (value == M)
            return mid;            // Found exact root

        else if (value < M)
            low = mid + 1;         // Go right

        else
            high = mid - 1;        // Go left
    }

    return -1;  // If no integer root exists
}

int main() {
    int N = 3, M = 27;

    cout << "Answer: " << NthRoot(N, M);

    return 0;
}
