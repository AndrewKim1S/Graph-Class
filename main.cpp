#include <iostream>
#include "Graph.h"


int main(){
  Graph graph(4);
  
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);
  graph.addVertex(6);
  graph.addVertex(7);
  graph.addVertex(8);
  graph.addVertex(9);

  graph.addEdge(0,1,9);
  graph.addEdge(0,2,6);
  graph.addEdge(1,3,2);
  graph.addEdge(2,3,11);
  graph.addEdge(2,5,15);
  graph.addEdge(2,8,6);
  graph.addEdge(3,4,9);
  graph.addEdge(4,1,14);
  graph.addEdge(4,5,7);
  graph.addEdge(4,6,5);
  graph.addEdge(5,3,10);
  graph.addEdge(5,6,6);
  graph.addEdge(5,7,12);
  graph.addEdge(6,7,2);
  graph.addEdge(6,9,7);
  graph.addEdge(7,9,1);
  graph.addEdge(8,5,12);
  graph.addEdge(8,9,12);

  std::cout << "\nGraph Display";
  std::cout << graph.to_string() << std::endl;

  std::cout << "\nBFS Traversal" << std::endl;
  graph.BFSTraversal();

  std::cout << "\n\nDFS Traversal" << std::endl;
  graph.DFS();

  std::cout << "\n\nDijkstra's Algorithm" << std::endl;
  graph.dijkstra(0,9);

  return 0;
}


