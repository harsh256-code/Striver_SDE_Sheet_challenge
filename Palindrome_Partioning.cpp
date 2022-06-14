class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0,s,ans,ds);
        return ans;
    }
    void solve(int ind, string &s,vector<vector<string>>&ans, vector<string>&ds){
        if(ind == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int low,int high){
        while(low<=high){
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
};
