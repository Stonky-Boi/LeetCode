class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node(int value):val(value),next(nullptr){}
    };
    Node* temp;
    int length;
public:
    MyLinkedList() {
        temp=new Node(0);
        length=0;
    }
    
    int get(int index) {
        if(index>=length)return -1;
        Node* curr=temp->next;
        for(int i=0;i<index;i++)curr=curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(length,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>length)return;
        Node* prev=temp;
        for(int i=0;i<index;i++)prev=prev->next;
        Node* node=new Node(val);
        node->next=prev->next;
        prev->next=node;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=length)return;
        Node* prev=temp;
        for(int i=0;i<index;i++)prev=prev->next;
        Node* node=prev->next;
        prev->next=node->next;
        delete node;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */