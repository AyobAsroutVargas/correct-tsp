#ifndef GREEDY_TSP_
#define GREEDY_TSP_

#include "tsp.h"
#include <map>

class GreedyTsp : public Tsp {
 public:
  GreedyTsp(std::string filename);
  ~GreedyTsp(){};
  int Solve();
};

#endif