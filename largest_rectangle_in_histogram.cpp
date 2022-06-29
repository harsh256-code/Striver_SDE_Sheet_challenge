class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        int n = heights.size();
        stack<int>s;
        for(int i = 0;i<=n;i++){
            while(!s.empty() and (i==n or heights[s.top()]>=heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty())width = i;
                else {
                    width = i-s.top()-1;
                }
                maxi = max(maxi,h*width);
            }
            s.push(i);
        }
        return maxi;
        
    }
}; 
