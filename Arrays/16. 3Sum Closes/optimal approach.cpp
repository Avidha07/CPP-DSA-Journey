class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();  
    sort(nums.begin() , nums.end());
    
    int sum = 0;
    int diff = INT_MAX;
    int res = 0;
    for(int i = 0; i<nums.size()-2; i++)
    {
        int low = i+1;
        int high = n-1;
        while(low < high)
        {

            sum = nums[i]+nums[low]+nums[high];
        
        if(sum == target)
        {
             return sum;
        }
        else if(abs(sum-target) < diff)
        {
            diff = abs(sum - target);
            res = sum;
        }
        else if(sum < target)
        {
            low++;

        }
        else {
            high--;
        }

        }
         
    }
    return res;
    }
};
