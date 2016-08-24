class Solution {
public:
    int reverse(int x) {
     
        
        //first I can reverse the integer, if it is bigger than the previous one, then I can use 0 to do it. 
        
        long long res=0;
        bool isPositive=x>0? true:false; 
        x=abs(x);
        while(x>0)
        {
            res=res*10+x%10;
            x=x/10; 
        }
        if(res > INT_MAX)
        {
            return 0;
        }
        return isPositive? res:res*(-1);
    }
};
