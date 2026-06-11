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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=0;
        ListNode* curr=head;
        while(curr){
            length++;
            curr=curr->next;
        }
        int base=length/k;
        int extra=length%k;
        vector<ListNode*> answer(k);
        curr=head;
        for(int i=0;i<k;i++){
            answer[i]=curr;
            int size=base+(i<extra?1:0);
            for(int j=0;j<size-1;j++){
                if(curr)curr=curr->next;
            }
            if(curr){
                ListNode* next_part=curr->next;
                curr->next=nullptr;
                curr=next_part;
            }
        }
        return answer;
    }
};