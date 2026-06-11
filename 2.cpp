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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* curr=temp;
        int sum=0,carry=0;
        while(l1 ||l2 ||carry!=0){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            sum=val1+val2+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return temp->next;
    }
};