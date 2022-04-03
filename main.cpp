#include "naive-tsp.h"
#include "greedy-tsp.h"
#include "dp-tsp.h"
#include <filesystem>
#include <string>

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Usage: ./main <Path>(Path to dir with graph files)\n";
    return 0;
  }

  std::string path = argv[1];

  for (const auto & entry : std::filesystem::directory_iterator(path)) {
    std::cout << "\n";
    std::string entryString = entry.path().string();
    DpTsp* dp_tsp = new DpTsp(entryString);
    NaiveTsp* nv_tsp = new NaiveTsp(entryString);
    GreedyTsp* gd_tsp = new GreedyTsp(entryString);

    clock_t t0 = clock();
    int dp_value = dp_tsp->Solve();
    long double time0 = (long double)(clock() - t0);
    long double dp_time = time0 / CLOCKS_PER_SEC;

    clock_t t1 = clock();
    int nv_value = nv_tsp->Solve();
    long double time1 = (long double)(clock() - t1);
    long double nv_time = time1 / CLOCKS_PER_SEC;

    clock_t t2 = clock();
    int gd_value = gd_tsp->Solve();
    long double time2 = (long double)(clock() - t2);
    long double gd_time = time2 / CLOCKS_PER_SEC;

    printf("%21s|%19s|%22s|%20s|%21s|%12s|%13s|", "instancia", "Valor Fuerza Bruta", "Tiempo Fuerza Bruta(s)", "Valor Prog. Dinámica", "Tiempo Prog. Dinámica", "Valor Voraz", "Tiempo Voraz");
    std::cout << "\n";
    if(nv_time >= 10) {
      printf("%21s|%19d|%22s|%20d|%21s|%12d|%13Lf|", entryString.c_str(), nv_value, "EXCESIVO", dp_value, "EXCESIVO", gd_value, gd_time);
    } else {
      printf("%21s|%19d|%22Lf|%20d|%21Lf|%12d|%13Lf|", entryString.c_str(), nv_value, nv_time, dp_value, dp_time, gd_value, gd_time);
    }
    
    std::cout << "\n";
    }
  
  return 0;
}