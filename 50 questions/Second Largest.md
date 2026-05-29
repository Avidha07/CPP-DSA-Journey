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
