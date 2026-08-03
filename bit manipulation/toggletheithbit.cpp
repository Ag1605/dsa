#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i;
    cin >> n >> i;

    // Toggle the i-th bit
    n = n ^ (1 << i);

    cout << n;

    return 0;
}