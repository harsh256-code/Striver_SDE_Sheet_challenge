class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        int tot = 0,cnt = 0,ans = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!=0)tot++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,1,-1,0};
        while(!q.empty()){
            int k = q.size();
            cnt+=k;
            
            while(k--){
                int x = q.front().first,y = q.front().second;
                q.pop();
                for(int i = 0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx<0 or newy<0 or newx>=n or newy>=m or grid[newx][newy]!=1){
                    continue;
                }
                q.push({newx,newy});
                grid[newx][newy] = 2;
            }
            }
            
            if(!q.empty())ans++;
        }
        
        return tot==cnt?ans:-1;
    }
};
