/*
3. Given a graph shown below, construct your own graph, then output all the nodes based on the constructed graph using BFS, DFS or topological sort;
input: (graph use map, BFS, DFS, topological sort)

Output: 0, 1, 2, 3, 4, 5, 6 (the output order doesn’t matter)
You can use vector, list or map to construct your graph,
For instance, we can construct this graph using vector as follows:
vector<int> nodes = {0, 1, 2, 3, 4, 5, 6};
vector<int> neighbors[7];
neighbors[0] = {1, 2};
neighbors[1] = {0, 2, 3, 4, 6};
neighbors[2] = {0, 1};
neighbors[3] = {1, 5};
neighbors[4] = {1, 5};
neighbors[5] = {3, 4};
neighbors[6] = {1};
Hint: you can use hashSet to store all the visited nodes.

BFS-Recursive, BFS-stack, DFS, 
 */


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */



// source: leetcode && github from Xiaoxin Wu

#include<vector>         // for graph
#include<unordered_map>  // for clone
#include<unordered_set>  // for traverse DFS & BFS
#include<stack>          // for traverse DFS
#include<queue>          // for traverse BFS
#include<iostream>
using namespace std;

struct UndirectedGraphNode{
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x): label(x) { }
};


class Solution {
public:
  
  

  
  void traverse_dfs_recur(UndirectedGraphNode* node,
			  unordered_set<UndirectedGraphNode*>& visited){  
    for(auto nd: node->neighbors){
      if(visited.find(nd) == visited.end()){ // not visited yet
	cout<< nd->label << endl;
	visited.insert(nd);
	traverse_dfs_recur(nd, visited);     // FILO on the recursive stack
      }
    }
    return;
  }
  
  
  void traverse_dfs_stack(UndirectedGraphNode* node){
    unordered_set<UndirectedGraphNode*> visited;
    stack<UndirectedGraphNode*> s;
    s.push(node);
    visited.insert(node);
    while(s.size()>0){
      UndirectedGraphNode* cur = s.top();
      cout<< cur->label << endl;
      s.pop();                                  // FILO, sweep at back
      for (auto nd : cur->neighbors){
	if(visited.find(nd) == visited.end()){  // not visited yet
	  s.push(nd);
	  visited.insert(nd);
	}
      }
    }
    return ;
  }
  
  void traverse_bfs_queue(UndirectedGraphNode* node){
    unordered_set<UndirectedGraphNode*> visited;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    visited.insert(node);
    while(q.size()>0){
      UndirectedGraphNode* cur = q.front();
      cout << cur->label << endl;
      q.pop();                                  // FIFO, sweep at the front
      for(auto nd : cur->neighbors){
	if(visited.find(nd) == visited.end()) { // not visited yet
	  q.push(nd);
	  visited.insert(nd);
	}
      }
    }
    return;
  }
  
  };
  

  


int main(){
  
  UndirectedGraphNode node0(0);
  UndirectedGraphNode node1(1);
  UndirectedGraphNode node2(2);
  UndirectedGraphNode node3(3);
  UndirectedGraphNode node4(4);
  UndirectedGraphNode node5(5);
  UndirectedGraphNode node6(6);

  
  node0.neighbors.push_back(&node1);
  node0.neighbors.push_back(&node2);

  node1.neighbors.push_back(&node0);
  node1.neighbors.push_back(&node2);
  node1.neighbors.push_back(&node3);
  node1.neighbors.push_back(&node4);
  node1.neighbors.push_back(&node6);

  node2.neighbors.push_back(&node0);
  node2.neighbors.push_back(&node1);
  
  node3.neighbors.push_back(&node1);
  node3.neighbors.push_back(&node5);

  node4.neighbors.push_back(&node1);
  node4.neighbors.push_back(&node5);

  node5.neighbors.push_back(&node3);
  node5.neighbors.push_back(&node4);

  node6.neighbors.push_back(&node1);

  

  Solution s;
  //UndirectedGraphNode* copy = s.cloneGraph(&node0);

  cout << " output of traverse dfs-stack:" << endl;
  s.traverse_dfs_stack(&node0);

  cout << " output of traverse dfs-recursion:" <<endl;
  unordered_set<UndirectedGraphNode*> visited;
  s.traverse_dfs_recur(&node0, visited);

  cout << "output of traerse bfs-queue:" << endl;
  s.traverse_bfs_queue(&node0);
  
  return 0;
}
