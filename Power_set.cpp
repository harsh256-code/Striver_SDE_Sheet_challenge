void generate(int ind,vector<vector<int>>&ans,vector<int>&ds,int n,vector<int>&v){
    if(ind==n){
        ans.push_back(ds);
        return;
    }
    ds.push_back(v[ind]);
    generate(ind+1,ans,ds,n,v);
    ds.pop_back();
    generate(ind+1,ans,ds,n,v);
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<int>ds;
    vector<vector<int>>ans;
    int n = v.size();
    generate(0,ans,ds,n,v);
    return ans;
    //Write your code here
}
vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    int n = s.size();
		    for(int num =0;num<(1<<n);num++){
		        string temp;
		        for(int i=0;i<n;i++){
		            if(num&(1<<i)){
		                temp+=s[i];
		            }
		        }
		        if(temp.size()>0)ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		    // Code here
		}
