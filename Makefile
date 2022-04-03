CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
DEPS = distance-matrix.h tsp.h naive-tsp.h greedy-tsp.h dp-tsp.h generador.h
OBJ1 = main.o distance-matrix.o naive-tsp.o greedy-tsp.o dp-tsp.o
OBJ2 = generate.o generador.o

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ1)
	$(CXX) -o $@ $^ $(CXXFLAGS)

generate: $(OBJ2)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean:
	rm main *.o generate