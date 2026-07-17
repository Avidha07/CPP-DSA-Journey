class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n = cardPoints.size();
       int start = n-k;
       int end = n-1;
     

       int sum = 0;
       for(int i = start; i<=end; i++)
       {
         sum += cardPoints[i];
       }

       if(k==n) return sum;

        int maxi = sum;
        int  i =0;
        while(i<k){
           
           sum = sum - cardPoints[start];
           sum = sum + cardPoints[i];
           maxi = max(maxi , sum);
           

           start++;
           i++;

       }

       return maxi;

       
       

    }
};
