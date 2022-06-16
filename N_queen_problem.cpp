class Solution {
    private:
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, vector<int>&leftRow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal,int n){
        if(col ==n){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i<n;i++){
            if(!leftRow[i] and !upperDiagonal[n-1+col-i] and !lowerDiagonal[i+col]){
                leftRow[i] = 1;
                upperDiagonal[n-1+col-i] = 1;
                lowerDiagonal[i+col] = 1;
                board[i][col] = 'Q';
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                leftRow[i] = 0;
                upperDiagonal[n-1+col-i] = 0;
                lowerDiagonal[i+col] = 0;
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++){
            board[i] =s;
        }
        vector<int>leftRow(n,0),upperDiagonal(2*n -1),lowerDiagonal(2*n-1);
        solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
        return ans;
        
    }
};
