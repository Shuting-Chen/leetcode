class Solution {
public:
    string longestPalindrome(string s) {
        
        
        //it is a little like sliding window.
        bool table[1000][1000]={false};
        int maxst=0,maxLen=1;
        int n=s.size();
        if(n==0)
        {
            return "";//an empty string.
        }
        
        for(int i=0;i<n-1;i++)
        {
            table[i][i]=true;
            if(s[i]==s[i+1])
            {
                
                table[i][i+1]=true;
                maxLen=2;
                maxst=i;
            }
            
        }
        table[n-1][n-1]=true;
        
        for(int len=3;len<=n;len++) //for each 3 groups, the things should be checked in the for loop..
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1; //then this one must be bigger than the previous one, so 
                if(s[i]==s[j] && table[i+1][j-1]==true)
                {
                    table[i][j]=true;
                    if(len>maxLen)
                    {
                        maxLen=len;
                        maxst=i;
                    }
                }
            }
        }
        return s.substr(maxst,maxLen);
    }
};
