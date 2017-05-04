/*
MEDIUM
2. (3 SUM Problem) Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
Can you do it in O(n2) time?
https://leetcode.com/problems/3sum/#/description
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int>& arry){
    vector<vector<int> > res;

    std::sort(arry.begin(), arry.end());   // key

    for (int i=0; i< arry.size(); i++){

      int target = -arry[i];
      int front = i + 1;                   // key
      int back = arry.size() - 1;          // key

      while(front < back){
	int sum = arry[front] + arry[back];
	if (sum < target)
	  front++;
	else if (sum > target)
	  back--;
	else { // found one
	  vector<int> triplet(3,0);
	  triplet[0] = arry[i];
	  triplet[1] = arry[front];
	  triplet[2] = arry[back];
	  res.push_back(triplet);


	  // rolling to avoid duplicates, after the other two cases
	  while(front < back && arry[front]==triplet[1])
	    front++;  

	  while(front < back && arry[back]==triplet[2])
	    back++;  
	}
      }

      // rolling to avoid duplicates at i
      while(i+1 < arry.size() &&  arry[i+1]==arry[i])
	i++;
      
    }// end of for
    
    return res;
  }

  
};

