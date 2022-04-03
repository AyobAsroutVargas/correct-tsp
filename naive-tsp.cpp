#include "naive-tsp.h"

NaiveTsp::NaiveTsp(std::string filename) {
  distanceMatrix_.parseFromFile(filename);
}

int NaiveTsp::Solve(){
  clock_t t0 = clock();
  
  std::vector<int> nodes;
  for (int i = 1; i < distanceMatrix_.nodes.size(); i++) {
    nodes.push_back(i);
  }

  int minPath = INT_MAX;
  do {
    long double time0 = (long double)(clock() - t0);
    long double time_seconds = time0 / CLOCKS_PER_SEC;
    if (time_seconds > 10) return minPath;

    int currentPath = 0;

    int k = 0;
    for (int i = 0; i < nodes.size(); i++) {
      currentPath += distanceMatrix_.matrix[k][nodes[i]];
      k = nodes[i];
    }
    currentPath += distanceMatrix_.matrix[k][0];

    minPath = std::min(minPath, currentPath);
  } while (std::next_permutation(nodes.begin(), nodes.end()));
  return minPath;
}
