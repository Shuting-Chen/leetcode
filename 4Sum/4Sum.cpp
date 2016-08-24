class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        vector<vector<int>> result;
        vector<int> temp;
        if(nums.size()<4)
        {
            return result;
        }
        std::sort(nums.begin(),nums.end());
        for(int i=0;i< nums.size()-3 ;i++)
        {
            //don't test at the end of the program, but check at the beginning of the program.
            if(i>0 && nums[i]==nums[i-1]) 
            { continue; }
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) //at this place, check at the beginning of the program, not the other place of the program..
                { continue; }
                int start=j+1;
                int end=nums.size()-1;
                //so the i and the j are the two kinds of the nums. 
                while(start<end)
                {
                    if(nums[i]+nums[j]+nums[start]+nums[end]==target)
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        result.push_back(temp);
                        temp.clear();
                        start++;
                        end--;
                        while(start<end && nums[start]==nums[start-1]) //this time check at this part, because they have already do the work, then check 
                        {
                            start++;
                        }
                        while(start<end && nums[end]==nums[end+1])
                        {
                            end--;
                        }
                    }
                    else if(nums[i]+nums[j]+nums[start]+nums[end]<target)
                    {
                        start++;
                    }
                    else if(nums[i]+nums[j]+nums[start]+nums[end]>target)
                    {
                        end--;
                    }
                }
                //according to test code, I can do better I think , make the corporation will test person base on how many test cases have been passed.  
              
               /*
                    while(nums[j]==nums[j-1])
                    {
                        j++;
                    }
                */
            }
            
            /*
                while(nums[i]==nums[i-1])
                { i++; }
            */
        }
       
        return result;
    }
};
