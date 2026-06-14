class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>>ans;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                for(int k = j+1; k<n; k++)
                {
                    for(int p = k+1;p<n; p++)
                    {
                        long sum = (long) nums[i] + nums[j] + nums[k] + nums[p];

                        if(sum == target)
                        {
                            vector<int>temp {nums[i] , nums[j] , nums[k] , nums[p]};
                            sort(temp.begin() , temp.end());

                            ans.insert(temp);
                        }
                    }
                }
                    
                
            }
        }
        return vector<vector<int>>(ans.begin() , ans.end());
    }
};
