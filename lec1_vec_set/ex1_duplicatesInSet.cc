/*

EASY: 
1. given a set of integer number, find duplicate among them.
Input  : arr[] = {1, 5, 2, 1, 4, 3, -1, 7, 2, 8, 9, 5}
Output : Duplicate item are : 5 2 1 
Can you do it in O(n) time?

*/

#include<iostream>
#include<vector>
#include<unordered_map> //hash

using namespace std;
typedef unordered_map<int, size_t> count_table;


count_table gen_count_table(vector<int> arry){

  count_table tmp; // empty

  int key;
  for (size_t i=0; i<= arry.size(); i++){
    key = arry[i];
    count_table::iterator it = tmp.find(key);

    if (it == tmp.end()) // not found
      tmp.insert({key, 1});
    else                 // found
      tmp[key]++;
  }   

  return tmp;
}



int main(){
  
  vector<int> arr = {1, 5, 2, 1, 4, 3, -1, 7, 2, 8, 9, 5};
  count_table arr_count;
  
  arr_count = gen_count_table(arr);

  // output duplicates, with value >=2
  cout << "duplicates are: ";
  for(auto a: arr_count)
    if (a.second > 1)
      cout << a.first << " ";
  cout << endl;
    
  return 0;

}
