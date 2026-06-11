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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=new ListNode(0,head);
        unordered_map<int,ListNode*> map;
        int prefix=0;
        ListNode* curr=temp;
        while(curr){
            prefix+=curr->val;
            map[prefix]=curr;
            curr=curr->next;
        }
        prefix=0;
        curr=temp;
        while(curr){
            prefix+=curr->val;
            curr->next=map[prefix]->next;
            curr=curr->next;
        }
        return temp->next;
    }
};