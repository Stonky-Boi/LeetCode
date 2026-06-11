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
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head=head;
    }
    
    int getRandom() {
        int answer=head->val;
        ListNode* curr=head;
        int count=1;
        while(curr){
            if(rand()%count==0)answer=curr->val;
            curr=curr->next;
            count++;
        }
        return answer;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */