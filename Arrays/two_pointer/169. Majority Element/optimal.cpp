class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        int element = 0;

        for(int i=0 ; i < n; i++)
        {
             if(cnt == 0)
             {
                cnt++;
                element = nums[i];
             }
             else if(nums[i] == element)
             {
                cnt++;
             }
             else{
                cnt--;
             }
        }

        int cnt2 =0;

        for(int i =0; i<n; i++)
        {
            if(element == nums[i])
            {
                cnt2++;
            }
        }

        if(cnt2>n/2)
        {
            return element;
        }
        return -1;

    }
};
