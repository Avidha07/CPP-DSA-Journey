class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
       vector<int>hash(n+1 , 0);
       int missing = -1;
       int reapting = -1;

       for(int i =0; i<n; i++)
       {
        hash[nums[i]]++;
       }

       for(int i = 1; i<=n; i++)
       {
        if(hash[i] == 2) reapting = i;
        else if(hash[i] == 0) missing = i;
       }

       if(reapting == -1 && missing == -1){
        break;
       }

       return {reapting , missing};
    }
};
