#ifndef DISTANCE_MATRIX_
#define DISTANCE_MATRIX_

#include <algorithm>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>


class DistanceMatrix {
 public:
  std::string getNode(int node);
  void parseFromFile(std::string filename);
  int getNodeIndex(std::string node);
  
  std::vector<std::vector<int>> matrix;
  std::vector<std::string> nodes;
  int size;
};

#endif