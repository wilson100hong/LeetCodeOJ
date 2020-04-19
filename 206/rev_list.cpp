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
     //#1: recursively
     ListNode* reverseList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) return head;
         ListNode* node = reverseList(head->next);
         head->next->next = head;
         head->next= nullptr;
         return node;    
     }
       
    // #2: iteratively
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
