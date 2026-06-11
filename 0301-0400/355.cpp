class Twitter {
private:
    int curr_time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> follows;
    struct tweet{
        int timestamp;
        int id;
        int index;
        int user;

        tweet(int t,int id,int i,int u):timestamp(t),id(id),index(i),user(u){};
    };
    struct compare{
        bool operator()(const tweet& a,const tweet& b)const{
            return a.timestamp<b.timestamp;
        }
    };
public:
    Twitter() {
        curr_time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({curr_time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tweet,vector<tweet>,compare> pq;
        vector<pair<int,int>>& self=tweets[userId];
        if(!self.empty())pq.push(tweet(self.back().first,self.back().second,(int)self.size()-1,userId));
        for(int f:follows[userId]){
            vector<pair<int,int>>& t=tweets[f];
            if(!t.empty())pq.push(tweet(t.back().first,t.back().second,(int)t.size()-1,f));
        }
        vector<int> feed;
        while(!pq.empty() &&feed.size()<10){
            tweet curr=pq.top();
            pq.pop();
            feed.push_back(curr.id);
            if(curr.index>0){
                int prev_index=curr.index-1;
                pair<int,int>& prev_tweet=tweets[curr.user][prev_index];
                pq.push(tweet(prev_tweet.first,prev_tweet.second,prev_index,curr.user));
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */