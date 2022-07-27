bool areAnagram(string &str1, string &str2){
    int hash[26] ={0};
    for(auto it:str1){
        hash[it-'a']++;
    }
    for(auto it:str2){
        hash[it-'a']--;
    }
    for(int i=0;i<26;i++){
        if(hash[i]!=0)return 0;
    }
    return 1;
    // Write your code here.
}
