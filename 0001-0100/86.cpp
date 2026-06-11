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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less_head=new ListNode(0),*more_head=new ListNode(0);
        ListNode *less=less_head,*more=more_head;
        while(head){
            if(head->val<x){
                less->next=head;
                less=less->next;
            }
            else{
                more->next=head;
                more=more->next;
            }
            head=head->next;
        }
        less->next=more_head->next;
        more->next=nullptr;
        return less_head->next;
    }
};