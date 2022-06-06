class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            
        }
        for(int i=0;i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
    }
};

//if matrix is not square
#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top = 0,down = n-1,left = 0,right = m-1;
    if(down ==0 and right == 0)return;
    while(top<down and left<right){
        int temp = mat[top][top];
        for(int i = left+1;i<=right;i++){
            swap(temp,mat[top][i]);
        }
        for(int i =top+1;i<=down;i++){
            swap(temp,mat[i][right]);
        }
        for(int i = right-1;i>=left;i--){
            swap(temp,mat[down][i]);
        }
        for(int i = down-1;i>=top;i--){
            swap(temp,mat[i][left]);
        }
        top++;down--;
        left++;right--;
    }
    
    // Write your code here

}
