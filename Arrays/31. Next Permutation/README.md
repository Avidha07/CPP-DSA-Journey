Problem Statement
Given an array of integers, find the next permutation in lexicographically increasing order.
If the current permutation is the last (i.e., sorted in descending order), return the first permutation (sorted in ascending order).

Approach: Brute Force
Idea

Generate all permutations of the array in sorted order.
Linear search through all permutations to find the current one.
Return the next permutation right after it.
If the current is the last permutation, return the first one.

Steps
Step 1: Sort the array to start from the lexicographically smallest permutation.
Step 2: Generate all N! permutations using next_permutation (STL).
Step 3: Store all permutations in a list.
Step 4: Find the index of the current permutation via linear search.
Step 5: Return permutation at index + 1 (or index 0 if it's the last).

Note: C++ STL provides next_permutation() which directly generates the next permutation without brute force. The above uses it only to pre-generate all permutations for demonstration purposes.

📊 Complexity Analysis
ComplexityTime Complexity : O(N! × N)
Space Complexity : O(N!)
Why so expensive?

For an array of size N, there are N! permutations.
We generate and store all of them, then do a linear search.

N         N!Permutations
5         120
10        3,628,800
15        ≈ 1.3 × 10¹²
20        ≈ 2.4 × 10¹⁸
For N = 15, we'd generate over 1 trillion permutations — clearly not practical!

❌ Why Brute Force is Avoided

Generating N! permutations is computationally infeasible for large N.
Memory required is also O(N!), which blows up quickly.
For N = 15, approximately 10¹² permutations must be generated and searched — making it practically unusable.

############################################################################################################################
