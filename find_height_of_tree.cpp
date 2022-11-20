class Solution {
public:
    long long ans  = 0,s;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>>graph(roads.size()+1);
        for(auto it:roads){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        s = seats;
        dfs(0,0,graph);
        return ans;
    }
    int dfs(int i,int prev,vector<vector<int>>&graph,int people = 1){
        for(auto it:graph[i]){
            if(prev==it)continue;
            people+= dfs(it,i,graph);
        }
        if(i!=0)ans+=(people+s-1)/s;
        return people;
    }
};
