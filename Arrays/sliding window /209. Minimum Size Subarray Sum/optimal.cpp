class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int i = 0; int j =0;
        int sum =0;
        int mini = INT_MAX;
        int len = 0;
        while(j<n){

            sum += nums[j];

            if(sum < target)
            {
                j++;
            }
            if(sum >= target)
            {
                
                while(sum >= target)
                {   
                    len = j-i+1;
                    mini = min(mini , len);
                    sum = sum-nums[i];
                    i++;
                }
                j++;
            }

            
        }

        if(mini == INT_MAX)
        {
            return 0;
        }
        return mini;
    }
};
