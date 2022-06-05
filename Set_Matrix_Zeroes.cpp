
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
