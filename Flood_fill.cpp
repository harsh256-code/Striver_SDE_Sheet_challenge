#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    
    queue<pair<int,int>>q;
    int n = image.size(),m= image[0].size();
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};
    q.push({x,y});
    int col = image[x][y];
    if(col==newColor)return image;
    image[x][y] = newColor;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        //image[x][y] = newColor;
        for(int i =0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 and newy>=0 and newx<n and newy<m and image[newx][newy]==col){
                image[newx][newy] = newColor;
                q.push({newx,newy});
            }
        }
 
    }
    return image;
    // Write your code here.
}
