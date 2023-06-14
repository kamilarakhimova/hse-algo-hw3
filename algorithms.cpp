#include "algorithms.h"

// функция проверки наличия пути между стартовой и конечной вершиной
int isPath(int ans) {
    if (ans == kInf) {
        ans = -1;
    }
    return ans;
}

// реализация алгоритма Дейкстры [1]
int Dijkstra(int n, int m, vector<vector<int>>& data) {
    int finishVertex; // = n - 1
    int answer;
    finishVertex = n - 1;
    vector<vector<pair<int, int>>> graph(n);
    int a, b, weight;
    for (int i = 0; i < m; ++i) {
        a = data[i][0];
        b = data[i][1];
        weight = data[i][2];
        graph[a].push_back(make_pair(b, weight));
        graph[b].push_back(make_pair(a, weight));
    }
    vector<int> d(n, kInf);
    d[startVertex] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, startVertex));
    while (!q.empty()) {
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v]) {
            continue;
        }
        for (size_t j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first;
            weight = graph[v][j].second;
            if (d[v] + weight < d[to]) {
                d[to] = d[v] + weight;
                q.push(make_pair(-d[to], to));
            }
        }
    }
    answer = d[finishVertex];
    answer = isPath(answer);
    return answer;
}

// реализация алгоритма Флойда-Уоршелла [2]
int FloydWarshall(int n, int m, vector<vector<int>>& data) {
    int finishVertex; // = n - 1
    int answer;
    finishVertex = n - 1;
    vector<vector<int>> graph(n, vector<int>(n, kInf));
    int a, b, weight;
    for (int i = 0; i < m; ++i) {
        a = data[i][0];
        b = data[i][1];
        weight = data[i][2];
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] < kInf && graph[k][j] < kInf) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    answer = graph[startVertex][finishVertex];
    answer = isPath(answer);
    return answer;
}

// реализация алгоритма Беллмана-Форда [3]
int BellmanFord(int n, int m, vector<vector<int>>& data) {
    int finishVertex; // = n - 1
    int answer;
    finishVertex = n - 1;
    vector<Edge> e;
    int a, b, weight;
    for (int i = 0; i < m; ++i) {
        a = data[i][0];
        b = data[i][1];
        weight = data[i][2];
        Edge curr1 = {a, b, weight};
        e.push_back(curr1);
        Edge curr2 = {b, a, weight};
        e.push_back(curr2);
    }
    vector<int> d(n, kInf);
    d[startVertex] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m * 2; ++j) {
            if (d[e[j].a] < kInf) {
                if (d[e[j].b] > d[e[j].a] + e[j].weight) {
                    d[e[j].b] = max(-kInf, d[e[j].a] + e[j].weight);
                }
            }
        }
    }
    answer = d[finishVertex];
    answer = isPath(answer);
    return answer;
}

// реализация алгоритма поиска A* [4]
int AStar(int n, int m, vector<vector<int>>& data) {
    int finishVertex; // = n - 1
    int answer;
    finishVertex = n - 1;
    answer = kInf;
    set<int> closed;
    vector<vector<pair<int, int>>> graph(n);
    int a, b, weight;
    for (int i = 0; i < m; ++i) {
        a = data[i][0];
        b = data[i][1];
        weight = data[i][2];
        graph[a].push_back(make_pair(b, weight));
        graph[b].push_back(make_pair(a, weight));
    }
    vector<int> d(n, kInf);
    d[startVertex] = 0;
    priority_queue<pair<int, int>> open;
    open.push(make_pair(0, startVertex));
    while (!open.empty()) {
        int v = open.top().second;
        int cur_d = -open.top().first;
        open.pop();
        if (closed.find(v) != closed.end()) {
            continue;
        }
        if (v == finishVertex) {
            answer = cur_d;
            break;
        }
        closed.insert(v);
        for (size_t j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first;
            weight = graph[v][j].second;
            if (d[v] + weight < d[to]) {
                d[to] = d[v] + weight;
                open.push(make_pair(-d[to], to));
            }
        }
    }
    answer = isPath(answer);
    return answer;
}
