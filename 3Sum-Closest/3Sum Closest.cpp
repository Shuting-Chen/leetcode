class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        std::sort(nums.begin(),nums.end());
        int minDiff=abs(nums[0]+nums[1]+nums[2]-target);
        
        if(nums.size()<3)
        {
            return INT_MAX;
        }
       
        res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                int diff=nums[i]+nums[left]+nums[right]-target;
                if(abs(diff)<abs(minDiff))
                {
                    minDiff=diff;  //this is to do the right work..
                    res=nums[i]+nums[left]+nums[right];
                }
                if( diff == 0 )
                { return res; }
                else if( diff < 0 )
                {  left++; }
                else 
                {  right--; }  //let the result to approach the right result everytime.
                   //no need to get rid of the duplicate thing, there is just 2 pointer scan, so adding can use the 2 pointer scan, then after sort use 2 pointer scan I can get the right sum of an array..
            }
            
        }
        return res;
    }
};
