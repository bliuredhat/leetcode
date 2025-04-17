/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-17 11:01:22
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-17 12:10:09
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//Khan 算法
std::vector<int> topologicalSortKahn(std::vector<std::vector<int>>& graph) {
    std::vector<int> res;
    int size = graph.size();
    std::vector<int> inDegree(size, 0);
    std::queue<int> que;
    for (auto& v : graph) {
        for (auto& u : v) {
            inDegree[u] ++;
        }
    }
    for (int idx=0; idx < size; idx++) {
        if (inDegree[idx] == 0) {
            que.push(idx);
        }
    }
    while(!que.empty()) {
        int val = que.front();
        que.pop();
        res.push_back(val); 
        for (auto& u : graph[val]) {
            inDegree[u]--;
            if (inDegree[u] == 0) {
                que.push(u);
            }
        }
    }
    if (res.size() != size) {
        std::cout << "存在环，不能排序。" <<std::endl;
        return {};
    }
    return res;
}

void DFS(std::vector<std::vector<int>>& graph, int u, std::vector<bool>&visited, 
                        std::stack<int>& stk) {
    visited[u] = true;
    for (auto& v : graph[u]) {
        if (!visited[v]) {
            DFS(graph, v, visited, stk);
        }
    }
    stk.push(u);
}

std::vector<int> topologicalSortDFS(std::vector<std::vector<int>>& graph) {
    std::vector<int> res;
    std::stack<int> stk;
    int size = graph.size();
    std::vector<bool> visited(size, false);
    for (int idx=0; idx < size; idx++) {
        if (!visited[idx]) {
            DFS(graph, idx, visited, stk);
        }
    }

    while(!stk.empty()) {
        auto val = stk.top();
        res.push_back(val);
        stk.pop();
    }
    return res;
}

int main() {
    int n = 6;
    std::vector<std::vector<int>> graph(n);
    // 构建图：5 → 0 ← 4
    //         ↓       ↓
    //         2 → 3 → 1
    graph[5] = {0, 2};
    graph[4] = {0, 1};
    graph[2] = {3};
    graph[3] = {1};
    graph[0] = {};
    graph[1] = {};
    
    vector<int> sorted = topologicalSortKahn(graph);
    
    if (sorted.empty()) {
        cout << "图中存在环，无法拓扑排序" << endl;
    } else {
        cout << "拓扑排序结果: ";
        for (int node : sorted) {
            cout << node << " ";
        }
        cout << endl;
    }

    auto vec = topologicalSortDFS(graph);
    cout << "DFS拓扑排序结果: ";
    for (int node : vec) {
        cout << node << " ";
    } 
    
    return 0;
}