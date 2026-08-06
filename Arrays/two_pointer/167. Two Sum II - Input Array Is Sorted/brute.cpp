class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       
       int n = numbers.size();
       for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++)
        {
            int sum = numbers[i]+numbers[j];

            if(sum == target)
            {
                return {i+1 , j+1}; 
            }
        }

       }
       return {-1, -1}; 
    }
};


//The brute force approach checks every possible pair of elements using two nested loops. For each pair, it calculates their sum and //compares it with the target value. If the sum matches the target, it immediately returns the 1-based indices of those two elements. This //method is simple and guarantees the correct answer but takes O(n²) time since every pair is examined, while using O(1) extra space.
