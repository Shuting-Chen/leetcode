class Solution {
public:
   
    string generateSequence(string prev,int n,int step) 
    {
        if(step==n)
        {
            return prev;
        }
        string res="";
        
        char ch=prev[0];
        int chn=1;
        for(int i=1;i<prev.size();i++)
        {
            if(prev[i]==ch)
            {
                chn++;
            }
            else{
                //otherwise, I can put the previous one to the res.
                res.push_back(chn+'0');//use to string to convert int into a string, cause convert a int must be a string,是一个长的，而不是一个短的呢。哎，连最后是什么都模模糊糊的呢。
                res.push_back(ch);
                chn=1;
                ch=prev[i];
            }
        }
        res.push_back(chn+'0');
        res.push_back(ch);
        return generateSequence(res,n,step+1);
    }
    
    string countAndSay(int n) {
        
        if(n==1)
        {   return "1"; }
        return generateSequence("1",n,1);
        
    }
};
