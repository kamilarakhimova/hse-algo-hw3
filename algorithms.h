#include <iostream>
#include <set>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::make_pair;
using std::min;
using std::max;
using std::pair;
using std::priority_queue;
using std::set;
using std::vector;

const int kInf = 100000;
const int startVertex = 0;

struct Edge {
    int a, b, weight;
};

int isPath(int ans);
int Dijkstra(int n, int m, vector<vector<int>>& data);
int FloydWarshall(int n, int m, vector<vector<int>>& data);
int BellmanFord(int n, int m, vector<vector<int>>& data);
int AStar(int n, int m, vector<vector<int>>& data);
