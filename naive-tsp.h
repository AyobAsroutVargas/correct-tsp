#ifndef NAIVE_TSP_
#define NAIVE_TSP_

#include "tsp.h"

class NaiveTsp : public Tsp {
 public:
  NaiveTsp(std::string filename);
  ~NaiveTsp(){};
  int Solve();
};

#endif