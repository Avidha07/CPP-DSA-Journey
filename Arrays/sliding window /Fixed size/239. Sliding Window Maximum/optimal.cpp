class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0; int j = 0;
        vector<int>res;
        deque<int>dq;
        int maxi = INT_MIN;

        while(j<n)
        {
            while(!dq.empty() && dq.back()<nums[j]){
                dq.pop_back();
            }

            dq.push_back(nums[j]);

            if( j-i+1 == k)
            {
                res.push_back(dq.front());

                if(dq.front() == nums[i]){
                    dq.pop_front();
                }
                i++; 
            }
            j++;

    
        }
        return res;
    }
};

