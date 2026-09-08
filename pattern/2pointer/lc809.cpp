#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // Checks whether one word can be stretched to become s
    bool isStretchy(string s, string word) {

        int i = 0;  // Pointer for s
        int j = 0;  // Pointer for word

        int n = s.size();
        int m = word.size();

        // Process both strings group by group
        while (i < n && j < m) {

            // If the current characters are different,
            // the word can never become s.
            if (s[i] != word[j]) {
                return false;
            }

            // -------------------------------------------------
            // Find the size of the current group in s
            // -------------------------------------------------

            int iStart = i;

            // Move i while characters are the same
            while (i < n && s[i] == s[iStart]) {
                i++;
            }

            // Length of this group in s
            int sCount = i - iStart;


            // -------------------------------------------------
            // Find the size of the current group in word
            // -------------------------------------------------

            int jStart = j;

            // Move j while characters are the same
            while (j < m && word[j] == word[jStart]) {
                j++;
            }

            // Length of this group in word
            int wordCount = j - jStart;


            // -------------------------------------------------
            // Check whether the two groups are compatible
            // -------------------------------------------------

            if (sCount < wordCount) {

                // s has fewer characters than word.
                // We cannot remove characters from word,
                // so this is impossible.
                return false;
            }

            if (sCount != wordCount && sCount < 3) {

                // The group in s is smaller than 3.
                // Therefore, it cannot be created by stretching.
                //
                // Example:
                // s = "hello"
                // word = "heello"
                //
                // "ll" in s has length 2, but "ll" in word
                // has length 2 here okay.
                //
                // But if word had a larger group than s,
                // we could not shrink it.
                return false;
            }

            // If sCount == wordCount:
            //     Perfect match.
            //
            // If sCount > wordCount AND sCount >= 3:
            //     We can stretch the smaller group in word.
        }

        // Both strings must be completely processed.
        //
        // If one still has characters left, their group
        // structure does not match.
        return i == n && j == m;
    }


    int expressiveWords(string s, vector<string>& words) {

        int answer = 0;

        // Check every query word
        for (string& word : words) {

            if (isStretchy(s, word)) {
                answer++;
            }
        }

        return answer;
    }
};


int main() {

    Solution solution;

    string s = "heeellooo";

    vector<string> words = {
        "hello",
        "hi",
        "helo"
    };

    int answer = solution.expressiveWords(s, words);

    cout << "Number of stretchy words: " << answer << endl;

    return 0;
}