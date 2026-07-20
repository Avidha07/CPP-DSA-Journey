class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0; int j =0;
        int maxi = INT_MIN;
        int len = 0;
        int zerocnt = 0;
        int totallen = 0;

        while(j<n)
        {

            if(nums[j] == 0)
            {
                 zerocnt++;
            }
            while(zerocnt > 1)
            {
                if(nums[i] == 0)
                {
                    zerocnt--;
                }
                i++;
            }
            len = j-i+1;
            totallen = len-1; //because we are deleting one element 
            maxi = max(maxi ,  totallen);
            j++;
        }

        return maxi;
    }
};


