/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        while(curr){
            if(!curr->child){
                curr=curr->next;
                continue;
            }
            Node* child_head=curr->child;
            Node* child_tail=child_head;
            while(child_tail->next)child_tail=child_tail->next;
            if(curr->next){
                child_tail->next=curr->next;
                curr->next->prev=child_tail;
            }
            curr->next=child_head;
            child_head->prev=curr;
            curr->child=nullptr;
            curr=curr->next;
        }
        return head;
    }
};