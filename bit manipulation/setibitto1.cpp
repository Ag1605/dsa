#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i;
    cin >> n >> i;

    // Set the i-th bit to 1
    n = n | (1 << i);

    cout << n;

    return 0;
}