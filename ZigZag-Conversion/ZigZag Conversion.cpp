class Solution {
public:
    string convert(string s, int numRows) {
        int i=0;
        string res;
        vector<vector<char>> result(numRows);
        /*
        for(int a=0;a<numRows;a++)
        {
            result.push_back(vector<char>()); //for every row, push_back a vector,,
        }
        */
        while(i<s.size())
        {
            for(int j=0;j<numRows && i<s.size();j++,i++)
            {
                result[j].push_back(s[i]);
                
            }
            
            for(int j=numRows-2;j>=1 && i<s.size();j--,i++)
            {
                result[j].push_back(s[i]);
            }
        }
        
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<result[i].size();j++) 
            {
               //res=res+table[i][j];
               res.push_back(result[i][j]);
            }
        }
        
        return res;
    }
};
