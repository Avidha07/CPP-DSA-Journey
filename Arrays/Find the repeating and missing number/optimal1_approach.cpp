class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
      long long n = nums.size();

      // s-sn = x-y;
      //s2- s2n = x^2-y^2;

      long long sn = (n*(n+1))/2;
      long long s2n = (n*(n+1)*(2*n+1))/6;

      long long s = 0, s2 =0;

      for(int i =0; i<n; i++)
      {
        s += nums[i];
        s2 += (long long)nums[i]*(long long)nums[i];
      }
      long long val1 = s-sn; // x-y;
      long long val2 = s2 - s2n; //x^2 - y^2;

      val2 = val2/val1; //x+y;

      long long x = (val1+val2)/2; //repeating
      long long y = x-val1;  //missing

      return {(int)x , (int)y};
    }
};
