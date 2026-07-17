class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

       int n = nums.size();
       int i =0; int j =0; 
       int sum =0;
       double avg = 0.0;
       double maxi = INT_MIN;

       while(j<n)
       {
        sum += nums[j];

        if(j-i+1 == k)
        {
            avg = (double)sum/k;
            maxi = max(avg , maxi);

            sum -= nums[i];
            i++;   
        }
        j++;
       }
       return maxi; 
    }
};
