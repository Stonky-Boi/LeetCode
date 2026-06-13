/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(ListNode* left,ListNode* right){
            return left->val>right->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(ListNode* head:lists){
            if(head)pq.push(head);
        }
        ListNode* temp=new ListNode(0);
        ListNode* curr=temp;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            curr->next=node;
            curr=curr->next;
            if(node->next)pq.push(node->next);
        }
        return temp->next;
    }
};