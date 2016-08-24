class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //if this one can give the all of the solutions, use the two pointers not the recursion.
        
        
        
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return result;
        for(int i=0;i<nums.size()-2;i++)
        {
            //firstly I need to have a target, then secondly, I can have more things than I can have.
            if(nums[i]>0) break;
            int target=0-nums[i];
            int left=i+1;//i is also a index, so use i+1 to do the work.
            int right=nums.size()-1;
            while(left<right) //if left is bigger than right, it wont work.
            {
                if(nums[left]+nums[right]<target)
                left++;
                else if(nums[left]+nums[right]>target)
                right--;
                else if(nums[left]+nums[right]==target)
                {
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                    {
                        left++;
                    }
                    right--;//cause the previous one has been used.
                    while(left<right && nums[right]==nums[right+1])
                    {
                        right--;
                    }
                }
                
            }
            while(nums[i]==nums[i+1] && i<nums.size()-3)//this part is very important,这道题刷掉了很多没用的信息。这样大大的方便了原来的题目意思。
            {
                i++;
            }
        }
        return result;
    }
};
