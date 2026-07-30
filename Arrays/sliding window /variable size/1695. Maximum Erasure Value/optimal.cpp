class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0; int j =0;
        int maxiSum = 0;
        int sum = 0;
        unordered_set<int>st;

        while(j<n)
        {
            

             while(st.find(nums[j]) != st.end())
             {
                 sum = sum - nums[i];
                 st.erase(nums[i]);
                 i++;
             }

             st.insert(nums[j]);
             sum+= nums[j];

             maxiSum = max(maxiSum , sum);
             j++;
        }

        return maxiSum;


    }
};
