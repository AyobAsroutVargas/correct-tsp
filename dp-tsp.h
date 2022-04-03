#ifndef DP_TSP_
#define DP_TSP_

#include "tsp.h"
#include <map>

class DpTsp : public Tsp {
 public:
  DpTsp(std::string filename);
  ~DpTsp(){};
  int Solve();
  int dpTsp(int mask, int pos);
  int ALL_VISITED;
  clock_t t0;
};

#endif