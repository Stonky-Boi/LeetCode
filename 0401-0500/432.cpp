class AllOne {
private:
    struct bucket{
        int freq;
        unordered_set<string> keys;
        bucket *prev,*next;
        bucket(int freq):freq(freq),prev(nullptr),next(nullptr){}
    };
    bucket *head,*tail;
    unordered_map<string,bucket*> location;
    void insertBefore(bucket* node,bucket* new_node){
        new_node->prev=node->prev;
        new_node->next=node;
        node->prev->next=new_node;
        node->prev=new_node;
    }
    void insertAfter(bucket* node,bucket* new_node){
        new_node->next=node->next;
        new_node->prev=node;
        node->next->prev=new_node;
        node->next=new_node;
    }
    void remove(bucket* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        delete node;
    }
public:
    AllOne() {
        head=new bucket(0);
        tail=new bucket(0);
        head->next=tail;
        tail->prev=head;
    }
    
    void inc(string key) {
        if(!location.count(key)){
            bucket* first=head->next;
            if(first!=tail &&first->freq==1){
                first->keys.insert(key);
                location[key]=first;
            }
            else{
                bucket* new_bucket=new bucket(1);
                new_bucket->keys.insert(key);
                insertAfter(head,new_bucket);
                location[key]=new_bucket;
            }
            return;
        }
        bucket* curr=location[key];
        bucket* next_bucket=curr->next;
        if(next_bucket!=tail &&next_bucket->freq==curr->freq+1){
            next_bucket->keys.insert(key);
            location[key]=next_bucket;
        }
        else{
            bucket* new_bucket=new bucket(curr->freq+1);
            new_bucket->keys.insert(key);
            insertAfter(curr,new_bucket);
            location[key]=new_bucket;
        }
        curr->keys.erase(key);
        if(curr->keys.empty())remove(curr);
    }
    
    void dec(string key) {
        bucket* curr=location[key];
        if(curr->freq==1){
            location.erase(key);
            curr->keys.erase(key);
            if(curr->keys.empty())remove(curr);
            return;
        }
        bucket* prev_bucket=curr->prev;
        if(prev_bucket!=head &&prev_bucket->freq==curr->freq-1){
            prev_bucket->keys.insert(key);
            location[key]=prev_bucket;
        }
        else{
            bucket* new_bucket=new bucket(curr->freq-1);
            new_bucket->keys.insert(key);
            insertBefore(curr,new_bucket);
            location[key]=new_bucket;
        }
        curr->keys.erase(key);
        if(curr->keys.empty())remove(curr);
    }
    
    string getMaxKey() {
        if(tail->prev==head)return "";
        return *tail->prev->keys.begin();
    }
    
    string getMinKey() {
        if(head->next==tail)return "";
        return *head->next->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */