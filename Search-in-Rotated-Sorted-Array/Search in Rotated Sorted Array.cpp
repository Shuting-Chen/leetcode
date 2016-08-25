class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0) return -1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]==target)
            {
                return m;//after return it, there is no use to do any more things. 
            }
            if(nums[l]<=nums[m])//this part is sorted
            {
                if(target >=nums[l] && target <=nums[m] ) 
                {
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else 
            {
                if(target>=nums[m] && target<=nums[r])
                {
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
           
        }
        return -1;
    }
};
