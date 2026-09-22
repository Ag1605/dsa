#include <iostream>
#include <numeric>   // for std::lcm

using namespace std;

class Solution {
public:

    // Function to find which receptor receives the laser
    int mirrorReflection(int p, int q) {

        // ---------------------------------------------------------
        // STEP 1: Find LCM of p and q
        //
        // We are looking for the first point where:
        // - the laser's vertical movement reaches a corner
        // - the room's horizontal reflections also line up
        //
        // LCM gives us the smallest distance that is a multiple
        // of both p and q.
        // ---------------------------------------------------------
        int l = lcm(p, q);

        // ---------------------------------------------------------
        // STEP 2: How many times does the room height (p)
        // fit inside L?
        //
        // Example:
        // p = 3
        // L = 12
        //
        // 12 / 3 = 4
        //
        // x tells us how many vertical room-lengths we travelled.
        // ---------------------------------------------------------
        int x = l / p;

        // ---------------------------------------------------------
        // STEP 3: How many times does q fit inside L?
        //
        // Example:
        // q = 4
        // L = 12
        //
        // 12 / 4 = 3
        //
        // y tells us how many q-length movements happened.
        // ---------------------------------------------------------
        int y = l / q;

        // ---------------------------------------------------------
        // STEP 4: Check x
        //
        // If x is EVEN, the laser reaches receptor 0.
        //
        // Why?
        // Every reflection flips the direction.
        // After an even number of room-height sections,
        // the laser ends up at the bottom side.
        // ---------------------------------------------------------
        if (x % 2 == 0)
            return 0;

        // ---------------------------------------------------------
        // STEP 5: Check y
        //
        // If x is odd but y is EVEN,
        // the laser reaches receptor 2.
        //
        // This corresponds to the laser reaching the upper-left
        // receptor after the required reflections.
        // ---------------------------------------------------------
        if (y % 2 == 0)
            return 2;

        // ---------------------------------------------------------
        // STEP 6:
        //
        // If BOTH x and y are odd,
        // the laser reaches receptor 1.
        // ---------------------------------------------------------
        return 1;
    }
};


int main() {

    // Create an object of Solution
    Solution sol;

    // ---------------------------------------------------------
    // Example 1
    //
    // p = 2
    // q = 1
    //
    // This is the example from the problem.
    // ---------------------------------------------------------
    int p = 2;
    int q = 1;

    int answer = sol.mirrorReflection(p, q);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "Receptor = " << answer << endl;

    return 0;
}