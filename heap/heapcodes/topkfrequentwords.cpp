#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------
// Custom Comparator
//------------------------------------------------------------
//
// Heap stores:
// {frequency, word}
//
// We are using a Min Heap.
//
// The element at the top should be the "least useful"
// among the current k elements.
//
// Priority Rules:
//
// 1. Smaller frequency → Higher priority (comes at top)
// 2. If frequency is same,
//    lexicographically larger word → Higher priority
//
// Why larger word?
// Because if heap size becomes greater than k,
// we remove the top element.
// We want to remove the lexicographically larger word first,
// since the question prefers smaller alphabetical words.
//------------------------------------------------------------
class Compare
{
public:
    bool operator()(pair<int, string> &a, pair<int, string> &b)
    {

        // If frequencies are same
        if (a.first == b.first)
        {

            // Alphabetically smaller word should stay.
            // Therefore larger word gets higher priority
            // and comes to the top.
            return a.second < b.second;
        }

        // Smaller frequency gets higher priority.
        return a.first > b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        //----------------------------------------------------
        // Step 1 : Count frequency of every word
        //----------------------------------------------------

        unordered_map<string, int> mp;

        for (string word : words)
        {
            mp[word]++;
        }

        //----------------------------------------------------
        // Step 2 : Create Min Heap
        //
        // pair.first  -> Frequency
        // pair.second -> Word
        //----------------------------------------------------

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Compare>
            pq;

        //----------------------------------------------------
        // Step 3 : Traverse frequency map
        //----------------------------------------------------

        for (auto it : mp)
        {

            // Insert current word and its frequency
            pq.push({it.second, it.first});

            // Heap should contain only k elements
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        //----------------------------------------------------
        // Step 4 : Extract answer
        //----------------------------------------------------

        vector<string> ans;

        while (!pq.empty())
        {

            // Store word only
            ans.push_back(pq.top().second);

            pq.pop();
        }

        //----------------------------------------------------
        // Heap gives lowest priority first.
        // Reverse to get highest frequency first.
        //----------------------------------------------------

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<string> words = {
        "i",
        "love",
        "leetcode",
        "i",
        "love",
        "coding"};

    int k = 2;

    vector<string> ans = obj.topKFrequent(words, k);

    cout << "Top " << k << " Frequent Words : ";

    for (string word : ans)
    {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}