# LeetCode 287 - Find the Duplicate Number

## Problem Statement

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, there is only one repeated number in the array.

Return the duplicate number.

### Example

```cpp
Input: nums = [1,3,4,2,2]
Output: 2
```

---

# Approach 1: Using unordered_map

## Idea

Use a hash map to store the frequency of each number.

If a number appears more than once, return it immediately.

### Code

```cpp
unordered_map<int, int> mp;

for(int num : nums){
    mp[num]++;

    if(mp[num] > 1)
        return num;
}
```

### Complexity Analysis

| Complexity | Value        |
| ---------- | ------------ |
| Time       | O(n) average |
| Space      | O(n)         |

### Advantages

* Works for any range of values.
* Handles negative numbers.
* No assumptions about input constraints.

Example:

```cpp
[1000, 5000, 2000, 5000]
[-10, 20, -10]
```

### Disadvantages

* Hashing overhead.
* Higher memory usage.
* Worst-case lookup can degrade.

---

# Approach 2: Using Frequency Array

## Idea

Since the problem guarantees:

```cpp
1 <= nums[i] <= n
```

we can directly use the value as an index in a frequency array.

### Code

```cpp
vector<int> freq(n + 1, 0);

for(int num : nums){
    freq[num]++;

    if(freq[num] > 1)
        return num;
}
```

### Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(n)  |

### Advantages

* Faster than unordered_map in practice.
* Direct indexing.
* No hashing cost.
* Better cache locality.

### Disadvantages

* Works only when values lie within a small known range.
* Cannot handle very large or arbitrary values efficiently.

---

# Which One Is Better?

For this problem:

```cpp
1 <= nums[i] <= n
```

A frequency array is generally preferred over an unordered_map because direct indexing is faster than hashing.

### Ranking of Approaches

```text
Brute Force
    ↓
unordered_map
    ↓
Frequency Array
    ↓
Floyd's Cycle Detection (Optimal)
```

---

# Optimal Solution: Floyd's Cycle Detection

## Why Is It Optimal?

The problem asks for the duplicate number without modifying the array and using only constant extra space.

Floyd's Tortoise and Hare algorithm treats the array as a linked list and detects the cycle created by the duplicate number.

### Complexity

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(1)  |

This is the most optimized solution for the problem.

---

# Interview Explanation

A good interview answer would be:

> Since all numbers lie in the range `[1, n]`, I can use a frequency array to track occurrences. This provides O(n) time and O(n) space complexity. If the range were unknown, very large, or included negative values, I would choose an unordered_map instead. For the optimal solution, Floyd's Cycle Detection achieves O(n) time and O(1) space.

---

# Key Takeaway

Choose your data structure based on the constraints:

* Known small range → Frequency Array
* Unknown or large range → unordered_map
* Constant space required → Floyd's Cycle Detection

Understanding **why** a data structure is chosen is more important in interviews than simply knowing how to implement it.
