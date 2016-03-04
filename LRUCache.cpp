// 1. MoveToHead should not free any node
#include <iostream>
#include <unordered_map>
using namespace std;
struct LinkedNode {
  LinkedNode* prev;
  LinkedNode* next;
  int value;
  int key;
};

class LinkedList {
  public:
  void RemoveTail() {
    if (!tail) return;

    LinkedNode* node = tail;
    if (head == node) {
      head = nullptr;
    }
    tail = tail->prev;
    if (tail) {
      tail->next = nullptr;
    }
    free(node);
  }

  void AddHead(int key, int value) {
    LinkedNode* node = new LinkedNode();
    node->key = key;
    node->value = value;
    AddHead(node);
  }

  void AddHead(LinkedNode* node) {
    node->prev = nullptr;
    if (head) {
      node->next = head;
      head->prev = node;
    } else {
      node->next = nullptr;
    }
    if (!tail) {
      tail = node;
    }
    head = node;
  }

  void MoveToHead(LinkedNode* node) {
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    } else {
      head = node->next;
    }

    if (node->next != nullptr) {
      node->next->prev = node->prev;
    } else {
      tail = node->prev;
    }

    AddHead(node);
  }

  LinkedNode* head = nullptr;
  LinkedNode* tail = nullptr;
};

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
        used = 0;
    }

    int get(int key) {
        if (hash_map.count(key) == 0) return -1;
        LinkedNode* node = hash_map[key];
        list.MoveToHead(node);
        return node->value;
    }

    void set(int key, int value) {
        if (hash_map.count(key) != 0) {
            LinkedNode* node = hash_map[key];
            list.MoveToHead(node);
            node->value = value;
        } else {
            if (used == cap) {
                int rk = list.tail->key;
                //cout << "rk: " << rk << endl;
                hash_map.erase(rk);
                list.RemoveTail();
                used--;
            }
            list.AddHead(key, value);
            hash_map[key] = list.head;
            used++;
        }
    }

    LinkedList list;
    unordered_map<int, LinkedNode*> hash_map;
    int used;
    int cap;
};

int main() {
  LRUCache ch(2);
  ch.set(2, 1);
  ch.set(3, 2);
  cout << ch.get(3) << endl;
  cout << ch.get(2) << endl;
  ch.set(4, 3);
  cout << ch.get(2) << endl;
  cout << ch.get(3) << endl;
  cout << ch.get(4) << endl;
}
