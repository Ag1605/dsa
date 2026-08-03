#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    // Remove the last set bit
    n = n & (n - 1);

    cout << n;

    return 0;
}