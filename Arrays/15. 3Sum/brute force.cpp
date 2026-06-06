class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>>ans;
        int n = nums.size();

        for(int i =0; i<n; i++)
        {    
            for(int j = i+1; j<n; j++)
            {
                for(int k = j+1; k<n; k++)
                {   

                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0)
                    {  
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);

                        sort(v.begin(),v.end());
                        ans.insert(v); 
                    }
                    
                }
            }
  
        }
        for(auto it : ans)
        {
           res.push_back(it);
        }

        return res;

    }
};
