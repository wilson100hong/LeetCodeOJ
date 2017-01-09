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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *s = head, *t = head;
        while (1) {
            s = s->next;
            t = t->next;
            if (t != nullptr) {
                t = t->next;
            }
            if (t == nullptr) return nullptr;
            if (s == t) break;
        }

        s = head;
        while (s != t) {
            s = s->next;
            t = t->next;
        }
        return s;
    }
};
