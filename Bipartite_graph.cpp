class Solution {
public:
    bool dfs(vector<int>&color,int node,vector<vector<int>>&graph){
        for(auto it:graph[node]){
            if(color[it]==-1){
                color[it] = 1-color[node];
                if(!dfs(color,it,graph))return false;
            }else if(color[it]==color[node])return false;
        }
        return true;
    }
    bool bfs(vector<int>&color,int node,vector<vector<int>>&graph){
        color[node] = 1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto it:graph[i]){
                if(color[it]==-1){
                    color[it] = 1-color[i];
                    q.push(it);
                }else if(color[it]==color[i])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(color,i,graph))return false;
            }
        }
        return true;
    }
};
