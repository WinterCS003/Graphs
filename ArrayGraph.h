#ifndef ARRAYGRAPH_H
#define ARRAYGRAPH_H

const int SIZE = 100; // max size of graph is 100

class ArrayGraph{
  private:
    char* vertices; // array of all vertices
    int** myGraph; // dynamic 2D array implementation of edges
    int count;     // number of vertices

    int vertexIndex(char node) const;
    void DepthFirst(char node, bool* visited) const;
    void BreadthFirst(char node, bool* visited) const;
  public:
    // CONSTRUCTORS & DESTRUCTORS
    ArrayGraph();
    ~ArrayGraph();

    // ACCESSORS
    bool isEmpty() const;  // returns true if graph is empty
    void DepthFirst() const;
    void BreadthFirst() const;

    // MUTATORS
    void insertVertex(char node); // inserts a new vertex
    void insertEdge(char vertex1, char vertex2, int weight); // connect v1 with v2
    void eraseVertex(char node); // erases a vertex
};

#endif // ARRAYGRAPH_H