/*
4. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include<vector>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:

  int evalRPN(vector<string>& tokens){ // tail recursion
    string s  = tokens.back();
    tokens.pop_back();

    if (s=="*" || s=="/" || s=="+" || s=="-"){
      int r2 = evalRPN(tokens);
      int r1 = evalRPN(tokens);
      if(s=="+") return r1+r2;
      if(s=="-") return r1-r2;
      if(s=="*") return r1*r2;
      if(s=="/") return r1/r2;
    }
    
    return stoi(s); // else
  }



  
    int evalRPN_stack(vector<string>& tokens) {
      stack<string> stk;   // used extra storage! recursion also use extra storage for func stack
      
      int a;
      int b;
      for(int i=0; i<tokens.size(); i++){
	if (tokens[i]== "+") {
	  a = stoi(stk.top()); stk.pop();
	  b = stoi(stk.top()); stk.pop();
	  stk.push(to_string(b+a));
	}
	else if (tokens[i]=="-"){
	  a = stoi(stk.top()); stk.pop();
	  b = stoi(stk.top()); stk.pop();
	  stk.push(to_string(b-a));         // LIFO
	}
	else if (tokens[i]=="*"){
	  a = stoi(stk.top()); stk.pop();
	  b = stoi(stk.top()); stk.pop();
	  stk.push(to_string(a*b));
	}
	else if (tokens[i]=="/"){
	  a = stoi(stk.top()); stk.pop();
	  b = stoi(stk.top()); stk.pop();
	  stk.push(to_string(b/a));         // LIFO
	}
	else
	  stk.push(tokens[i]);	
      }
      return stoi(stk.top());
    }
};
