class Solution {
public:
    void getComb(vector<vector<int>>& res,vector<int>& temp,vector<int>& candidates, int target,int idx)
    {
        //everyone can be only used on
        
         if(target==0)
        {
            res.push_back(temp);
            return;
        }
        else if(target<0)
        {
            return;
        }
        else
        {   
            int prev=-1;
            for(int i=idx;i<candidates.size();i++)
            {
                if(candidates[i]==prev)
                {
                    continue;
                }
                target-=candidates[i];
                temp.push_back(candidates[i]);
                getComb(res,temp,candidates,target,i+1);
                temp.pop_back();
                target+=candidates[i];
                prev=candidates[i];
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        getComb(res,temp,candidates,target,0);
        return res;
    }
};
