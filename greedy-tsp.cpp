#include "greedy-tsp.h"

GreedyTsp::GreedyTsp(std::string filename) {
  distanceMatrix_.parseFromFile(filename);
}

int GreedyTsp::Solve(){
  int sum = 0;
  int counter = 0;
  int j = 0, i = 0;
  int min = INT_MAX;
  std::map<int, int> visitedRouteList;

  visitedRouteList[0] = 1;
  int route[distanceMatrix_.matrix.size()];

  while (i < distanceMatrix_.matrix.size() && j < distanceMatrix_.matrix[i].size()) {
    if (counter >= distanceMatrix_.matrix[i].size() - 1) {
      break;
    }

    if (j != i && (visitedRouteList[j] == 0)) {
      if (distanceMatrix_.matrix[i][j] < min) {
        min = distanceMatrix_.matrix[i][j];
        route[counter] = j + 1;
      }
    }
    j++;

    if (j == distanceMatrix_.matrix[i].size()) {
      sum += min;
      min = INT_MAX;
      visitedRouteList[route[counter] - 1] = 1;
      j = 0;
      i = route[counter] - 1;
      counter++;
    }
  }

  i = route[counter - 1] - 1;
  sum += distanceMatrix_.matrix[i][0];
  return sum;
}