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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *s = head, *t = head;
        while (1) {
            s = s->next;
            t = t->next;
            if (t != nullptr) t = t->next;
            if (t == nullptr) break;
            if (s == t) return true;
        }
        return false;
    }
};
