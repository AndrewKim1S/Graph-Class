#include "Graph.h"


Graph::Graph(int num) : numVertices(num) {}
Graph::~Graph(){}


void Graph::addVertex(int id, int w){
  vertices.emplace_back(id, w);
}


bool Graph::addEdge(size_t src, size_t dst, int w){
  // Remove condition if vertexes are not in order 
  if(src >= vertices.size() && dst >= vertices.size()){
    return false;
  }

  edges.emplace_back(src, dst, w);

  vertices[src].edges.emplace_back(src, dst, w);
  numVertices ++;
  return true;
}


std::string Graph::to_string(){
  std::string graph = "";
  for(size_t i = 0; i < vertices.size(); i++){
    graph += "\n" + std::to_string(i) + " -> ";
    for(size_t k = 0; k < vertices[i].edges.size(); k++){
      graph += std::to_string(vertices[i].edges[k].dst) += " ";
    }
  }
  return graph;
}


// Taverse the graph in BFS 
void Graph::BFSTraversal(int s){
  std::vector<int> visited;
  std::list<int> queue;
  queue.push_back(s);

  while(!queue.empty()){
    s = queue.front();
    queue.pop_front();
    std::cout << s << " ";

    for(size_t i = 0; i < vertices[s].edges.size(); i++){
      int id = vertices[s].edges[i].dst;
      if(std::find(visited.begin(), visited.end(), id) == visited.end()){
        queue.push_back(id);
        visited.push_back(id);
      }
    }
  }
}


void Graph::DFS(int s){
  visitedDFS.clear();
  DFSTraversal(s);
}


// Traverse the graph in DFS
void Graph::DFSTraversal(int s){
  std::cout << s << " ";
  visitedDFS.push_back(s);

  //Recursion
  for(size_t i = 0; i < vertices[s].edges.size(); i++){
    int id = vertices[s].edges[i].dst;
    if(std::find(visitedDFS.begin(), visitedDFS.end(), id) == visitedDFS.end()){
      DFSTraversal(id);
    }
  }
}


// This works on the basis that the id of the node is in the correct index
int Graph::dijkstra(int s, int dst){
  std::vector<int> visited;
  std::list<int> queue;

  std::vector<std::pair<int, int>> length;
  
  for(size_t i = 0; i < vertices.size(); i++){
    std::pair<int, int> tmp(vertices[i].id, std::numeric_limits<int>::max());
    length.push_back(tmp);
  }
  length[0].second = 0;

  queue.push_back(s);

  while(!queue.empty()){
    s = queue.front();
    queue.pop_front();

    for(size_t i = 0; i < vertices[s].edges.size(); i++){
      int id = vertices[s].edges[i].dst;
      
      int vertexLength = length[s].second + vertices[s].edges[i].weight; 
      if(vertexLength < length[id].second){
        length[id].second = vertexLength;
      }
      
      if(std::find(visited.begin(), visited.end(), id) == visited.end()){
        queue.push_back(id);
        visited.push_back(id);
      }
    }
  }
  for(size_t i = 0; i < length.size(); i++){
    std::cout << length[i].first << ": " << length[i].second << "\n";
  }

  return 0;
}
