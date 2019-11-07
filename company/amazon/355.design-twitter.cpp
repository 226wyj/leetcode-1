class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() { time = 0; }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        follow(userId, userId);
        tweets[userId].push_back({ time++, tweetId });
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
     * in the news feed must be posted by users who the user followed or by the
     * user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>>
            q;
        for (auto id : friends[userId]) {
            for (auto a : tweets[id]) {
                if (q.size() > 0 && q.top().first > a.first && q.size() > 10)
                    break;
                q.push(a);
                if (q.size() > 10)
                    q.pop();
            }
        }
        while (!q.empty()) {
            // keep push into the head
            ret.insert(ret.begin(), q.top().second);
            q.pop();
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a
     * no-op. */
    void follow(int followerId, int followeeId)
    {
        friends[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be
     * a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            friends[followerId].erase(followeeId);
    }

private:
    int time;
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
