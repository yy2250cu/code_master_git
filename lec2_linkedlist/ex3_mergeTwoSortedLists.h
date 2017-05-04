/*
Definition for linked list:

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) { }
};
 
*/

#include<cstddef>
#include<climits>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) { }
};


class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

    ListNode node(INT_MIN);
    ListNode* cur = &node;

    while (l1 && l2){     // l1: 1 -> 3-> 5   l2: 2 -> 4 ->6
      if(l1->val < l2->val){  // from small to big
	cur->next = l1;
	l1 = l1->next;
      }
      else {
	cur->next = l2;
	l2 = l2->next;
      }
      cur = cur->next;
    }
    
    cur->next = l1? l1 : l2;
    return node.next;
    
  }
  
};
