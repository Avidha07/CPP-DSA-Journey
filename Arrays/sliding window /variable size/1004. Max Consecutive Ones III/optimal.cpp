class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0; int j =0;
        int cnt = 0;
        int maxi = INT_MIN;
        int len = 0;

        while(j<n)
        {
            if(nums[j] == 0)
            {
                cnt++;
            }
            while(cnt > k)
            {
                
                    if(nums[i] == 0)
                    {
                        cnt--;
                    }
                    i++;
                
            }
            len = j-i+1;
            maxi = max(len , maxi);
            j++;
        }
        return maxi;
    }
};
