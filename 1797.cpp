class AuthenticationManager {
private:
    int ttl;
    unordered_map<string,int> map;
public:
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(map.count(tokenId) &&map[tokenId]>currentTime)map[tokenId]=currentTime+ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        vector<string> to_delete;
        for(auto& [token,time]:map){
            if(time<=currentTime)to_delete.push_back(token);
            else count++;
        }
        for(string& key:to_delete)map.erase(key);
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */