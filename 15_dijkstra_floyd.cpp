/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-15 11:17:36
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-15 17:15:16
 * @Description: 
 */
#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>

int INF = INT_MAX;

std::vector<int> Dijkstra(std::vector<std::vector<int> > graph, int start) {
    std::vector<int> res;
    int size = graph.size();
    std::vector<int> dist(size, INT_MAX);
    dist[start] = 0;
    std::vector<bool> visited(size, false);
    visited[start] = true;
    std::vector<int> pre(size, -1);
    for(int idx=0; idx < size; idx++) {
        dist[idx] = graph[start][idx];
        pre[idx] = start;
    }
    for (int idx=0; idx < size; idx++) {
        int tmp_dist = INT_MAX;
        int tmpIdx;
        for (int sub=0; sub < size; sub++) {
            if (!visited[sub] && dist[sub] < tmp_dist) {
                tmp_dist = dist[sub];
                tmpIdx = sub;
            }
        }
        std::cout << "idx: " << tmpIdx << " val: " << tmp_dist<<std::endl;
        visited[tmpIdx] = true;
        for (int sub=0; sub<size; sub++) {
            if (!visited[sub]) {
                
                if (graph[tmpIdx][sub] == INT_MAX && dist[sub] == INT_MAX) {
                    continue;
                }
                if ((graph[tmpIdx][sub] + tmp_dist - INT_MAX) > 0) {
                    continue;
                } 
                
                if (dist[sub] >  (graph[tmpIdx][sub] + tmp_dist)) {
                    dist[sub] = graph[tmpIdx][sub] + tmp_dist;
                    pre[sub] = tmpIdx;  
                }
            }
        }
    }
    return dist;
}

std::vector<std::vector<int>> floyd(std::vector<std::vector<int>> graph) {
    int size = graph.size();
    std::vector<std::vector<int>> res(size, std::vector<int>(size, INT_MAX));
    std::vector<std::vector<int>> path(size, std::vector<int>(size, -1));
    for (int i = 0; i < size; i++) {
        res[i][i] = 0;
        for (int j = 0; j < size; j++) {
            if (i != j) {
                res[i][j] = graph[i][j];
            }
        }
    }
    for(int idx1 = 0; idx1<size; idx1++) {
        for (int idx2=0; idx2<size ; idx2++) {
            for (int idx3=0; idx3<size; idx3++) {
                if(res[idx2][idx3] > res[idx1][idx3] + res[idx2][idx1]) {
                    res[idx2][idx3] = res[idx2][idx1] + res[idx1][idx3];
                    path[idx2][idx3] = idx1;
                }
            }
        }
    }
    return res;
}


int main() {
    std::vector<std::vector<int>> graph = {
			{0, 6, INF, 1, INF}, //不直接相连的点距离就是无穷大
			{6, 0, 5, 2, 2},
			{INF, 5, 0, 5, INF},
			{1, 2, INF, 0, 1},
			{INF, 2, 5, 1, 0},
		};
    auto res = Dijkstra(graph, 0); 
    for (auto val : res) {
        std::cout << " , " << val;
    }

    return 1;
}

