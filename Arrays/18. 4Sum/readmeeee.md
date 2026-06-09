Problem Statement
Given an array nums of n integers, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct
nums[a] + nums[b] + nums[c] + nums[d] == target
The solution set must not contain duplicate quadruplets.
Approach
1. Sort the Array
First, sort the array. Sorting helps in:
Applying the two-pointer technique efficiently.
Generating quadruplets in a consistent order.
Avoiding duplicate combinations.
2. Fix the First Two Elements
Use two nested loops:
i selects the first element.
j selects the second element.
For every pair (i, j), find the remaining two numbers using the two-pointer approach.
3. Apply Two Pointers
Initialize:
l = j + 1
h = n - 1
Calculate:
sum = nums[i] + nums[j] + nums[l] + nums[h];
If sum == target, store the quadruplet.
If sum > target, move h--.
If sum < target, move l++.
4. Remove Duplicates
A set<vector<int>> is used to automatically store only unique quadruplets.
5. Convert Set to Answer Vector
Finally, copy all quadruplets from the set into the result vector.
Why Use long long?
The sum of four integers may exceed the range of int.
Example:
1000000000 + 1000000000 + 1000000000 + 1000000000
To prevent integer overflow:
long long sum =
(long long)nums[i] +
(long long)nums[j] +
(long long)nums[l] +
(long long)nums[h];
Algorithm
Sort the array.
Iterate over the first element i.
Iterate over the second element j.
Use two pointers l and h.
Calculate the sum of four elements.
Store valid quadruplets in a set.
Convert the set into the answer vector.
Return the result.
