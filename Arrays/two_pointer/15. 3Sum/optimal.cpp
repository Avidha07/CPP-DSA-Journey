class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        int n = nums.size();

        for(int i =0; i<n-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1; int h = n-1;
            while(l<h)
            {
                int sum = nums[i]+nums[l]+nums[h];
                if(sum == 0)
                {
                   ans.push_back({nums[i] , nums[l] , nums[h]});

                   while(l<h && nums[l] == nums[l+1]) l++;
                   while(l<h && nums[h] == nums[h-1]) h--;

                   l++;
                   h--;
                }
                else if(sum > 0)
                {
                    h--;
                }
                else{
                    l++;
                }

            }
        }
        return ans;
        

    }
};
