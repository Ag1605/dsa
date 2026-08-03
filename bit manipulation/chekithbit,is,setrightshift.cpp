#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i;
    cin >> n >> i;

    // Shift the i-th bit to the last position
    // Then check whether the last bit is 1 or 0
    if ((n >> i) & 1)
        cout << "Bit is Set";
    else
        cout << "Bit is Not Set";

    return 0;
}