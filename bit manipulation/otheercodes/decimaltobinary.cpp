#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n)
{
    if (n == 0)
        return "0";

    string result = "";

    while (n > 0)
    {
        if (n % 2 == 1)
            result += '1';
        else
            result += '0';

        n = n / 2;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    int n;
    cin >> n;

    cout << decimalToBinary(n);

    return 0;
}