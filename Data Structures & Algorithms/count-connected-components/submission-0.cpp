class DisjointSet{
    vector<int> parent,rank;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findParent(int n){
            if(n==parent[n]) return n;
            return parent[n]= findParent(parent[n]);
        }
        void union_nodes(int u,int v){
            int p_u= findParent(u);
            int p_v= findParent(v);
            
            if(rank[p_u]<rank[p_v]){
                parent[p_u]= p_v;
            }
            else if(rank[p_u]>rank[p_v]){
                parent[p_v]=p_u;
            }
            else{
                parent[p_v]=p_u;
                rank[p_u]++;
            }
        }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto& x: edges){
            ds.union_nodes(x[0],x[1]);
        }
        unordered_set<int> mp;

        for(int i=0;i<n;i++){
            mp.insert(ds.findParent(i));
        }
        return mp.size();

    }
};
