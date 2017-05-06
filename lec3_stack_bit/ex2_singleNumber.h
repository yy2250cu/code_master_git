/*
Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/

#include<vector>
#include<stack>
#include<cstddef>
#include<climits>
#include<iostream>
using namespace std;

class Solution{
public:

  int singleNumber(vector<int>& nums){ // what if there is a single 0, 
                                       // cannot tell!! {0}, {1,1}
    for(int i=0; i<nums.size();i++)
      nums[i+1] = nums[i] ^ nums[i+1]; // xor, same is zero, not same is one
    
    return nums[nums.size()-1];
  }



  
  int singleNumber_old(vector<int>& nums){

    stack<int> stk;
    stk.push(nums[0]);
    for(int i=1; i != nums.size(); i=i+1){
      if (stk.size()>0 && stk.top() == nums[i]) stk.pop();
      else stk.push(nums[i]);
    }

    if(stk.size()>0) return stk.top();
    else {
      cout << "all pairs! "<< endl;
      return INT_MIN;
    }
    
  }
  
};



