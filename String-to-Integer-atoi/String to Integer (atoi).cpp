class Solution {
public:
    int myAtoi(string str) {
       // if(str==NULL)
        if(str.empty())
        {
            return 0;
        }
        int i=0;
        while(str[i]==' ')//just a whitespace, 
        {
            i++;
        }
        
        bool sign=true;
        //int sign=str[i]=='-'?1:-1;//give value to the number sign, then get 1 or -1.
        //use ? : to do the work, then assign the value to a new variable. 
        int res=0;
        if(str[i]=='-')//first check the sign and use all the posible number to do the compare work.
        {
            sign=false;
            i++;
        }
        else if(str[i]=='+') //after it, just use i++ or not.
        {
            sign=true;
            i++;
        }
        while(isdigit(str[i]))//to parse all of the digits to add them together. 
        {
            //everytime when I add a new digit, check 
            int digit=str[i]-'0';//Add every digit when I want to add a new digit, then I need to make sure everytime if it 
            //exceed the maximum number, 
            
            if(res*10<=INT_MAX)//first check if the result has already exceeded the maxmum value. 
            {
                res*=10;
            }
            else if(res*10>INT_MAX)
            {
                //if it is just a simple if-else clause,I can use just one sentence to ..
                return (sign==true)? INT_MAX: INT_MIN; //when I need to return I need to know if it is positive or negative. 
            }
            
            if((res+digit)<=INT_MAX) 
            {
                res+=digit;
            }
            
            else if((res+digit)>INT_MAX)
            {
                return (sign==true)? INT_MAX: INT_MIN;
            }
            i++;
            
        }
        
        //I use true or false, so it is just a judging condition. 
        return sign==true?res:res*(-1);
    }
};
