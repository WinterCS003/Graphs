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
  } catch(const char* msg){
    std::cerr << msg << std::endl;
  }

  return 0;
}