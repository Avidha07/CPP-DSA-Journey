class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for(int i =0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                j = i; //finding the first zero in the array
                break;
            }
        }

        if( j == -1) //no zeroes find in array
        {
            return ;
        }

        for(int i = j+1; i<nums.size(); i++)  // i alwasys start from  j+1 
        {
            if(nums[i] != 0)
            {
                swap(nums[i] , nums[j]);
                j++;
            }
        }
    }
};
