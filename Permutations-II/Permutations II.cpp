class Solution {
public:
    void permuteComb(vector<vector<int>>& res,vector<int>& temp,vector<bool>& used,vector<int>& nums,int step)
    {
        if(step==nums.size())
        {
            res.push_back(temp);
            return;
        }
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
            {
                continue;
            }
            else
            {
                if(nums[i]==prev)
                {
                    continue;
                }
                else{
                    used[i]=true;
                    temp.push_back(nums[i]);
                    permuteComb(res,temp,used,nums,step+1);
                    temp.pop_back();
                    used[i]=false;
                    prev=nums[i];
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        permuteComb(res,temp,used,nums,0);
        return res;
    }
};
