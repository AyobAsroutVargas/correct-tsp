#include "generador.h"

void Generator::GenerateInstance(std::string filename, int size) {
  srand((unsigned) time(NULL));
  //std::string filenamePath = "Grafos/" + filename;
  std::fstream output_stream;

  output_stream.open(filename, std::ios_base::out);
  if (!output_stream.is_open()) {
    std::cerr << "Could not open the file\n";
    return;
  }
  output_stream << size;
  output_stream << "\n";
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      output_stream << i << " " << j << " " << rand() % 100 << "\n";
    }
  }
}