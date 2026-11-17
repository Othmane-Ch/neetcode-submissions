class Twitter {
private:
    unordered_map<int, unordered_set<int>> tweets {}; // user_id : (list of tweet_ids) that are unique 
    unordered_map<int, unordered_set<int>> followers {}; // user_id : set of followers to have o(1) follow and unfollow
    vector<pair<int,int>> newsFeed {}; // tweetId, UserId
public:
    Twitter() = default;
    
    //  Time : O(1)
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(tweetId);
        newsFeed.push_back(make_pair(tweetId, userId));
    }
    
    // Time  : O(n)
    vector<int> getNewsFeed(int userId) {
        vector<int> result {};
        int k = 0;
        for(auto it = newsFeed.rbegin(); it != newsFeed.rend(); ++it)
        {
            auto& [tweet, user] = *it;
            if(user == userId || followers[userId].contains(user))
            {
                ++k;
                result.push_back(tweet);
            }
            if(k == 10) break;
        }
        return result;
    }

    //  Time : O(1)
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    //  Time : O(1)
    void unfollow(int followerId, int followeeId) {
        auto it = followers.find(followerId);
        if(it != followers.end())
        {
            if (it->second.contains(followeeId)) it->second.erase(followeeId);
        }
    }
};
