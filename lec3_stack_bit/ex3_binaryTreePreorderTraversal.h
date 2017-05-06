/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<cstddef>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      stack<TreeNode*> stk;
      vector<int> result;

      if(root==NULL)
	return result; // check this using test case
      
      stk.push(root);
      while(!stk.empty()){
	TreeNode* node=stk.top();
	result.push_back(node->val);
	stk.pop();
	if(node->right) stk.push(node->right);
	if(node->left) stk.push(node->left);
      }
      return result;
    }
};

