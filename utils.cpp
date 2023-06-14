#include "utils.h"

/// генератор полного графа
void generateCompleteGraph(int n, int m, vector<vector<int>>& data) {
    // устанавливаем начальную точку генерирования последовательности
    srand(time(NULL));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            data[cnt][0] = i;
            data[cnt][1] = j;
            // генерируем веса рёбер в диапазоне [1, 10]
            data[cnt][2] = rand() % 10 + 1;
            ++cnt;
        }
    }
}

// генератор связного графа с коэффициентом плотности = 0.5
void generateConnectedGraph(int n, int m, vector<vector<int>>& data) {
    // устанавливаем начальную точку генерирования последовательности
    srand(time(NULL));
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        // для получения связного графа
        data[cnt][0] = i;
        data[cnt][1] = i + 1;
        // генерируем веса рёбер в диапазоне [1, 10]
        data[cnt][2] = rand() % 10 + 1;
        ++cnt;
    }
    while (cnt != m) {
        // генерируем случайные связи между случайными вершинами
        data[cnt][0] = rand() % n;
        data[cnt][1] = rand() % n;
        while (data[cnt][1] == data[cnt][0]) {
            data[cnt][1] = rand() % n;
        }
        // генерируем веса рёбер в диапазоне [1, 10]
        data[cnt][2] = rand() % 10 + 1;
        ++cnt;
    }
}

// генератор разреженного графа (дерева "бамбук")
void generateSparseGraph(int n, int m, vector<vector<int>>& data) {
    // устанавливаем начальную точку генерирования последовательности
    srand(time(NULL));
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        // для получения связного графа - бамбука
        data[cnt][0] = i;
        data[cnt][1] = i + 1;
        // генерируем веса рёбер в диапазоне [1, 10]
        data[cnt][2] = rand() % 10 + 1;
        ++cnt;
    }
}

// функция, возвращающая имя/название алгоритма
string getAlgoName(int choice) {
    string name;
    switch (choice) {
        case 1:
            name = "Dijkstra";
            break;
        case 2:
            name = "FloydWarshall";
            break;
        case 3:
            name = "BellmanFord";
            break;
        case 4:
            name = "A*";
            break;
        default:
            break;
    }
    return name;
}

// функция, возвращающая название типа графа
string getGraphName(int choice) {
    string name;
    switch (choice) {
        case 1:
            name = "Complete Graph";
            break;
        case 2:
            name = "Connected Graph";
            break;
        case 3:
            name = "Sparse Graph";
            break;
        default:
            break;
    }
    return name;
}
