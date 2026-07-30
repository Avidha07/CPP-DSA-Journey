class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i =0; int j =0;
        int sum =0; int minl = INT_MAX;

        while(j<n)
        {
            sum+=nums[j];

            while(sum >= target)
            {   
                minl = min(minl , j-i+1);
                sum = sum - nums[i];
                i++;
            }
   
            j++;

        }
        if(minl == INT_MAX)
        {
            return 0;
        }

        return minl;
    }
};
