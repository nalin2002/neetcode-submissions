class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findParent(parent[n]);
    }

    bool union_nodes(int u, int v) {
        int p_u = findParent(u);
        int p_v = findParent(v);
        
        // If roots match, a cycle is detected
        if (p_u == p_v) return false;

        if (rank[p_u] < rank[p_v]) {
            parent[p_u] = p_v;
        } else if (rank[p_u] > rank[p_v]) {
            parent[p_v] = p_u;
        } else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        DisjointSet ds(n);
        for(auto& edge:edges){
            if( !ds.union_nodes(edge[0],edge[1])){
                return false;
            }
        }
        return true;

    }
};
