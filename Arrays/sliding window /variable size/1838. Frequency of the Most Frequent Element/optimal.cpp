class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans =1;
        long long sum =0;

        int i =0; int  j =0;
        while(j<n)
        {
            sum += nums[j];

            //long long required = 1LL*nums[j]*(j-i+1) - sum ; ye bhi use kar sakte h 

            while(1LL*nums[j]*(j-i+1) - sum > k)
            {
                sum = sum-nums[i];
                i++;
            }
            
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};
