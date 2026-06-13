class Skiplist {
private:
    static const int MAX_LEVEL=16;
    struct node{
        int value,level;
        node* forward[MAX_LEVEL];
        node(int v,int l):value(v),level(l){
            for(int i=0;i<MAX_LEVEL;i++)forward[i]=nullptr;
        }
    };
    node* head;
    int curr_level;
    int random_level(){
        int level=1;
        while((rand()&1)&&level<MAX_LEVEL)level++;
        return level;
    }
public:
    Skiplist() {
        head=new node(-1,MAX_LEVEL);
        curr_level=1;
    }
    
    bool search(int target) {
        node* curr=head;
        for(int i=curr_level-1;i>=0;i--){
            while(curr->forward[i] &&curr->forward[i]->value<target)curr=curr->forward[i];
        }
        curr=curr->forward[0];
        return curr&&curr->value==target;
    }
    
    void add(int num) {
        node* update[MAX_LEVEL];
        node* curr=head;
        for(int i=curr_level-1;i>=0;i--){
            while(curr->forward[i] &&curr->forward[i]->value<num)curr=curr->forward[i];
            update[i]=curr;
        }
        int node_level=random_level();
        if(node_level>curr_level){
            for(int i=curr_level;i<node_level;i++)update[i]=head;
            curr_level=node_level;
        }
        node* new_node=new node(num,node_level);
        for(int i=0;i<node_level;i++){
            new_node->forward[i]=update[i]->forward[i];
            update[i]->forward[i]=new_node;
        }
    }
    
    bool erase(int num) {
        node* update[MAX_LEVEL];
        node* curr=head;
        for(int i=curr_level-1;i>=0;i--){
            while(curr->forward[i] &&curr->forward[i]->value<num)curr=curr->forward[i];
            update[i]=curr;
        }
        curr=curr->forward[0];
        if(!curr ||curr->value!=num)return false;
        for(int i=0;i<curr_level;i++){
            if(update[i]->forward[i]!=curr)break;
            update[i]->forward[i]=curr->forward[i];
        }
        delete curr;
        while(curr_level>1 && !head->forward[curr_level-1])curr_level--;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */