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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=new ListNode(0,head);
        ListNode* prev=temp;
        ListNode* curr=head;
        while(curr){
            ListNode* tail=curr;
            for(int i=1;i<k&&tail;i++)tail=tail->next;
            if(!tail)break;
            ListNode* next_group=tail->next;
            tail->next=nullptr;
            ListNode* reverse_head=reverseList(curr);
            prev->next=reverse_head;
            curr->next=next_group;
            prev=curr;
            curr=next_group;
        }
        return temp->next;
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