class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int m = grumpy.size();
        int satisfied = 0;
        vector<int>sat(n,0);
        for(int i = 0; i<n; i++)
        {
            if(grumpy[i] == 0)
            {
                 satisfied += customers[i];
                 sat[i] = 0;
            }
            else {
                sat[i] = customers[i];
            }
        }
        int sum = 0;
        int maxi = INT_MIN;
        int i = 0; int j = 0;
        while(j<n)
        {
             sum += sat[j];
             if(j-i+1 == minutes)
             {
                maxi = max(maxi , sum);

                sum = sum - sat[i];
                i++;   
             }
             j++;
        }

        int res = satisfied + maxi;

        return res;
        

        
    }
};
