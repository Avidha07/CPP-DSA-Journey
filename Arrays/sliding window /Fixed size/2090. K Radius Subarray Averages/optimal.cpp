class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>res(n,-1);
        int m = 2*k+1;
        long long int sum = 0;
        if(m>n){
            return res;
        }
        for(int i = 0; i<m; i++)
        {
            sum += nums[i];
        }
        res[k]=sum/m;
        for(int i = m; i<n; i++)
        {
            sum = sum + nums[i];
            sum = sum - nums[i-m];
            res[i-k] = sum/m;
        }
        return res;
    }
};
