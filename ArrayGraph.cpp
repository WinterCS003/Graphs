#include <iostream>

#include "ArrayGraph.h"

ArrayGraph::ArrayGraph(){
  // initialize an empty graph
  myGraph = new int*[SIZE];
  for(int i = 0; i < SIZE; i++){
    myGraph[i] = new int[SIZE];
  }

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      myGraph[i][j] = -1; // indicates empty
    }
  }

  vertices = new char[SIZE];
  this->count = 0;
}

ArrayGraph::~ArrayGraph(){
  for(int i = 0; i < SIZE; i++){
    delete [] myGraph[i];
  }
  delete [] myGraph;

  delete [] vertices;
}



bool ArrayGraph::isEmpty() const {
  return count == 0;
}

int ArrayGraph::vertexIndex(char node) const {
  for(int i = 0; i < count; i++){
    if(vertices[i] == node){
      return i;
    }
  }

  return -1;
}

void ArrayGraph::DepthFirst(char node, bool* visited) const {
  int index = vertexIndex(node);

  if(index == -1){
    return;
  }

  visited[index] = true;
  std::cout << node << " -> ";
  for(int j = 0; j < count; j++){
    if(myGraph[index][j] != -1 && !visited[j]){
      DepthFirst(vertices[j], visited);
    }
  }
}

void ArrayGraph::DepthFirst() const {
  if(isEmpty()){
    return;
  }

  bool visited[count];
  DepthFirst(vertices[0], visited); // start from root node
  std::cout << std::endl;
}

void ArrayGraph::BreadthFirst(char node, bool* visited) const {
  int index = vertexIndex(node);

  if(index == -1){
    return;
  }

  if(!visited[index]){
    std::cout << node << " -> ";
    visited[index] = true;
  }
  // print all adjacent vertices/vertices in the same level
  for(int j = 0; j < count; j++){
    if(myGraph[index][j] != -1 && !visited[j]){
      std::cout << vertices[j] << " -> ";
      visited[j] = true;
    }
  }

  // move to next level
  for(int j = 0; j < count; j++){
    if(myGraph[index][j] != -1){
      BreadthFirst(vertices[j], visited);
    }
  }
}

void ArrayGraph::BreadthFirst() const {
  if(isEmpty()){
    return;
  }

  bool visited[count];
  BreadthFirst(vertices[0], visited);
  std::cout << std::endl;
}

void ArrayGraph::insertVertex(char node){
  if(count == SIZE){
    throw "Graph is full";
    return;
  }
  if(vertexIndex(node) != -1){
    throw "Node already exists";
    return;
  }
 
  vertices[count++] = node;
}

void ArrayGraph::insertEdge(char vertex1, char vertex2, int weight){
  int i = vertexIndex(vertex1);
  int j = vertexIndex(vertex2);

  if(i == -1 || j == -1){
    throw "Vertex does not exist";
    return;
  }
  if(myGraph[i][j] != -1){
    throw "Edge already exists";
    return;
  }

  myGraph[i][j] = weight;
  myGraph[j][i] = weight;
}

void ArrayGraph::eraseVertex(char node){
  int index = vertexIndex(node);
  if(index == -1){
    throw "Vertex does not exist";
    return;
  }

  for(int i = index; i < count-1; i++){
    vertices[i] = vertices[i+1];
  }

  for(int i = index; i < count-1; i++){
    for(int j = 0; j < count; j++){
      myGraph[i][j] = myGraph[i+1][j];
    }
  }

  for(int i = 0; i < count; i++){
    for(int j = index; j < count-1; j++){
      myGraph[i][j] = myGraph[i][j+1];
    }
  }

  for(int j = 0; j < count; j++){
    myGraph[count-1][j] = -1;
  }

  for(int i = 0; i < count; i++){
    myGraph[i][count-1] = -1;
  }

  count--;
}
