class Solution {
public:
    
    int findLeftMost(vector<int>& nums, int target)
    {   
        int l=0,r=nums.size()-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target<nums[mid])
            {
                r=mid-1;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(l>=0 && l<=nums.size()-1 && nums[l]==target)//even the things are finished it doesn't mean it cannot be finished,
        {   return l;   }
        return -1;
    }
    
    int findRightMost(vector<int>& nums, int target)
    {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target<nums[mid])
            {
                r=mid-1;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else{
                l=mid+1;
            }
        }
        if(r>=0 && r<=nums.size()-1 && nums[r]==target)
        {   return r;   }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        vector<int> res;
        res.push_back(findLeftMost(nums,target));
        res.push_back(findRightMost(nums,target));
        return res;
    }
};
