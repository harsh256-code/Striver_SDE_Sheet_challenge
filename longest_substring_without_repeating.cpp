class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int maxi =0;
        int l = 0;
        for(int r =0;r<s.size();r++){
            if(st.find(s[r])!=st.end()){
                while(l<r and st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                    
                }
                
            }
            st.insert(s[r]);
            maxi = max(maxi ,r-l+1);
        }
        return maxi;
    }
};
