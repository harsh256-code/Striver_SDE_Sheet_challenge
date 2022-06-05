
//Second Approach Using Two Dummy Arrays 
// Dummy Row and column array will store if the row and column has zero or not
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int>dummyR(n,-1),dummyC(m,-1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] ==0){
                    dummyR[i] = 0;
                    dummyC[j] = 0;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dummyR[i] ==0 or dummyC[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//optmize solution using same matix first row and first column

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        int col0 = 1;
        for(int i = 0;i<n;i++){
            if(matrix[i][0] ==0) col0=0;
            for(int j = 1;j<m;j++){
                if(matrix[i][j] ==0){
                    matrix[0][j] = 0;
                    matrix[i][0] =0;
                }
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=1;j--){
                if(matrix[i][0]==0 or matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 ==0) matrix[i][0]=0;
        }
    }
};
