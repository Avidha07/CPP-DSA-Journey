class Solution {
  public:
    int countTriplets(int sum, vector<int>& nums) {
        // code here
        int n = nums.size();
        int cnt = 0;
        
        for(int i =0; i<n-2; i++)
        {
            for(int j = i+1; j<n-1; j++)
            {
                for(int k = j+1; k<n; k++)
                {
                    int total = nums[i]+nums[j]+nums[k];
                    if(total < sum)
                    {
                        cnt++;
                        
                    }
                }
            }
        }
        return cnt;
    }
};
