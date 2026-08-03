#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    // Check if n is a power of 2
    if (n > 0 && (n & (n - 1)) == 0)
        cout << "Power of 2";
    else
        cout << "Not a Power of 2";

    return 0;
}