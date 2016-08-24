class Solution {
public:
    bool isValid(string s) {
        //All the coding questions are different, I cannot rely on memory.
        stack<char> sta;
        //I can use a vector, but here I want to use wa stack.vector:...back();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                sta.push(s[i]);
                continue;
            }
            
            int n=sta.size();
            if(n==0) return false;
            
            char cur=sta.top();
            
            if(s[i]==')')
            {
                if(cur!='(')
                {   return false;  }
            }
            
            if(s[i]=='}')
            {
                if(cur!='{')
                {   return false;  }
            }
            
            if(s[i]==']')
            {
                if(cur!='[')
                {   return false;  }
            }
            sta.pop();
        }
        if(!sta.empty()) return false;
        return true;
    }
};
