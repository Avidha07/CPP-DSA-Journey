class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans =1;

        for(int i =0; i<n; i++)
        {
             long long operation = 0;
             int freq = 1;

             for(int j = i-1; j>=0; j--)
             {
                operation += (nums[i] - nums[j]);

                if(operation <= k)
                {
                    freq++;
                }
                else{
                    break;
                }
             }
             ans = max(ans , freq);
        }

        return ans;
    }
};
## time limit exceeded
