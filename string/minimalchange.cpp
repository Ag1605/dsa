#include <bits/stdc++.h>
using namespace std;

// Function to calculate cost for current string
int calculateCost(string s) {
    int n = s.size();

    vector<int> even(26, 0), odd(26, 0);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even[s[i] - 'a']++;
        else
            odd[s[i] - 'a']++;
    }

    int maxEven = *max_element(even.begin(), even.end());
    int maxOdd  = *max_element(odd.begin(), odd.end());

    int evenCount = (n + 1) / 2;  // number of even positions
    int oddCount  = n / 2;        // number of odd positions

    return (evenCount - maxEven) + (oddCount - maxOdd);
}

int solve(string s) {
    int n = s.size();

    // ✅ Case 1: No deletion
    int answer = calculateCost(s);

    // ✅ Case 2: Try deleting one character
    for (int del = 0; del < n; del++) {

        string temp = s.substr(0, del) + s.substr(del + 1);

        int cost = calculateCost(temp);

        answer = min(answer, cost);
    }

    return answer;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s);
}