class Solution {
    private:
    void solve(int ind, int target,vector<int>&c,vector<vector<int>>&ans,vector<int>&ds){
        if(ind == c.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }
        if(c[ind]<=target){
            ds.push_back(c[ind]);
            solve(ind,target-c[ind],c,ans,ds);
            ds.pop_back();
        }
        solve(ind+1,target,c,ans,ds);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,c,ans,ds);
        return ans;
    }
};
