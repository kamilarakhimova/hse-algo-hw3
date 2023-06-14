#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>

using std::vector;
using std::string;

void generateCompleteGraph(int n, int m, vector<vector<int>>& data);
void generateConnectedGraph(int n, int m, vector<vector<int>>& data);
void generateSparseGraph(int n, int m, vector<vector<int>>& data);
string getAlgoName(int choice);
string getGraphName(int choice);
