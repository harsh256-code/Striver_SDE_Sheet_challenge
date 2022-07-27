string writeAsYouSpeak(int n) 
{
    string ans ="1";
    for(int i=1;i<n;i++){
        string temp ="";
        int c=1;
        for(int j=0;j<ans.size()-1;j++){
            if(ans[j]==ans[j+1]){
                c++;
            }else{
                temp+=(to_string(c)+ans[j]);
                c=1;
            }
        }
        temp+= to_string(c)+ans[ans.size()-1];
        ans=temp;
    }
    return ans;
	// Write your code here.	
}
