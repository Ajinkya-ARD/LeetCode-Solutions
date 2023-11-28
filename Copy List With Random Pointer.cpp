/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if(!head) return nullptr;
    // copy nodes
    Node *cur = head;
    while(cur) {
      Node *newNode = new Node(cur->val);
      newNode->next = cur->next;
      newNode->random = cur->random;
      cur->next = newNode;
      cur = newNode->next;
    }

    // fix random
    cur = head;
    while(cur) {
      cur = cur->next;
      if(cur->random) cur->random = cur->random->next;
      cur = cur->next;
    }
    
    // separate two list
    Node *newHead = head->next;
    cur = head;
    Node *newCur = newHead;
    while(cur) {
      cur->next = newCur->next;
      cur = cur->next;
      newCur->next = cur ? cur->next : nullptr;
      newCur = newCur->next;
    }
    
    return newHead;
  }
};