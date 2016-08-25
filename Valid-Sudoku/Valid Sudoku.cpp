class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(board.size()!=9||board[0].size()!=9)
        return false;
        
        for(int i=0;i<9;i++)//for every row,i是行number,j是列number
        {
            vector<bool> used(9,false);
            for(int j=0;j<9;j++)
            {
                if(!isdigit(board[i][j])) {  continue;  }
                int k=board[i][j]-'0';
                if(used[k-1])
                {
                    return false;
                }
                used[k-1]=true;
            }
        }
        
        for(int j=0;j<9;j++)
        {
            vector<bool> used(9,false); 
            for(int i=0;i<9;i++)
            {
                if(!isdigit(board[i][j])) {  continue;  }
                int k=board[i][j]-'0';
                if(used[k-1])
                {
                    return false;
                }
                used[k-1]=true;
            }
        }
        
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int row=i*3;
                int col=j*3;
                vector<bool> used(9,false); //a new field.
                for(int m=row;m<row+3;m++)
                {
                    for(int n=col;n<col+3;n++)
                    {
                        if(!isdigit(board[m][n])) {  continue;  }
                        int k=board[m][n]-'0';
                        if(used[k-1])
                        {
                            return false;
                        }
                        used[k-1]=true;
                    }
                }
            }
        }
        
        return true;
    }
};
