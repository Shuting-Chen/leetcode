class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> mapping;
        for(int i=0;i<nums.size();i++) 
        {
            mapping[nums[i]]=i; //give the values to the 
        }
        
        for(int i=0;i<nums.size();i++)  
        {
            int searched=target-nums[i]; 
         
            if( mapping[searched]!=NULL ) 
            {
                result.push_back(i+1);
                for(int j=0;j<nums.size();j++)
                {
                    if(nums[j]==searched && j!=i)
                    {  result.push_back(j+1); break; }
                
                }
                break; 
            }
        }
        return result;
    }
   
    
}; 
