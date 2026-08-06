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


/*
Brute Force Approach:
We iterate through every possible pair of elements using two nested loops.
For each pair, we calculate their sum and compare it with the target value.
If the sum equals the target, we return their 1-based indices immediately.
This approach is simple and uses O(1) extra space, but its time complexity is O(n²).
*/
