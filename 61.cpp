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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        ListNode* tail=head;
        int length=1;
        while(tail->next){
            tail=tail->next;
            length++;
        }
        tail->next=head;
        k%=length;
        int steps=length-k;
        ListNode* temp=tail;
        for(int i=0;i<steps;i++)temp=temp->next;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};