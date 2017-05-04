/*
Medium
5.Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
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

  ListNode* detectCycle(ListNode* head){
    // head --x--    cstart  --b-- meet --a-- ctart
    // 2(x + b + k1(a+b)) = x + b + k2(a+b)
    // x = (k2-2k1-1)(a+b) + a
    // after meet, take a steps

    if (head == nullptr || head->next == nullptr)
      return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *meet= head;
    
    while(fast->next !=nullptr && fast->next->next!=nullptr) { //game goes on
      slow = slow->next;
      fast = fast->next->next;
      
      if(slow == fast){ // has cycle
	while(slow != meet){  // find meet point
	  slow = slow->next;
	  meet = meet->next;
	}
	return meet;
      }
      
    }
    
    return nullptr; 
  }
    
};


