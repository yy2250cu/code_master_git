/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


#include<string>
#include<stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for(auto c : s){
      switch (c) {
      case '(':
      case '{':
      case '[': stk.push(c); break;
      case ')': if (stk.empty() || stk.top()!='(') return false;  else stk.pop(); break;
      case '}':	if (stk.empty() || stk.top()!='{') return false;  else stk.pop(); break;
      case ']': if (stk.empty() || stk.top()!='[') return false;  else stk.pop(); break;
      default: ;
      }
    }
    return stk.empty();
  }

};



