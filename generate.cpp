#include "generador.h"

int main() {
  Generator* generator = new Generator();
  for (int i = 20; i > 1; i--) {
    std::string filename = "grafos/instancia_" + std::to_string(i);
    for (int j = 0; j < 20; j++) {
      std::string tempfilename = filename + "_" + std::to_string(j);
      generator->GenerateInstance(tempfilename, i);
    }
  }
  return 0;
}