class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int one= 0; int two = 0;
        int zero = 0;

        for(int i =0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                zero++;
            }
            else if(nums[i] == 1){
                one++;
            }
            else {
                two++;
            }
        }

        int ind =0;
        while(zero--)
        {
            nums[ind++] = 0;
        }
        while(one--)
        {
            nums[ind++] = 1;
        }
        while(two--)
        {
            nums[ind++] = 2;
        }
    }
};
