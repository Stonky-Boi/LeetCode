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
    ListNode* sortList(ListNode* head) {
        if(!head ||!head->next)return head;
        ListNode* m=mid(head);
        ListNode *l=head,*r=m->next;
        m->next=nullptr;
        l=sortList(l);
        r=sortList(r);
        return merge(l,r);
    }
    ListNode* mid(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(fast->next &&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* temp=new ListNode(0);
        ListNode* tail=temp;
        while(l1 && l2){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next=l1?l1:l2;
        return temp->next;
    }
};