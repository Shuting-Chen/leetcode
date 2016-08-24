class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int div=1;
        int ori=x;
        while(x>=10) //how many digits do I need to divide?
        {
            x/=10; //x=x/10;
            div*=10; //div=div*10;change itself to another number, then use the div*=10
        }
        
        
        
        int left,right;
        
        while(div>=10 )//if the number only have two digits,then I can use this one to do the work.
        {
            left=ori/div;
            right=ori%10;
            if(left!=right) return false;
            ori=(ori%div)/10; //get rid of the first and last digit.
            div/=100;
            
        }
        return true;
    }
};
