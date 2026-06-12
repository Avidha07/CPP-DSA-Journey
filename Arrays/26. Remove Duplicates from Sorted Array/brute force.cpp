//using set
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        set<int>st;

        for(int i = 0; i<n; i++)
        {
            st.insert(nums[i]);
        }
         
         int i =0;
        for(auto it : st)
        {
            nums[i++] = it;
        }

        return i;
    }
};

//////////////////////////////////////////////////////////////////
//using vector
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>v;
        v.push_back(nums[0]);

        for(int i =1; i<n; i++)
        {
            if(nums[i] != nums[i-1])
            {
               v.push_back(nums[i]);
            }
        }
         int idx = 0;
        for(auto it : v)
        {
             nums[idx++] = it;
        }

        return idx;
    }
};
