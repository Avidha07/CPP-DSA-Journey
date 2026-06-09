class Solution {
  public:
    int countTriplets(int sum, vector<int>& nums) {
        // code here
        int n = nums.size();
        int cnt = 0;
        
        sort(nums.begin() , nums.end());
        
        for(int i =0; i<n-2; i++)
        {
            int l = i+1; int h = n-1;
            
            while(l<h)
            {
                int total = nums[i] + nums[l] + nums[h];
                
                if(total > sum ||total == sum )
                {
                    h--;
                }
                else{
                    cnt = cnt + (h-l);
                    l++;
                }
            }
        }
        return cnt;
    }
};
