class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxElement = arr[0];
        
        for(int i = 1; i<arr.size(); i++)
        {
            if(maxElement < arr[i])
            {
                maxElement = arr[i];
            }
        }
        return maxElement;
    }
};
