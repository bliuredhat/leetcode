/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-15 11:17:36
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-16 12:38:43
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
/*
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
*/


/*
松弛法（relaxation）是一数学术语，描述的是一些求解方法，这些方法会通过逐步接近的方式获得相关问题的最佳解法。
每运用一次松弛法就好像我们“移动”了一次，而我们要做的就是在尽可能少的移动次数内找到最佳解决方案。
*/
//bellman-ford算法
struct Edge
{
    int s;
    int d;
    int weight;
};

class Graph {
public:
    int V, E;
    std::vector<Edge> edges;

    Graph(int v, int e) : V(v), E(e) {}
    
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }
};
std::vector<int> BellmanFord(Graph& graph, int start) {
     int V = graph.V; //顶点个数；
    int E = graph.E;  //边的个数；
    std::vector<int> dist(graph.V, INT_MAX);
    dist[start] = 0;
    for (int i=0; i < graph.V-1; i++) {
        for (int j=0; j<graph.E; j++) {
            int s = graph.edges[j].s;
            int d = graph.edges[j].d;
            int weight = graph.edges[j].weight;
            if (dist[s] != INT_MAX && dist[d] > (dist[s] + weight)) {
                dist[d] = dist[s] + weight;
            }
        }
    }
    // 检查负权环
    for (int i = 0; i < E; i++) {
        int u = graph.edges[i].s;
        int v = graph.edges[i].d;
        int weight = graph.edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            std::cout << "图中存在负权环！" << std::endl;
            break;
        }
    }
    return dist;
}

int main() {
    int V = 5; // 顶点数
    int E = 8; // 边数
    Graph graph(V, E);

    // 添加边
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    auto res = BellmanFord(graph, 0);
    for (auto& val : res ) {
        std::cout <<" , " << val; 
    }
    return 0;
}
