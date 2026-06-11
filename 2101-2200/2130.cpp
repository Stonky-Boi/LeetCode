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
    int pairSum(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast &&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* second=reverseList(slow);
        int sum=0;
        while(second){
            sum=max(sum,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return sum;
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