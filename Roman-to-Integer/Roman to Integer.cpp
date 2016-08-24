class Solution {
public:
    int romanToInt(string s) {
        //roman to int is easier than int to roman, then I can use the thigns to get the work done.
        //Arabic numbers are the the numbers which can convert to the digits,then I can do the work better.
        //string dict[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        //int nums[]={1000,900,500,400,100,90,50,40,10,9,5,4,1);
        
        int res=0;
        char prev=' ';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='M' && prev!='C') { res+=1000;}
            if(s[i]=='C' && prev!='X') { res+=100;}
            if(s[i]=='X' && prev!='I') { res+=10;}
            //cause it has already deal with the previous one, so the only thing that I need to do is to..
            if(s[i]=='M' && prev=='C') { res+=800;} //900->800
            if(s[i]=='C' && prev=='X') { res+=80;}  //90->80
            if(s[i]=='X' && prev=='I') { res+=8;}  //9->8
            
            if(s[i]=='D' && prev!='C') { res+=500;} //both of them are c,x,i, no matter how big it is, then I can use it to do the work.
            if(s[i]=='L' && prev!='X') { res+=50;}
            if(s[i]=='V' && prev!='I') { res+=5;}
            
            if(s[i]=='D' && prev=='C') { res+=300;} //100->80.500->300
            if(s[i]=='L' && prev=='X') { res+=30;}
            if(s[i]=='V' && prev=='I') { res+=3;}
            
            if(s[i]=='I') { res+=1;}
            
            prev=s[i];
        }
            //also can use this kind of {} to give the values to them.
        return res;   
            //c is 100,but as long as others get a c in the prevous 1000->900 100->90, but if there is a x before c, the get to 90, l is 50, then xl is 40  below 100, x is before something then 5 become 4,,below 10, if I is before the others, then 5 become 4..
        //give a string array,, an array of strings, so it can be declare like this one.
        
    }
};
