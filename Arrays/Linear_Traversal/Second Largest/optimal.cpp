class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxElement = -1;
         int secLargest = -1;
        int n = arr.size();
        
        for(int i =0; i<n; i++)
        {
            if(arr[i] > maxElement ){
                secLargest = maxElement;
                maxElement = arr[i];
            }
            
            else if(arr[i] > secLargest && arr[i] < maxElement){
                secLargest = arr[i];
            }
        }
        
        return secLargest;
    }
};
