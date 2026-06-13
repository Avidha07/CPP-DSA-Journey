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


// My first approach was brute force, where I checked every pair of elements. This takes O(n²) time and O(1) space.
// I then improved it using a HashMap. For each element, I looked for its complement (target - currentElement) in the map. This reduced the time complexity to O(n) but required O(n) extra space.
// Since the array is already sorted and the problem asks for constant extra space, I further optimized the solution using the Two Pointer technique. This achieves O(n) time complexity while reducing the space complexity to O(1), making it the optimal solution.
