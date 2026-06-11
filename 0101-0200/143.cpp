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
    void reorderList(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next &&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverseList(slow->next);
        slow->next=nullptr;
        ListNode* first=head;
        while(second){
            ListNode *temp1=first->next,*temp2=second->next;
            second->next=first->next;
            first->next=second;
            first=temp1;
            second=temp2;
        }
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