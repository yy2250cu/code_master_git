/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include<cstddef>

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr) { }
};

class Solution{
public:
  bool hasCycle(ListNode *head){

    if(!head)
      return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next!=nullptr) {// game goes on
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)   // meet
	return true;   
    }
    return false;        // none
  }
    
};

