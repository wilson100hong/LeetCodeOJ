// Resouvior Sampling
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cursor = head_;
        int k = 1;
        int ans;
        while (cursor != nullptr) {
            // get probability of 1/k
            if (rand() % k == 0) {
                ans = cursor->val;
            }
            k++;
            cursor = cursor->next;
        }
        return ans;
    }
private:
    ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
