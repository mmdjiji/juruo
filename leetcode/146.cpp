// 思路：哈希表+双向链表
class Node {
public:
  Node *prev;
  Node *next;
  int key;
  int value;
  Node(int key = 0, int value = 0) {
    this->key = key;
    this->value = value;
    prev = nullptr;
    next = nullptr;
  }
};

class LRUCache {
public:
  LRUCache(int capacity) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    cnt = 0;                   // counter of capacity
    this->capacity = capacity; // mem capacity
  }

  int get(int key) {
    if (map[key] != nullptr) {
      Node *cur = map[key];
      rm(cur);
      addTail(cur);
      return cur->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (map[key] != nullptr) {
      Node *cur = map[key];
      cur->value = value;
      rm(cur);
      addTail(cur);
    } else {
      if (cnt >= capacity) {
        Node *del = head->next;
        rm(del);
        map.erase(del->key);
        --cnt;
      }
      Node *ins = new Node(key, value);
      addTail(ins);
      map[key] = ins;
      ++cnt;
    }
  }

private:
  unordered_map<int, Node *> map;
  Node *head, *tail;
  int cnt, capacity;

  void rm(Node *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }

  void addTail(Node *n) {
    Node *tp = tail->prev;
    tp->next = n;
    n->prev = tp;
    n->next = tail;
    tail->prev = n;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */