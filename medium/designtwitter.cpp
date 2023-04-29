class Twitter
{
private:
public:
    struct cmp
    {
        bool operator()(pair<int, int> f, pair<int, int> s) { return f.second < s.second; }
    };
    set<pair<int, int>> following;
    // sort by latest
    deque<pair<int, int>> pq;
    Twitter() {}

    // creates a tweet for a user, and asigns it with a tweet id
    void postTweet(int userId, int tweetId)
    {
        pq.push_back({tweetId, userId});
    }

    // show top 10 tweetids (followed) => use priority queue
    vector<int> getNewsFeed(int userId)
    {

        vector<int> res;

        deque<pair<int, int>> cq = pq;
        int k = 0;
        while (k < 10)
        {
            if (cq.empty())
                break;

            pair<int, int> temp = cq.back();
            cq.pop_back();

            // follower->followee
            if (following.find({userId, temp.second}) != following.end() || temp.second == userId)
            {
                res.push_back(temp.first);
                k++;
            }
        }
        return res;
    }

    // care about
    void follow(int followerId, int followeeId)
    {
        following.insert({followerId, followeeId});
    }

    // no long care about
    void unfollow(int followerId, int followeeId)
    {
        following.erase({followerId, followeeId});
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);