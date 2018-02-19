class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr, *cur=nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int n1 = (l1 == nullptr ? 0 : l1->val);
            int n2 = (l2 == nullptr ? 0 : l2->val);
            
            int n3 = n1 + n2 + carry;
            carry = n3 / 10;
            
            ListNode* created = new ListNode(n3 % 10);
            
            if (cur == nullptr) {
                ans = created;
            } else {
                cur->next = created;
            }
            cur = created;
            
            if (l1 !=nullptr) l1 = l1->next;
            if (l2 !=nullptr) l2 = l2->next;
        }
        
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return ans;
    }
};
