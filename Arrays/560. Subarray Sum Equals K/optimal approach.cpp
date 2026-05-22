class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         
         int n = nums.size();
         int cnt = 0;

         vector<int>prefixSum(n,0);
         prefixSum[0] = nums[0];
         //calculating prefixsum by indexing
         for(int i = 1; i<n; i++)
         {
            prefixSum[i] = prefixSum[i-1] + nums[i];
         }
         unordered_map<int,int>mp;

         for(int j =0; j<n; j++)
         {
            if(prefixSum[j]== k)
            {
                cnt++;
            }

            int val = prefixSum[j] - k;
            if(mp.find(val) != mp.end()){
                cnt+=mp[val];  //add freq of prefixSum
            }
            if(mp.find(prefixSum[j]) == mp.end()){
                mp[prefixSum[j]] = 0;
            }
            mp[prefixSum[j]]++;

         }

         return cnt;
  
    }
};
