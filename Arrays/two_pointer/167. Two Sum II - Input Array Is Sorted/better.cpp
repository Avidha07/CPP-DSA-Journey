
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int ,int>mp;

        for(int i =0; i<n; i++)
        {
            int diff = target - nums[i];

            if(mp.find(diff) != mp.end())
            {
                return {mp[diff]+1 , i+1};
            }

            mp[nums[i]] = i;
        }
        return {-1 , -1};
    }
};


/*
Better Approach (Hash Map):

In the brute force approach, we check every possible pair, which leads to O(n²) time complexity.
Instead of searching for the second element repeatedly, we can store the elements we have already visited in a hash map.
For each element, we calculate the required complement (target - current element) and check whether it already exists in the map.
If the complement is found, we return their 1-based indices; otherwise, we store the current element and continue.
This optimization reduces the time complexity to O(n) while using O(n) extra space.
*/
