class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
       
        if(s.size()==0) return 0;
        
        unordered_map<char,int> mp;
        mp[s[0]]=0;
        int maxLen=1;
        
        int start=0;
        int i;
        for(i=1;i<s.size();i++)
        {
            if(mp.count(s[i]))
            {
                maxLen=max(maxLen,i-start);
                for(int j=start;j<mp[s[i]];j++)
                {
                    mp.erase(s[j]);
                }
                //the old start and i.
                start=mp[s[i]]+1;
                mp[s[i]]=i;
                
            }
            else{
                mp[s[i]]=i;
                
                
            }
        }
       
        maxLen=max(maxLen,i-start);
        return maxLen;
        
    }
};
