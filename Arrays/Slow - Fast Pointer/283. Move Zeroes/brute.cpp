class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,0);
        int ind =0;
        for(int i =0; i<n; i++)
        {
            if(nums[i] != 0)
            {
                v[ind++] = nums[i];
            }
        }

        for(int i =0; i<n; i++)
        {
            nums[i] = v[i];
        }
    }
};
