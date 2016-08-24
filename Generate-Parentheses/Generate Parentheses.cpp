class Solution {
public:
    
    void generate(vector<string>& res,string& temp,int n,int left, int right)
    {
        //right one cannot go beyond the left one
        if(right==n && left==n)
        {
            res.push_back(temp);
            return;
        }
        
        if(left<n)//these two add together is one layer
        {
            temp.push_back('(');
            generate(res,temp,n,left+1,right);
            temp.pop_back();
        }
        if(right<left)
        {
            temp.push_back(')');
            generate(res,temp,n,left,right+1);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
       
        //but the generation also have a lot of 
        vector<string> res;
        if(n==0) return res;
        string temp;
        generate(res,temp,n,0,0);
        return res;
    }
};
