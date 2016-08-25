class Solution {
public:
    int strStr(string haystack, string needle) {
        //this time I think I can use backtracking to do this one, 
        int size1=haystack.size();
        int size2=needle.size();
        if(size2>size1) return -1;
        if(size2==0) return 0;
        for(int i=0;i<size1-size2+1;i++)
        {
            for(int j=0;j<size2;j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    break;//this i is not valid
                }
                else if(j==size2-1)
                {
                    return i;//just find the first, if I can use this, then it is valid.
                }
            }
        }
        return -1;
    }
};
