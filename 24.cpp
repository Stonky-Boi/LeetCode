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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=new ListNode(0,head);
        ListNode* curr=temp;
        while(curr->next &&curr->next->next){
            ListNode *node1=curr->next,*node2=curr->next->next;
            node1->next=node2->next;
            node2->next=node1;
            curr->next=node2;
            curr=node1;
        }
        return temp->next;
    }
};