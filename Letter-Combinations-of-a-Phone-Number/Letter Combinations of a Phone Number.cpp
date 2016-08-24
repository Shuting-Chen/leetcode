class Solution {
public:

    void findCombinations(int step,int n,vector<string>& res,string& temp,string& digits,string dicts[])
    {
        
        if(step==n)
        {
            res.push_back(temp);
            return;
        }
        string letters=dicts[(digits[step]-'0')-1];
        for(int i=0;i<letters.size();i++)
        {
            temp[step]=letters[i];
            findCombinations(step+1,n,res,temp,digits,dicts);
        }
       
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp(digits.size(),'2');
        int n=digits.size();
        if(n==0) return res;
        string dicts[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        //in this case just give a string, cause there is no push_back operation just a simple array to be refered.
        findCombinations(0,n,res,temp,digits,dicts);
        return res;
    }
};
