// Dynamic Array implementation of a Graph
// Copyright (c) 2021 Jaemok C. Lee 
#include <iostream>

#include "ArrayGraph.h"

int main() {
  try{
    ArrayGraph test1;
    test1.insertVertex('1');
    test1.insertVertex('2');
    test1.insertVertex('3');
    test1.insertVertex('4');
    test1.insertVertex('5');
    test1.insertVertex('6');
    test1.insertVertex('7');
    test1.insertVertex('8');
    test1.insertVertex('9');

    test1.insertEdge('1', '2', 1);
    test1.insertEdge('2', '3', 2);
    test1.insertEdge('2', '6', 2);
    test1.insertEdge('3', '4', 2);
    test1.insertEdge('3', '5', 2);
    test1.insertEdge('1', '7', 1);
    test1.insertEdge('1', '8', 1);
    test1.insertEdge('8', '9', 1);

    test1.DepthFirst();

    ArrayGraph test2;
    test2.insertVertex('A');
    test2.insertVertex('B');
    test2.insertVertex('C');
    test2.insertVertex('D');
    test2.insertVertex('E');
    test2.insertVertex('F');

    test2.insertEdge('A', 'B', 1);
    test2.insertEdge('A', 'C', 1);
    test2.insertEdge('A', 'D', 1);
    test2.insertEdge('B', 'C', 1);
    test2.insertEdge('B', 'E', 1);
    test2.insertEdge('C', 'D', 1);
    test2.insertEdge('C', 'E', 1);
    test2.insertEdge('C', 'F', 1);
    test2.insertEdge('F', 'D', 1);

    test2.BreadthFirst();
  } catch(const char* msg){
    std::cerr << msg << std::endl;
  }

  return 0;
}