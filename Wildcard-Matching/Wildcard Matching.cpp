class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        if(m==0 && n==0) return true;
        /*
        if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                if(p[i]!='*') return false;
                
            }
            return true;
        }
        */
        if(n==0) return false;
      
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false)); //how to define a vector? First is m+1, then vector<bool>(n+1,false)
        dp[0][0]=true;
        for(int i=0;i<=m;i++) 
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    if(dp[i][j-1]||(i>0 && dp[i-1][j])||(i>0 &&dp[i-1][j-1]))
                    {
                        dp[i][j]=true;
                    }
                }
                else
                {   
                    if(i>0)
                    {
                        if(p[j-1]=='?')
                        {
                            if(dp[i-1][j-1]) 
                            {
                                dp[i][j]=true;
                            }
                        }
                        else
                        {
                            if(s[i-1]==p[j-1]&& dp[i-1][j-1])
                            {
                                dp[i][j]=true;
                            }
                        }
                    }
                }
            }
        }
        if (dp[m][n])
        {
            return true;
        }
        else return false;
    }
};
