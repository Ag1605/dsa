#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i;
    cin >> n >> i;

    // Check if the i-th bit is set
    if (n & (1 << i))
        cout << "Set";
    else
        cout << "Not Set";

    return 0;
}