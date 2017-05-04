/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#include<vector>         // for graph
#include<unordered_map>  // for clone
#include<unordered_set>  // for traverse
#include<stack>         // for traverse
#include<queue>         
#include<iostream>
#include<cstddef>
using namespace std;

struct UndirectedGraphNode{
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x): label(x) { }
};


class Solution {
public:
  
  UndirectedGraphNode* cloneGraph_bfs(UndirectedGraphNode * node){
    if(!node) return nullptr;
    hash[node] = new UndirectedGraphNode(node->label);   // clone
    queue<UndirectedGraphNode*> q;
    q.push(node);
    while(q.size() >0){
      UndirectedGraphNode* cur = q.front();
      q.pop();
      for(auto nd: cur->neighbors){
	if(hash.find(nd) == hash.end()) {  //  a new node
	  hash[nd] = new UndirectedGraphNode(nd->label); // clone
	  q.push(nd);
	}
	hash[cur]->neighbors.push_back(hash[nd]);        // build neighbors 
      }

    }

    return hash[node];
  }
  
private:
  //hash maps each node in the original graph to its copy in the cloned graph.
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
};


void traverse_dfs_stack(UndirectedGraphNode* node){
  
  unordered_set<UndirectedGraphNode*> visited;
  stack<UndirectedGraphNode*> s;
  s.push(node);
  visited.insert(node);
  while(s.size()>0){
    UndirectedGraphNode* cur = s.top();
    cout<< cur->label << endl;
    s.pop();
    for (auto nd : cur->neighbors){
      if(visited.find(nd) == visited.end()){  // not visited yet
	s.push(nd);
	visited.insert(nd);
      }
    }
  }
  
  return ;
}
  
