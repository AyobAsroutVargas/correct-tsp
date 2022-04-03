#ifndef GENERATOR_
#define GENERATOR_

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class Generator {
 public:
  void GenerateInstance(std::string filename, int size);
};

#endif