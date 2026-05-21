class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxi = nums[0];
        int sum =0;

        for(int i =0; i<nums.size(); i++){
            sum = 0;
            for(int j = i; j<nums.size(); j++)
            {
                sum += nums[j];

                maxi = max(sum , maxi);
            }
        }
        return maxi;

        
    }
};
