#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "algorithms.h"
#include "utils.h"

using std::cin;
using std::cout;
using std::ios_base;
using std::max;
using std::swap;
using std::vector;
using std::string;
using std::to_string;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

const int max_algos = 4;
const int max_graphs = 3;
const int sizeStart = 10;
const int sizeFinish = 1010;

vector<vector<vector<int>>> datasCompleteGraph;
vector<vector<vector<int>>> datasConnectedGraph;
vector<vector<vector<int>>> datasSparseGraph;

// функция, генерирующая все необходимые графы всех размеров и видов
void generateAllGraphs() {
    int n, m;
    for (int i = sizeStart; i <= sizeFinish; i += 50) {
        n = i;
        // генерируем полный граф
        m = int(n * (n - 1) / 2);
        vector<vector<int>> dataComplete(m, vector<int>(3, 0));
        generateCompleteGraph(n, m, dataComplete);
        datasCompleteGraph.push_back(dataComplete);
        // генерируем связный граф с коэфф. плотности 0.5
        m = int(m / 2);
        vector<vector<int>> dataConnected(m, vector<int>(3, 0));
        generateConnectedGraph(n, m, dataConnected);
        datasConnectedGraph.push_back(dataConnected);
        // генерируем разреженный граф (дерево-"бамбук")
        m = n - 1;
        vector<vector<int>> dataSparse(m, vector<int>(3, 0));
        generateSparseGraph(n, m, dataSparse);
        datasSparseGraph.push_back(dataSparse);
    }
}

// функция, возвращающая время работы заданного алгоритма
int64_t algoTime(int choice, int n, int m, vector<vector<int>>& data) {
    int algo_answer;
    auto start = high_resolution_clock::now();
    // cout << "Алгоритм ";
    switch (choice) {
        case 1:
            algo_answer = Dijkstra(n, m, data);
            break;
        case 2:
            algo_answer = FloydWarshall(n, m, data);
            break;
        case 3:
            algo_answer = BellmanFord(n, m, data);
            break;
        case 4:
            algo_answer = AStar(n, m, data);
            break;
        default:
            break;
    }
    auto elapsed = high_resolution_clock::now() - start;
    int64_t elapsed_ms = duration_cast<nanoseconds>(elapsed).count();
    // cout << getAlgoName(choice) << " дал результат " << algo_answer << ".\n";
    return elapsed_ms;
}

// функция, возвращающая усреднённое время работы алгоритма с 10 испытаний
int64_t midTime(int choice, int n, int m, vector<vector<int>>& data) {
    int64_t mtime = algoTime(choice, n, m, data);
    for (int i = 1; i < 10; ++i) {
        mtime += algoTime(choice, n, m, data);
    }
    mtime /= 10;
    return mtime;
}

// функция, создающая таблицы отдельно по каждому алгоритму по числу вершин
void createAlgoVertexesTables() {
    std::ofstream myfile;
    string folder = "TablesForGraphs/";
    srand(time(NULL));
    for (int j = 1; j <= max_algos; ++j) {
        myfile.open(folder + getAlgoName(j) + " Vertexes" + ".csv");
        int cnt = 0;
        for (int i = sizeStart; i <= sizeFinish; i += 50) {
            int n, m;
            n = i;
            myfile << n;
            m = int(n * (n - 1) / 2);
            myfile << ';' << midTime(j, n, m, datasCompleteGraph[cnt]);
            m = int(m / 2);
            myfile << ';' << midTime(j, n, m, datasConnectedGraph[cnt]);
            m = n - 1;
            myfile << ';' << midTime(j, n, m, datasSparseGraph[cnt]);
            myfile << '\n';
            ++cnt;
        }
        myfile.close();
    }
}

// функция, создающая таблицы отдельно по каждому алгоритму по числу рёбер
void createAlgoEdgesTables() {
    std::ofstream myfile;
    string folder = "TablesForGraphs/";
    srand(time(NULL));
    for (int k = 1; k <= max_graphs; ++k) {
        for (int j = 1; j <= max_algos; ++j) {
            myfile.open(folder + getGraphName(k) + " " + getAlgoName(j) + ".csv");
            int cnt = 0;
            for (int i = sizeStart; i <= sizeFinish; i += 50) {
                int n, m;
                n = i;
                switch (k) {
                    case 1:
                        m = int(n * (n - 1) / 2);
                        myfile << m << ';' << midTime(j, n, m, datasCompleteGraph[cnt]);
                        break;
                    case 2:
                        m = int(n * (n - 1) / 4);;
                        myfile << m << ';' << midTime(j, n, m, datasConnectedGraph[cnt]);
                        break;
                    case 3:
                        m = n - 1;
                        myfile << m << ';' << midTime(j, n, m, datasSparseGraph[cnt]);
                        break;
                    default:
                        break;
                }
                myfile << '\n';
                ++cnt;
            }
            myfile.close();
        }
    }
}

// функция, создающая таблицы отдельно по каждому виду графов
void createGraphTables(int isVertex) {
    string type;
    if (isVertex == 1) {
        type = " Vertexes";
    } else {
        type = " Edges";
    }
    std::ofstream myfile;
    string folder = "TablesForGraphs/";
    srand(time(NULL));
    for (int j = 1; j <= max_graphs; ++j) {
        myfile.open(folder + getGraphName(j) + type + ".csv");
        int cnt = 0;
        for (int i = sizeStart; i <= sizeFinish; i += 50) {
            int n, m;
            n = i;
            if (isVertex == 1) {
                myfile << n;
            }
            switch (j) {
                case 1:
                    m = int(n * (n - 1) / 2);
                    if (isVertex != 1) {
                        myfile << m;
                    }
                    for (int k = 1; k <= max_algos; ++k) {
                        myfile << ';' << midTime(k, n, m, datasCompleteGraph[cnt]);
                    }
                    break;
                case 2:
                    m = int(n * (n - 1) / 4);
                    if (isVertex != 1) {
                        myfile << m;
                    }
                    for (int k = 1; k <= max_algos; ++k) {
                        myfile << ';' << midTime(k, n, m, datasConnectedGraph[cnt]);
                    }
                    break;
                case 3:
                    m = n - 1;
                    if (isVertex != 1) {
                        myfile << m;
                    }
                    for (int k = 1; k <= max_algos; ++k) {
                        myfile << ';' << midTime(k, n, m, datasSparseGraph[cnt]);
                    }
                    break;
                default:
                    break;
            }
            myfile << '\n';
            ++cnt;
        }
        myfile.close();
    }
}

int main() {
    cout << "Программа начинает работу.\n";
    generateAllGraphs();
    cout << "Все графы всех видов и размеров сгенерированы. Подготовительная работа выполнена.\n";
    createAlgoVertexesTables();
    cout << "Обработано 25%...\n";
    createAlgoEdgesTables();
    cout << "Обработано 50%...\n";
    createGraphTables(1);
    cout << "Обработано 75%...\n";
    createGraphTables(0);
    cout << "Обработано 100%!\n";
    cout << "Программа завершает работу. Конец.\n";
    return 0;
}
