/**
 * Definition for singly-linked list.
 * struct listnode {
 *     int val;
 *     listnode *next;
 *     listnode(int x) : val(x), next(null) {}
 * };
 */
#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        tail->next = head;

        k %= n;
        ListNode* node = head;
        while (k < n-1) {
            node = node->next;
            k++;
        }
    
        head = node->next;
        node->next = nullptr;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    Solution sol;
    ListNode* res = sol.rotateRight(head, 0);
    cout << res->val << endl;
    
}
