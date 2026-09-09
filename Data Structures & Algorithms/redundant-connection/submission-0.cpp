class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    bool unionNodes(int u, int v) {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if (root_u == root_v) return false;

        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for (auto& edge : edges) {
            
            if (!ds.unionNodes(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
