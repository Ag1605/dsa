#include <iostream>
#include <string>
using namespace std;


int possibleStringCount(string word) {

    // There is ALWAYS at least one possible
    // original string:
    //
    // The original string could simply be
    // the final string itself.
    int ans = 1;


    // Start from index 1 because we compare
    // word[i] with the previous character
    // word[i - 1].
    for (int i = 1; i < word.size(); i++) {

        // If current character is the same
        // as the previous character,
        // then this character might be
        // an accidental extra character.
        if (word[i] == word[i - 1]) {

            // One additional possible
            // original string is created.
            ans++;
        }
    }


    return ans;
}


int main() {

    string word = "abbcccc";

    int result = possibleStringCount(word);

    cout << result << endl;

    return 0;
}