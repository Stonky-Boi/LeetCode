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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> n(nums.begin(),nums.end());
        ListNode* temp=new ListNode(0,head);
        ListNode* curr=temp;
        while(curr->next){
            if(n.count(curr->next->val))curr->next=curr->next->next;
            else curr=curr->next;
        }
        return temp->next;
    }
};