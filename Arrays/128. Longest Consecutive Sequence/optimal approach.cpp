class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }

        unordered_set<int>st(nums.begin() , nums.end());

        for(int i=0;i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        int longest = 0;
     

        for(auto it : st)
        {
            if(st.find(it - 1) == st.end()){
                int current = it;
                int cnt = 1;

                while(st.find(current+1) != st.end()){
                    current++;
                    cnt++;
                }
                 longest = max(longest , cnt);
            }

           
        }
        return longest;
    }
};
