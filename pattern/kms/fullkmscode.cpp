#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    -------------------------------------------------------------
    Function : buildLPS()

    LPS = Longest Proper Prefix which is also Suffix

    lps[i] stores the length of the longest proper prefix
    which is also a suffix for the substring pattern[0...i].

    Example:

    Pattern : ABABC

    Index   : 0 1 2 3 4
    Char    : A B A B C
    LPS     : 0 0 1 2 0

    Time Complexity : O(m)
    Space Complexity: O(m)
    -------------------------------------------------------------
    */
    vector<int> buildLPS(string pattern)
    {
        // Length of pattern
        int n = pattern.size();

        // Initially every LPS value is 0
        vector<int> lps(n, 0);

        /*
        len represents the length of the previous
        longest prefix which is also suffix.

        Initially there is no prefix.
        */
        int len = 0;

        /*
        First character always has LPS = 0,
        therefore start from index 1.
        */
        int i = 1;

        while (i < n)
        {
            //--------------------------------------------------
            // CASE 1 : Characters Match
            //--------------------------------------------------

            if (pattern[i] == pattern[len])
            {
                /*
                Prefix can now be extended.

                Increase prefix length.
                */
                len++;

                /*
                Store the prefix length.
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
                If some prefix already matched,
                don't restart from beginning.

                Jump to the previous valid prefix.

                Example

                Pattern : ABABAC

                Current len = 4

                Instead of checking from 0,
                jump to lps[3].
                */

                if (len != 0)
                {
                    /*
                    Move len backward.

                    Notice:
                    i does NOT move.

                    Same character will be compared
                    again with smaller prefix.
                    */
                    len = lps[len - 1];
                }
                else
                {
                    /*
                    No prefix exists.

                    Therefore answer is 0.
                    */
                    lps[i] = 0;

                    /*
                    Move to next character.
                    */
                    i++;
                }
            }
        }

        return lps;
    }

    /*
    -------------------------------------------------------------
    KMP Search Algorithm

    Goal:
    Find every occurrence of Pattern inside Text.

    Instead of moving text pointer backward,
    we shift the pattern using the LPS array.

    Time Complexity : O(n + m)

    n = length of text
    m = length of pattern
    -------------------------------------------------------------
    */
    vector<int> KMP(string text, string pattern)
    {
        // Build LPS array once
        vector<int> lps = buildLPS(pattern);

        // Stores all starting indices where pattern is found
        vector<int> ans;

        int n = text.size();
        int m = pattern.size();

        /*
        i -> Pointer for Text
        j -> Pointer for Pattern
        */
        int i = 0;
        int j = 0;

        /*
        Continue until whole text is processed.
        */
        while (i < n)
        {
            //--------------------------------------------------
            // CASE 1 : Characters Match
            //--------------------------------------------------

            if (text[i] == pattern[j])
            {
                /*
                Move both pointers.
                */
                i++;
                j++;
            }

            //--------------------------------------------------
            // CASE 2 : Entire Pattern Matched
            //--------------------------------------------------

            if (j == m)
            {
                /*
                Pattern found.

                Starting index is

                Current Text Index
                minus
                Pattern Length
                */
                ans.push_back(i - j);

                /*
                Instead of restarting from 0,

                Continue from the previous
                valid prefix.

                This is what makes KMP efficient.
                */
                j = lps[j - 1];
            }

            //--------------------------------------------------
            // CASE 3 : Characters Do Not Match
            //--------------------------------------------------

            else if (i < n && text[i] != pattern[j])
            {
                /*
                If some characters already matched,
                shift only the pattern.

                Do NOT move text pointer.
                */

                if (j != 0)
                {
                    /*
                    Jump using LPS.

                    This avoids rechecking characters.
                    */
                    j = lps[j - 1];
                }
                else
                {
                    /*
                    Nothing matched yet.

                    Simply move text pointer.
                    */
                    i++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    // Text where we want to search
    string text = "ABABABCABABC";

    // Pattern to search
    string pattern = "ABABC";

    // Perform KMP Search
    vector<int> ans = obj.KMP(text, pattern);

    cout << "Text    : " << text << endl;
    cout << "Pattern : " << pattern << endl;

    cout << "\nPattern Found At Index : ";

    if (ans.empty())
    {
        cout << "Not Found";
    }
    else
    {
        for (int index : ans)
            cout << index << " ";
    }

    cout << endl;

    return 0;
}