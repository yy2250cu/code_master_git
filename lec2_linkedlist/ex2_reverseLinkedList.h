/*
2. Reverse Linked List
Reverse a singly linked list.
For input: 1 -> 2 -> 3 -> 4 -> 5 -> 6
output should be 6 -> 5 -> 4 -> 3 -> 2 -> 1
Can you do it in O(n) without using extra space.
https://leetcode.com/problems/reverse-linked-list/#/description

Suggestion: do both iteratively and recursively. 

this is a iteration solution
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

struct ListNode {  
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};


class Solution {
public:

  // version 1.a: iteration; use an extra node pre and two pointers pre, cur
    ListNode* reverseList_iter1a(ListNode* head) {
      ListNode new_Head(0);           // stack
      ListNode* new_head = &new_Head;

      new_head->next = head;

      // use two pointers
      ListNode* pre = new_head;
      ListNode* cur = head;
      while(cur && cur->next){
	ListNode* tmp = pre->next;
	pre->next = cur->next;  // see the picture  0(pre)... 1(cur)...2 ->3->4 
	cur->next = cur->next->next;
	pre->next->next = tmp;
      }
      return new_head->next;
    }

  
  // version 1.b: iteration; use non extra node
  ListNode* reverseList_iter1b(ListNode* head){
    ListNode* pre = nullptr;
    while(head){  // moving head forward, and pre forward
      ListNode* next = head->next;    // NULL(pre)...1(head) ... 2 ->3 ->4
      head->next = pre;               // NULL<-1(pre) ... 2(head) ->3 ->4
      pre = head;
      head = next;
    }

    return pre;
    
  }

  // version 2: recursive
  ListNode* reverseList_recr(ListNode* head){
    if (!head || !(head->next) )   // two boundary cases: front & back
      return head;

    ListNode* node  = reverseList_recr(head->next);
    head->next->next = head;        //   1-> 2-> 3(head) ... 4(node) <- 5 <- 6(node)
    head->next = nullptr;


    return node;   // always the EOF original linked list
  }

  
};

