#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

class DSU {
    std::vector<int> parent;
public:
    DSU(int n) : parent(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        std::vector<std::vector<int>> edges;

        // 1. Generate all possible edges: O(n^2)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = std::abs(points[i][0] - points[j][0]) + 
                           std::abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        // 2. Sort edges by distance: O(n^2 log(n^2)) = O(n^2 log n)
        std::sort(edges.begin(), edges.end());

        // 3. Kruskal's Algorithm via DSU
        DSU dsu(n);
        int total_cost = 0;
        int edges_count = 0;

        for (const auto& edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (dsu.unite(u, v)) {
                total_cost += weight;
                edges_count++;
                if (edges_count == n - 1) break; // MST complete
            }
        }

        return total_cost;

    }
};
