# 560. Subarray Sum Equals K

## Problem Statement

Given an integer array `nums` and an integer `k`, return the total number of subarrays whose sum equals to `k`.

A subarray is a contiguous non-empty sequence of elements within an array.

---

# Brute Force Approach

## Idea

Generate all possible subarrays using two nested loops.

For every subarray:
- Calculate the sum
- If sum becomes equal to `k`, increase the count

---

## Brute Force Code (C++)

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         
         int sum = 0;
         int cnt = 0;

         for(int i = 0; i < nums.size(); i++) {   
            
            sum = 0;

            for(int j = i; j < nums.size(); j++) {

                sum += nums[j];

                if(sum == k) {
                    cnt++;
                }
            }
         }

         return cnt;
    }
};
```

---

## Time Complexity

```math
O(n^2)
```

## Space Complexity

```math
O(1)
```

---

# Optimal Approach — Prefix Sum + HashMap

## Prefix Sum Concept

`prefixSum[i]` stores the sum of elements from index `0` to `i`.

Example:

```text
nums = [1, 2, 3]

prefixSum = [1, 3, 6]
```

---

# Core Observation

Suppose current prefix sum is:

```math
prefixSum[j]
```

We need some previous prefix sum such that:

```math
prefixSum[j] - previousPrefixSum = k
```

Rearranging:

```math
previousPrefixSum = prefixSum[j] - k
```

So:
- If `(prefixSum[j] - k)` already exists,
- Then a valid subarray exists.

---

# Why Use unordered_map?

We store:

```cpp
prefixSum -> frequency
```

Example:

```cpp
unordered_map<int, int> mp;
```

---

## map vs unordered_map

| Data Structure | Internal Structure | Average Time Complexity |
|---|---|---|
| `map` | Red Black Tree | `O(log n)` |
| `unordered_map` | Hash Table | `O(1)` |

Since frequent lookup is required, `unordered_map` is preferred.

---

# Optimal Code (C++)

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         
         int n = nums.size();
         int cnt = 0;

         vector<int> prefixSum(n, 0);

         prefixSum[0] = nums[0];

         // Calculating prefix sum array
         for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
         }

         unordered_map<int, int> mp;

         for(int j = 0; j < n; j++) {

            // If prefix sum itself equals k
            if(prefixSum[j] == k) {
                cnt++;
            }

            int val = prefixSum[j] - k;

            // If required prefix sum exists
            if(mp.find(val) != mp.end()) {
                cnt += mp[val];
            }

            // Store frequency
            mp[prefixSum[j]]++;
         }

         return cnt;
    }
};
```

---

# Time Complexity

```math
O(n)
```

---

# Space Complexity

```math
O(n)
```

---

# Best Optimized Version

We can optimize space further by removing the prefix sum array and calculating prefix sum dynamically.

---

## Fully Optimized Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefixSum = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int remove = prefixSum - k;

            if(mp.find(remove) != mp.end()) {
                cnt += mp[remove];
            }

            mp[prefixSum]++;
        }

        return cnt;
    }
};
```

---

# Why `mp[0] = 1`?

This handles cases where the subarray starts from index `0`.

Example:

```text
nums = [1,1,1]
k = 2
```

When:

```math
prefixSum = 2
```

Then:

```math
prefixSum - k = 0
```

So we already need one occurrence of `0` inside the map.

---

# Final Complexity

## Time Complexity

```math
O(n)
```

## Space Complexity

```math
O(n)
```

---

# Key Learnings

- Prefix Sum converts subarray problems into prefix difference problems.
- HashMap stores frequencies of prefix sums.
- `unordered_map` gives average `O(1)` lookup.
- Very important pattern for:
  - Subarray Sum problems
  - Zero Sum Subarray
  - Longest Subarray
  - Binary Array problems

---

# Common Mistakes

❌ Forgetting `mp[0] = 1`

❌ Using sliding window for negative numbers

❌ Storing only existence instead of frequency

❌ Confusing subarray with subsequence

---

# Interview Explanation

> We use Prefix Sum and HashMap.
>
> If `(currentPrefixSum - k)` already existed before,
> then the subarray between those indices has sum `k`.
>
> HashMap helps us perform lookup in `O(1)` average time,
> giving an overall time complexity of `O(n)`.

---
