class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>res(n,0);
        int sum =0;
        
        if(k ==0 )
        {
            return res;
        }
        int start = 1; int end = k;
         if(k < 0)
         {
              start = n-abs(k);
              end = n-1;
         }

         for(int i = start; i<=end; i++ )
         {
            sum += code[i];
         }

         for(int j = 0; j<n; j++)
         {
            res[j] = sum;

            sum = sum - code[start%n];
            sum = sum + code[(end+1)%n];
            start++;
            end++;
         }

         return res;
    }
};
