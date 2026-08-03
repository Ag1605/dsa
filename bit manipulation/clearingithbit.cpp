#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i;
    cin >> n >> i;

    // Clear the i-th bit (make it 0)
    n = n & ~(1 << i);

    cout << n;

    return 0;
}