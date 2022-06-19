void words(string &s,int start,vector<string>&dictionary,vector<string>&ans,string curr){
    if(start>=s.size()){
        ans.push_back(curr);
        return;
    }
    for(int i = start;i<s.size();i++){
        string temp = s.substr(start,i-start+1);
        
        bool flag = false;
        for(string st: dictionary){
            if(st.compare(temp)==0){
                flag = true;
                break;
            }
        }
        if(flag){
            string x = curr;
            curr+=temp+" ";
            words(s,i+1,dictionary,ans,curr);
            
            curr = x;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>ans;
    string curr;
    words(s,0,dictionary,ans,curr);
    return ans;
    // Write your code here

}
