class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='{' or it=='[' or it=='(') st.push(it);
            else {
                if(st.size()==0)return 0;
                char c = st.top();
                st.pop();
                if((c=='{' and it=='}') or (c=='[' and it==']') or (c=='(' and it==')')) {
                    continue;
                }else return false;
        }
        }
             return st.empty();
    }
       
};
