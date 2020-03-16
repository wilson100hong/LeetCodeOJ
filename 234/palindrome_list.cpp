#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true; 
        int n = 0;
        ListNode* node = head;
        while (node != nullptr) {
            n++;
            node = node->next;
        }
        
        if (n == 1) return true;
        
        n = (n+1) / 2;
        ListNode* right = head;
        while (n--) {
            right = right->next;
        }
        
        // reverse right to end
        ListNode* prev = nullptr;
        while (right->next != nullptr) {
            ListNode* temp = right->next;
            right->next = prev;
            prev = right;
            right = temp;
        }
        right->next = prev;

        ListNode* left = head;
        while (right != nullptr) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode* MakeList(vector<int>& input) {
      if (input.size() == 0) return nullptr;
      ListNode* head = new ListNode(input[0]);
      ListNode* cur = head;
      for (int i=1;i<input.size();++i) {
        ListNode* node = new ListNode(input[i]);
        cur->next = node;
        cur = node;
      }
      return head;
    }

};

int main() {
  vector<int> input = {1, 2, 2, 1};
  Solution sol;
  ListNode* head = sol.MakeList(input);
  cout << sol.isPalindrome(head) << endl;
}
