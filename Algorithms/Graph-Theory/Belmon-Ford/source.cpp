/**
 * @file source.cpp
 * @brief Bellman-Ford Shortest Path Algorithm & Negative Cycle Detection
 * 
 * Computes single-source shortest paths in a directed/undirected graph with positive
 * or negative edge weights, and detects negative-weight cycles reachable from src.
 * 
 * Time Complexity:  O(V * E)
 * Space Complexity: O(V + E)
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define PA pair<int, int>
#define MP(a, b) make_pair(a, b)
#define Max 100000
#define INF (1 << 29)

struct Node {
    int u, v, w;
    Node(int a, int b, int c) {
        u = a; v = b; w = c;
    }
};

vector<Node> G;
int d[Max];

int belmon_ford(int src, int N, int des, int edge) {
    int u, v, w;
    for (int i = 0; i <= N; i++) d[i] = INF;
    d[src] = 0;
    bool Neg_cycle = false;
    bool update;

    for (int step = 1; step <= N; step++) {
        update = false;
        for (int i = 0; i < edge; i++) {
            u = G[i].u; v = G[i].v; w = G[i].w;
            if (d[u] < INF && d[v] > d[u] + w) {
                update = true;
                if (step == N)
                    Neg_cycle = true;
                d[v] = d[u] + w;
            }
        }
        if (!update)
            break;
    }

    if (Neg_cycle) {
        cout << "Negative cycle detected!\n";
        return -1;
    }
    return d[des];
}

int main() {
    int node, edge, u, v, w;
    if (scanf("%d %d", &node, &edge) != 2) return 0;

    G.clear();
    for (int i = 0; i < edge; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G.push_back(Node(u, v, w));
    }

    int src = 1, des = node;
    int ans = belmon_ford(src, node, des, edge);
    if (ans != -1) {
        cout << "Shortest path: " << ans << "\n";
    }

    return 0;
}
