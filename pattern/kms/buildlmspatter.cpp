#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
Function: buildLPS()
Purpose:
    Builds the LPS (Longest Prefix Suffix) array for the pattern.

What is LPS?

LPS[i] = Length of the longest proper prefix
         which is also a suffix
         for substring pattern[0...i].

Proper Prefix:
    Prefix excluding the complete string itself.

Suffix:
    Ending part of the string.

Example:
Pattern = "ababaca"

Index : 0 1 2 3 4 5 6
Char  : a b a b a c a

LPS   : 0 0 1 2 3 0 1

Meaning:
LPS[4] = 3

Substring = "ababa"

Prefixes:
a
ab
aba
abab

Suffixes:
a
ba
aba
baba

Longest common = "aba"
Length = 3
------------------------------------------------------------
*/

vector<int> buildLPS(string pattern)
{
    // Total number of characters in pattern
    int n = pattern.size();

    // Initially every LPS value is 0
    vector<int> lps(n, 0);

    /*
    len = length of previous longest prefix suffix

    Initially first character has no proper prefix
    and suffix.

    So,
    len = 0
    */
    int len = 0;

    /*
    i starts from 1 because

    LPS[0] is always 0.

    A single character cannot have
    a proper prefix and suffix.
    */
    int i = 1;

    /*
    Continue until every character
    of pattern is processed.
    */
    while (i < n)
    {
        //--------------------------------------------------
        // CASE 1 : Characters Match
        //--------------------------------------------------

        if (pattern[i] == pattern[len])
        {
            /*
            Matching means current prefix
            can be extended.

            Increase prefix length.
            */
            len++;

            /*
            Store updated prefix length.
            */
            lps[i] = len;

            /*
            Move to next character.
            */
            i++;
        }

        //--------------------------------------------------
        // CASE 2 : Characters Do Not Match
        //--------------------------------------------------
        else
        {
            /*
            If mismatch occurs and
            we already have some matched prefix,
            do NOT restart from zero.

            Instead,

            Jump to previous possible prefix.

            Example:

            Pattern = "abababx"

            Current len = 4

            Instead of checking from start,

            Jump to

            lps[len-1]

            which already tells us the next
            possible prefix length.
            */

            if (len != 0)
            {
                /*
                Move len backward using
                previously computed LPS.

                i does NOT move.

                We again compare same character.
                */
                len = lps[len - 1];
            }
            else
            {
                /*
                No prefix available.

                Therefore answer is zero.
                */
                lps[i] = 0;

                /*
                Move forward.
                */
                i++;
            }
        }
    }

    return lps;
}

int main()
{
    // Example pattern
    string pattern = "ababaca";

    // Build LPS array
    vector<int> lps = buildLPS(pattern);

    cout << "Pattern : " << pattern << endl;

    cout << "Index   : ";
    for (int i = 0; i < pattern.size(); i++)
        cout << i << " ";

    cout << endl;

    cout << "Chars   : ";
    for (char ch : pattern)
        cout << ch << " ";

    cout << endl;

    cout << "LPS     : ";
    for (int x : lps)
        cout << x << " ";

    cout << endl;

    return 0;
}