/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev, *cur, *tar;
    if (head == nullptr)
      return nullptr;
    cur = head;
    tar = head->next;
    cur->next = nullptr;
    prev = cur;

    while (tar != nullptr) {
      cur = tar;
      tar = cur->next;
      cur->next = prev;
      prev = cur;
    }
    return cur;
  }
};