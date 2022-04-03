#include "distance-matrix.h"

int DistanceMatrix::getNodeIndex(std::string node) {
  auto it = std::find(nodes.begin(), nodes.end(), node);
  if (it != nodes.end())
  {
    int index = it - nodes.begin();
    return index;
  }
  else {
    return -1;
  }
}

void DistanceMatrix::parseFromFile(std::string filename) {
  std::string line;
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Unable to open file";
    return;
  }

  std::getline(file, line);
  size = std::stoi(line);
  matrix.resize(size);
  for (int i = 0; i < size; i++) {
    matrix[i].resize(size);
  }


  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if(i == j) {
        matrix[i][j] = 0;
      } else {
        matrix[i][j] = INT_MAX;
      }
    }
  }

  while (std::getline(file, line)) {
    std::istringstream iss (line);
    std::string word, src, dest;
    int weight;

    iss >> word;
    if (getNodeIndex(word) == -1) nodes.push_back(word);
    src = word;

    iss >> word;
    if (getNodeIndex(word) == -1) nodes.push_back(word);
    dest = word;

    iss >> word;
    weight = std::stoi(word);

    matrix[getNodeIndex(src)][getNodeIndex(dest)] = weight;
    matrix[getNodeIndex(dest)][getNodeIndex(src)] = weight;
  }
  file.close();
}