class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n  = nums.size();
        int res = 0;
        int diff = INT_MAX;
        sort(nums.begin() , nums.end());

        for(int i =0; i<n; i++)
        {
            int l = i+1; int h = n-1;

            while(l<h)
            {
                int sum = nums[i] + nums[l] + nums[h];
                if(sum == target)
                {
                    return sum;
                }
                else if(abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    res = sum;
                }
                else if(sum > target)
                {
                    h--;
                }
                else{
                    l++;
                }
            }

        }
        return res;
    }
};
