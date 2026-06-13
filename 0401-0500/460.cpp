class LFUCache {
private:
    struct node{
        int value,freq;
        list<int>::iterator position;
        node():value(0),freq(0){}
        node(int v,int f,list<int>::iterator p):value(v),freq(f),position(p){}
    };
    int cap;
    int min_freq;
    unordered_map<int,node> nodes;
    unordered_map<int,list<int>> freq_list;
    void touch(int key){
        int f=nodes[key].freq;
        freq_list[f].erase(nodes[key].position);
        if(freq_list[f].empty()){
            freq_list.erase(f);
            if(min_freq==f)min_freq++;
        }
        f++;
        freq_list[f].push_front(key);
        nodes[key].freq=f;
        nodes[key].position=freq_list[f].begin();
    }
public:
    LFUCache(int capacity) {
        cap=capacity;
        min_freq=0;
    }
    
    int get(int key) {
        if(!nodes.count(key))return -1;
        touch(key);
        return nodes[key].value;
    }
    
    void put(int key, int value) {
        if(nodes.count(key)){
            nodes[key].value=value;
            touch(key);
            return;
        }
        if(nodes.size()==cap){
            int evict=freq_list[min_freq].back();
            freq_list[min_freq].pop_back();
            if(freq_list[min_freq].empty())freq_list.erase(min_freq);
            nodes.erase(evict);
        }
        freq_list[1].push_front(key);
        nodes.emplace(key,node(value,1,freq_list[1].begin()));
        min_freq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */