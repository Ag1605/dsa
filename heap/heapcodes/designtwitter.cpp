#include <bits/stdc++.h>
using namespace std;

class Twitter
{

public:
    //---------------------------------------------------------
    // followMap
    //
    // Key   -> Follower ID
    // Value -> Set of people that the user follows
    //
    // Example:
    //
    // 1 -> {2,3}
    //
    // Means user 1 follows user 2 and user 3.
    //---------------------------------------------------------

    unordered_map<int, unordered_set<int>> followMap;

    //---------------------------------------------------------
    // tweets
    //
    // Key   -> User ID
    // Value -> Vector of {time, tweetId}
    //
    // Example
    //
    // 1 ->
    // { {0,101},
    //   {3,105},
    //   {7,110} }
    //---------------------------------------------------------

    unordered_map<int, vector<pair<int, int>>> tweets;

    //---------------------------------------------------------
    // Global timer
    //
    // Every tweet gets a unique increasing timestamp.
    //---------------------------------------------------------

    int timer;

    //---------------------------------------------------------
    // Constructor
    //---------------------------------------------------------

    Twitter()
    {

        timer = 0;
    }

    //---------------------------------------------------------
    // Post Tweet
    //---------------------------------------------------------

    void postTweet(int userId, int tweetId)
    {

        //-----------------------------------------------------
        // Store
        //
        // {current time, tweetId}
        //-----------------------------------------------------

        tweets[userId].push_back({timer, tweetId});

        //-----------------------------------------------------
        // Increase time
        //-----------------------------------------------------

        timer++;
    }

    //---------------------------------------------------------
    // Return latest 10 tweets
    //---------------------------------------------------------

    vector<int> getNewsFeed(int userId)
    {

        //-----------------------------------------------------
        // Stores final answer
        //-----------------------------------------------------

        vector<int> ans;

        //-----------------------------------------------------
        // Max Heap
        //
        // pair.first  -> time
        // pair.second -> tweetId
        //
        // Largest timestamp comes first.
        //-----------------------------------------------------

        priority_queue<pair<int, int>> pq;

        //-----------------------------------------------------
        // Push user's own tweets
        //-----------------------------------------------------

        for (auto tweet : tweets[userId])
        {

            pq.push(tweet);
        }

        //-----------------------------------------------------
        // Push tweets of everyone user follows
        //-----------------------------------------------------

        for (int followee : followMap[userId])
        {

            for (auto tweet : tweets[followee])
            {

                pq.push(tweet);
            }
        }

        //-----------------------------------------------------
        // Extract latest 10 tweets
        //-----------------------------------------------------

        while (!pq.empty() && ans.size() < 10)
        {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }

    //---------------------------------------------------------
    // Follow another user
    //---------------------------------------------------------

    void follow(int followerId, int followeeId)
    {

        followMap[followerId].insert(followeeId);
    }

    //---------------------------------------------------------
    // Unfollow
    //---------------------------------------------------------

    void unfollow(int followerId, int followeeId)
    {

        followMap[followerId].erase(followeeId);
    }
};

int main()
{

    Twitter twitter;

    //---------------------------------------------------------
    // User 1 posts tweets
    //---------------------------------------------------------

    twitter.postTweet(1, 101);

    twitter.postTweet(1, 102);

    //---------------------------------------------------------
    // User 2 posts tweets
    //---------------------------------------------------------

    twitter.postTweet(2, 201);

    twitter.postTweet(2, 202);

    //---------------------------------------------------------
    // User 1 follows User 2
    //---------------------------------------------------------

    twitter.follow(1, 2);

    //---------------------------------------------------------
    // Get News Feed of User 1
    //---------------------------------------------------------

    vector<int> feed = twitter.getNewsFeed(1);

    cout << "News Feed of User 1\n\n";

    for (int tweet : feed)
    {

        cout << tweet << " ";
    }

    cout << endl;

    //---------------------------------------------------------
    // User 1 unfollows User 2
    //---------------------------------------------------------

    twitter.unfollow(1, 2);

    cout << "\nAfter Unfollowing User 2\n\n";

    feed = twitter.getNewsFeed(1);

    for (int tweet : feed)
    {

        cout << tweet << " ";
    }

    cout << endl;

    return 0;
}