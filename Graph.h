#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>


// Graph structure
class Graph{
  
  public:
    
    // Edge structure
    struct Edge{
      size_t src;
      size_t dst;
      int weight;

      Edge(size_t s, size_t d, int w) : src(s), dst(d), weight(w){}
    };


    // Vertex structure
    struct Vertex{
      int id;
      int weight;

      std::vector<Edge> edges;

      Vertex(int i, int w) : id(i), weight(w) {}
    };


    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<int> visitedDFS;

    Graph(int num);
    ~Graph();

    void addVertex(int id, int w = 0);
    bool addEdge(size_t src, size_t dst, int w = 0);

    void BFSTraversal(int s = 0);
    void DFS(int s = 0);
    void DFSTraversal(int s);

    int dijkstra(int s = 0, int dst = 0);

    std::string to_string();

  private:
    int numVertices;
};



