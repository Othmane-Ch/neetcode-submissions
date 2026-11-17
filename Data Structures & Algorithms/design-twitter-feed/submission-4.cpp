class Twitter {
private:
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweets {}; // user_id : (list of (timestamp, tweet_ids)  
    unordered_map<int, unordered_set<int>> followers {}; // user_id : set of followers to have o(1) follow and unfollow
public:
    Twitter() = default;
    
    //  Time : O(1)
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(time, tweetId));
        ++time;
    }
    
    // Time : O(F * log(F)) f numbers of tweets of the followers of userId ( tweet for each follower in the heap)
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> max_pq {}; // time, tweetId, userId, index at tweets list

        auto push_latest = [&] (int user_id)
        {
            auto it = tweets.find(user_id);
            if(it != tweets.end())
            {
                int i = it->second.size() - 1;
                max_pq.push(make_tuple(it->second[i].first, it->second[i].second, user_id, i));
            }
        };
        push_latest(userId);
        for(const auto& f : followers[userId])
        {
            push_latest(f);
        }
        vector<int> result {};
        while(!max_pq.empty())
        {
            auto [ts, tweet, user, i] = max_pq.top(); max_pq.pop();
            result.push_back(tweet);
            if(i > 0) max_pq.push(make_tuple(tweets[user][i - 1].first, tweets[user][i - 1].second, user, i - 1)); 
            if(result.size() == 10) break;
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
