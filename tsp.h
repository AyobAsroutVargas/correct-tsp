#ifndef TSP_
#define TSP_

#include "distance-matrix.h"

class Tsp {
 public:
  Tsp(){};
  virtual ~Tsp(){};
  virtual int Solve() = 0;
  DistanceMatrix distanceMatrix_;
  std::vector<int> route;
};

#endif