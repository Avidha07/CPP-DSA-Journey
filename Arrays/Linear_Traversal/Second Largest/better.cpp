class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxElement = -1;
        int n = arr.size();
        
        for(int i =0; i<n; i++)
        {
            if(maxElement < arr[i]){
                maxElement = arr[i];
            }
        }
        
        
        int secLargest = -1;
        
        for(int i =0; i<n; i++)
        {
            if(secLargest < arr[i]  &&  arr[i] < maxElement)
            {
                secLargest = arr[i];
            }
        }
        return secLargest;
    }
};
