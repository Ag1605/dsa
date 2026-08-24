#include <bits/stdc++.h>
using namespace std;

/*
    Problem: H-Index

    Given an array citations[], where citations[i] represents
    the number of citations received by the i-th paper.

    We need to find the maximum value h such that:

        At least h papers have at least h citations each.

    Example:

        citations = [3, 0, 6, 1, 5]

        After sorting:
        [0, 1, 3, 5, 6]

        There are:
        - 5 papers with >= 0 citations
        - 4 papers with >= 1 citation
        - 3 papers with >= 3 citations
        - 2 papers with >= 5 citations

        H-index = 3
*/


class Solution {
public:

    int hIndex(vector<int>& citations) {

        // ---------------------------------------------------------
        // STEP 1: Sort the citations array.
        //
        // Example:
        //
        // [3, 0, 6, 1, 5]
        //
        // becomes:
        //
        // [0, 1, 3, 5, 6]
        //
        // Sorting allows us to use Binary Search.
        // ---------------------------------------------------------
        sort(citations.begin(), citations.end());


        // Number of papers.
        int n = citations.size();


        // ---------------------------------------------------------
        // We will perform Binary Search.
        //
        // left  = starting index
        // right = ending index
        //
        // We are searching for the FIRST position where:
        //
        // citations[mid] >= number of papers from mid to end
        //
        // ---------------------------------------------------------
        int left = 0;
        int right = n - 1;


        // Continue Binary Search while the search range is valid.
        while (left <= right) {

            // Calculate middle index safely.
            int mid = left + (right - left) / 2;


            // -----------------------------------------------------
            // Number of papers from index mid to the last index.
            //
            // If:
            //
            // n = 5
            // mid = 2
            //
            // indices:
            //
            // 0  1  2  3  4
            //       ↑
            //      mid
            //
            // Papers from mid to end:
            //
            // 2, 3, 4
            //
            // Total = 3
            //
            // Therefore:
            //
            // h = n - mid
            // -----------------------------------------------------
            int h = n - mid;


            // -----------------------------------------------------
            // Check whether citations[mid] is enough.
            //
            // If citations[mid] >= h:
            //
            // Then there are h papers having at least h citations.
            //
            // Therefore, h is a VALID H-index candidate.
            // -----------------------------------------------------
            if (citations[mid] >= h) {

                // -------------------------------------------------
                // We found a valid h.
                //
                // But maybe an even larger h is possible.
                //
                // To increase h, we need to move toward the LEFT.
                //
                // Therefore, search:
                //
                // [left ... mid-1]
                // -------------------------------------------------
                right = mid - 1;

            }
            else {

                // -------------------------------------------------
                // citations[mid] < h
                //
                // This means there are not enough citations
                // to achieve this h.
                //
                // We need a smaller h.
                //
                // Moving toward the RIGHT decreases:
                //
                // h = n - mid
                //
                // Therefore:
                //
                // left = mid + 1
                // -------------------------------------------------
                left = mid + 1;
            }
        }


        // ---------------------------------------------------------
        // When Binary Search finishes:
        //
        // 'left' is the first index where:
        //
        // citations[left] >= n - left
        //
        // Therefore the H-index is:
        //
        // n - left
        //
        // ---------------------------------------------------------
        return n - left;
    }
};


int main() {

    // Example input.
    vector<int> citations = {3, 0, 6, 1, 5};


    // Create Solution object.
    Solution obj;


    // Call hIndex() and store the answer.
    int answer = obj.hIndex(citations);


    // Print the H-index.
    cout << "H-Index = " << answer << endl;


    return 0;
}