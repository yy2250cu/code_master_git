// 237. Delete Node in a Linked List
/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

Subscribe to see which companies asked this question.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<cstddef>
// Definition for sinly-linked list.
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {} 
};



class Solution {
  // step 1: copy next node into current node
  // step 2: delete the next node
public:
    void deleteNode(ListNode* node) {
      ListNode*  tmp = node->next;        
      node->val     = tmp->val;           
      node->next    = tmp->next;    // end of step1; step2 no need when var is on stack
    }
  
};




