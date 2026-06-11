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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev_tail=dummy;
        ListNode* curr=head;
        int size=1;
        while(curr){
            int group_size=0;
            ListNode* temp=curr;
            while(temp &&group_size<size){
                group_size++;
                temp=temp->next;
            }
            ListNode* tail=curr;
            for(int i=1;i<group_size;i++)tail=tail->next;
            if(group_size%2==0){
                tail->next=nullptr;
                ListNode* reverse_head=reverseList(curr);
                prev_tail->next=reverse_head;
                curr->next=temp;
                prev_tail=curr;
            }
            else prev_tail=tail;
            curr=temp;
            size++;
        }
        return dummy->next;
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