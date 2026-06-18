class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto it : nums)
        {
            st.insert(it);
        }
        
        int res = 0;
        for(auto it : st)
        {
            nums[res++] = it;
        }

        return res;
    }
};
