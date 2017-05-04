/*
40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 

[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

 */

#include<vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target){

    vector<vector<int> > res;
    sort(num.begin(), num.end()); // <O(n^2) anyway
    vector<int> local;
    dfs_backtracking(res, 0, target, local, num);
    return res;
  }

  void dfs_backtracking(vector<vector<int> >& res, const int start,
			const int target, vector<int>& local,
			vector<int>& num){
    
    if (target == 0){   
      res.push_back(local);   // record
      return ;
    }

    for(int i=start; i<num.size(); i++) {
	if(num[i]>target) return;   // cannot found, no record
	if( i>start && (num[i] == num[i-1]) ) continue; //avoid duplicate
	local.push_back(num[i]);
	dfs_backtracking(res, i+1, target-num[i],local,num); 
	local.pop_back();
    }
    
    return;
  }

  
};

