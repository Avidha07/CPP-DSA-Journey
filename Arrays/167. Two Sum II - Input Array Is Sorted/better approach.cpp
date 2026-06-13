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


//Initially, I thought of using a HashMap because it gives O(n) time complexity. However, it requires O(n) extra space. Since the array is already sorted and the problem requires constant extra space, I can optimize further using the Two Pointer technique. The Two Pointer solution still runs in O(n) time but uses only O(1) extra space, making it the preferred solution.
