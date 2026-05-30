class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
         sort(arr.begin() , arr.end());
         int n = arr.size();
    
   int largest = arr[n-1];
   
   for(int i = n-2; i>=0; i--)
   {
       if(arr[i] != largest)
       {
           return arr[i];
       }
   }
   return -1;
    
    }
};


class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
         int n = arr.size();
         
         if(n==0 || n== 1)
         {
             return -1;
         }
         
         int large = INT_MIN ; int second_large = -1;
         
         for(int i =0; i<n; i++)
         {
             large = max(large , arr[i]);
         }
         
         for(int i =0; i<n; i++)
         {
             if(arr[i] > second_large && arr[i] != large){
                 second_large = arr[i];
             }
         }
         return second_large;
    
    
    }
};
