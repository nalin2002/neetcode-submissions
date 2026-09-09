/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> dp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(dp.contains(node)) return dp[node];
        
        Node* clone = new Node(node->val);
       
        dp[node]= clone;
        for(int i=0;i<node->neighbors.size();i++){
            Node* clone_neighbor = cloneGraph(node->neighbors[i]);
            clone->neighbors.push_back(clone_neighbor);
        }
        
        return clone;
    }
};
