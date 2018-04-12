#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//  0 ---- 1 ---- 2
//  |      |      |
//  |      |      |
//  |      |      |
//  5      4 ---- 3

//returns index of first found position
//returns -1 if not found
int find_in_vector(vector<int> v, int val){
  for(int i = 0; i < v.size(); i++){
    if(v[i] == val){
      return i;
    }
  }
  return -1;
}


//true: found cycle, false: death end
bool explore_node(int node, unordered_map<int, vector<int>> graph, int parent, vector<int> &visited){

  visited.push_back(node);

  for(int j = 0; j < graph[node].size(); j++){

    int neighbor = graph[node][j];

    if(neighbor != parent && neighbor != node){ //check if came through it or it's a loop with itself
      if(find_in_vector(visited,neighbor) >= 0){ //check if visited, it means found cycle
        return true;
      }else{
        if(explore_node(neighbor,graph,node,visited)){ //if found cycle, no need to keep looking
          return true;
        }
      }
    }
  }
  return false;
}

bool has_cycle(unordered_map<int, vector<int>> graph, int start){
  vector<int> visited;

  //Use DFS deep-first search to explore nodes
  if(explore_node(start, graph, -1, visited)){
    return true;
  }

  return false;
}


int main(){
  //Graph represented as adjacents list
  unordered_map<int, vector<int>> graph {
      {0, {1, 5}},
      {5, {0}},
      {1, {0, 2, 4}},
      {4, {1, 3}},
      {2, {1, 3}},
      {3, {2, 4}}
  };
  cout << "Found cycle in graph?: " << has_cycle(graph, 5);
  return 0;
}
