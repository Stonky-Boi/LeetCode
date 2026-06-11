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
    ListNode* removeNodes(ListNode* head) {
        head=reverseList(head);
        int max_seen=head->val;
        ListNode* curr=head;
        while(curr->next){
            if(curr->next->val<max_seen)curr->next=curr->next->next;
            else{
                curr=curr->next;
                max_seen=max(max_seen,curr->val);
            }
        }
        return reverseList(head);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
};