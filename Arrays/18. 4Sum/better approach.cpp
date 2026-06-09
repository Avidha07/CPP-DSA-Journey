class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0; i<n-3; i++)
        {
            for(int j = i+1; j<n-2; j++)
            {
                int l = j+1; int h = n-1;
                while(l<h)
                {
                   long long sum = (long long) nums[i]+(long long )nums[j] + (long long) nums[l] + (long long) nums[h];
                   if(sum == target)
                   {
                       v.insert({nums[i],nums[j],nums[l],nums[h]});
                       l++; h--;
                   }
                   else if(sum >target)
                   {
                    h--;
                   }
                   else{
                    l++;
                   }
                }
            }
        }
        for(auto it : v)
        {
            ans.push_back(it);
        }
        return ans;
    }
};


