class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int total = 0;
        int currMax = 0;
        int maxSum = INT_MIN;
        int currMin = 0;
        int minSum = INT_MAX;
        int circular_max = INT_MIN;


        for(int i =0; i<n; i++)
        {
          
          currMax = max(nums[i] , currMax + nums[i]);
          maxSum = max(currMax , maxSum);

          currMin = min(nums[i] , currMin+nums[i]);
          minSum = min(currMin , minSum);

          total += nums[i];
          

         
        }
    if(maxSum < 0)
    {
        return maxSum;
    }
    circular_max = total - minSum;
    return max(maxSum , circular_max);
        
    }
};
