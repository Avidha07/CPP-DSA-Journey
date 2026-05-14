
# Two Sum

## Problem Statement
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

---

# Approaches

## 1. Brute Force Approach

### Idea
Check every possible pair using nested loops.

### Algorithm
1. Traverse the array using two loops.
2. Check whether `nums[i] + nums[j] == target`.
3. Return indices if found.

### Time Complexity
O(n²)

### Space Complexity
O(1)

### File
`brute_force.cpp`

---

## 2. Better Approach (Hashing)

### Idea
Use hashing to store visited elements and check for the required complement.

### Algorithm
1. Traverse the array.
2. Compute:
   ```cpp
   complement = target - nums[i]
   ```
3. If complement exists in hashmap, return indices.
4. Otherwise store current element in hashmap.

### Time Complexity
O(n)

### Space Complexity
O(n)

### File
`better_approach.cpp`

---

## 3. Optimal Approach (Sorting + Two Pointer)

### Idea
Store elements along with their original indices, sort the array, and use the two-pointer technique to find the target sum efficiently.

### Algorithm
1. Store:
   ```cpp
   {value, original_index}
   ```
2. Sort the vector.
3. Use two pointers:
   - left = 0
   - right = n - 1
4. Compare sum:
   - If sum == target → return original indices
   - If sum < target → move left++
   - If sum > target → move right--

### Time Complexity
O(n log n)

### Space Complexity
O(n)

### File
`optimal.cpp`

---

# Learning Outcomes

- Learned brute-force pair checking.
- Understood hashing optimization.
- Practiced sorting with original index preservation.
- Learned two-pointer technique.
- Compared time complexity improvements from O(n²) to O(n log n) and O(n).

---

# Repository Structure

```text
two_sum/
 ├── brute_force.cpp
 ├── better_approach.cpp
 ├── optimal.cpp
 └── README.md
```

Interview-Level Explanation (Ideal Answer)
A strong answer would sound like this:
“We traverse the array once. For every element nums[i], we calculate the complement as target - nums[i]. We check whether this complement already exists in the hash map. If it exists, we return the stored index and the current index. Otherwise, we store the current element and its index in the map for future lookup.”
