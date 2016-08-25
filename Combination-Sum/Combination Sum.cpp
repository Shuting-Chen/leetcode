class Solution {
public:
    void getComb(vector<vector<int>>& res,vector<int>& temp,vector<int>& candidates, int target,int idx)
    {
        
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
            for(int i=idx;i<candidates.size();i++) 
            {   
                target=target-candidates[i];
                temp.push_back(candidates[i]);
                getComb(res,temp,candidates,target,i); 
                temp.pop_back();
                target=target+candidates[i];
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> temp;
        if(candidates.size()==0)
        {
            return res;
        }
        
        getComb(res,temp,candidates,target,0);
        return res;
    }
};
