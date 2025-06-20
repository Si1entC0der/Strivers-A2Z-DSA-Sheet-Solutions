class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &it: edges) 
            adj[it[0]].push_back(it[1]), adj[it[1]].push_back(it[0]);

        vector <bool> vis(n,0);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i,adj,vis);
            }
        } 
        return cnt;
    }
private:
    void bfs(int start,vector<vector<int>> &adj,vector<bool> &vis) {
        queue <int> q;
        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &it : adj[node]) {
                if(!vis[it])
                    vis[it] = true, q.push(it); 
            } 
        }

    }
};
