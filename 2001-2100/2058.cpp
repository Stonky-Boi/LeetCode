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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        int index=1;
        int first_critical=-1;
        int prev_critical=-1;
        int min_dist=INT_MAX;
        while(curr &&curr->next){
            bool maxima=curr->val>prev->val &&curr->val>curr->next->val;
            bool minima=curr->val<prev->val &&curr->val<curr->next->val;
            if(maxima||minima){
                if(first_critical==-1)first_critical=index;
                else min_dist=min(min_dist,index-prev_critical);
                prev_critical=index;
            }
            prev=curr;
            curr=curr->next;
            index++;
        }
        if(first_critical==-1||first_critical==prev_critical)return {-1,-1};
        int max_dist=prev_critical-first_critical;
        return {min_dist,max_dist};
    }
};