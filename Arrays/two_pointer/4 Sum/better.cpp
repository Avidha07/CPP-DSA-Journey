class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n = nums.size();

        for(int i =0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                unordered_set<int>seen;

                for(int k = j+1; k<n; k++)
                {
                    long long required = (long long) target - nums[i] -nums[j] - nums[k];

                    if( required >= INT_MIN &&
   required <= INT_MAX && seen.count(required)) {
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , (int)required};
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                    }

                    seen.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(st.begin() , st.end());
    }
};
