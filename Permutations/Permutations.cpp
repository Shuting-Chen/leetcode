class Solution {
public:
    void permuteComb(vector<vector<int>>& res,vector<int>& temp,vector<bool>& used,vector<int>& nums,int step)
    {
        if(step==nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
            {
                continue;
            }
            else{
                used[i]=true;
                temp.push_back(nums[i]);
                permuteComb(res,temp,used,nums,step+1);
                temp.pop_back();
                used[i]=false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        //这个是permutation，减少了判断的问题呢好吧。
        permuteComb(res,temp,used,nums,0);
        return res;
    }
};
