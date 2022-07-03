class Solution {
public:
    int myAtoi(string s) {
        int ans =0;
        int n = s.size(),i=0;
        while(i<n and s[i]==' ')i++;
        int sign = 1;
        if(s[i]=='+' or s[i]=='-'){
            if(s[i]=='-')sign = -1;
            i++;
        }
        while(i<n and s[i]>='0' and s[i]<='9'){
            int no = s[i]-'0';
            if(ans>INT_MAX/10 or (ans*10 >INT_MAX-no)){
                return sign==1?INT_MAX:INT_MIN;
            }
            ans = ans*10 +no;
            i++;
        }
        return ans*sign;
        
    }
};
