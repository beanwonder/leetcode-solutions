#include <cstring>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

class LRUCache{
private:
  struct node {
    node* prev;
    int key;
    int val;
    node* next;
    node (int k=-1, int v=-1) : prev(NULL), key(k), val(v), next(NULL) {};
  };

  int capacity;
  map<int, node*> keymap;
  // fake nodes
  node head;
  node tail;
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head.next = &tail;
    tail.prev = &head;
  }

  int get(int key) {
    auto it = keymap.find(key);
    if (it != keymap.end()) {
      node* nptr = (*it).second;
      remove_from_list(nptr);
      insert_node_before(&tail, nptr);
      return nptr->val;
    } else
      return -1;
  }

  void set(int key, int value) {
    if (get(key) != -1) {
        (tail.prev)->val = value;
    } else {
      if (keymap.size() < capacity) {
        node *nptr = new node(key, value);
        insert_node_before(&tail, nptr);
        keymap[key] = nptr;
      } else {
        node *nptr = head.next;
        int old_key = nptr->key;
        // update key
        remove_from_list(nptr);
        insert_node_before(&tail, nptr);
        nptr->key = key;
        nptr->val = value;
        keymap.erase(old_key);
        keymap[key] = nptr;
      }
    }
  }

  ~LRUCache() {
    node *cur = head.next;
    while (cur != &tail) {
        node *tmp = cur->next;
        delete cur;
        cur = tmp;
    }
  }

  void insert_node_after(node* this_ptr, node* node_ptr) {
    node_ptr->next = this_ptr->next;
    node_ptr->prev = this_ptr;
    this_ptr->next->prev = node_ptr;
    this_ptr->next = node_ptr;
  }

  void insert_node_before(node* this_ptr, node* node_ptr) {
    node_ptr->prev = this_ptr->prev;
    node_ptr->next = this_ptr;
    this_ptr->prev->next = node_ptr;
    this_ptr->prev = node_ptr;
  }

  void remove_from_list(node* node_ptr) {
    node_ptr->prev->next = node_ptr->next;
    node_ptr->next->prev = node_ptr->prev;
  }

};
