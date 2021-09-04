/* Problem url: https://leetcode.com/problems/sum-of-distances-in-tree
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> res;   
    vector<int> count;
    vector<vector<int>> adj; 
    
    void dfs_1(int node, int parent) {
        for (auto child : adj[node]) {
            if (child != parent) {
                dfs_1(child, node);
                count[node] += count[child]; 
                res[node] += res[child] + count[child];
            }
        }
    }
    void dfs_2(int node, int parent) {
        for (auto child : adj[node]) {
            if (child != parent) {
                res[child] = res[node] - count[child] + res.size() - count[child];
                dfs_2(child, node);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n, 0);
        count.resize(n, 1);
        adj.resize(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs_1(0, -1);
        dfs_2(0, -1); 
        return res;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dfs, tree
 * 
 * */
