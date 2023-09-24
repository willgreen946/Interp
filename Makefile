all:
	$(CXX) src/main.cpp -o cbasic -Wall -pedantic -g

old:
	$(CXX) src/old/old.cpp -o cbasic -Wall -pedantic -g
