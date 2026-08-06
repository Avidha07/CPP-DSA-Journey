# 167. Two Sum II - Input Array Is Sorted

## 📌 Problem Information

- **Platform:** LeetCode
- **Problem Number:** 167
- **Difficulty:** Medium
- **Topic(s):** Array, Two Pointers
- **Pattern:** Opposite Direction Two Pointers

---

# 📝 Problem Statement

Given a **1-indexed** array of integers `numbers` that is sorted in non-decreasing order, find two numbers such that they add up to a specific `target`.

Return the indices of the two numbers as a vector of size `2`.

### Constraints

- Exactly one valid solution exists.
- The same element cannot be used twice.
- Only **constant extra space** is allowed.

---

# 💡 Intuition

Since the array is sorted, we can utilize its ordering instead of checking every possible pair.

If the current sum is greater than the target, moving the right pointer decreases the sum. If the current sum is smaller than the target, moving the left pointer increases the sum. This observation leads to an optimal two-pointer solution.

---

# 🔍 Observations

- The array is already sorted.
- Brute force checks every pair unnecessarily.
- Binary search or hashing can improve the brute force solution.
- The sorted property allows us to eliminate many pairs using two pointers.
- Constant extra space requirement hints towards the two-pointer approach.

---

# 🚫 Constraints

- `2 <= numbers.length <= 3 × 10^4`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in non-decreasing order.
- `-1000 <= target <= 1000`
- Exactly one solution exists.

---

# 🥉 Brute Force Approach

### Idea

Check every possible pair and return the indices whose sum equals the target.

### Interview Explanation

The brute force approach checks every possible pair of elements using two nested loops. For each pair, it calculates their sum and compares it with the target value. If the sum matches the target, it immediately returns the 1-based indices of those two elements. This approach is simple and guarantees the correct answer but takes **O(n²)** time since every pair is examined while using **O(1)** extra space.

### Algorithm

1. Traverse every element.
2. For every element, check all remaining elements.
3. Calculate their sum.
4. Return the indices when the target is found.

### Complexity

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

# 🥈 Better Approach (Hash Map)

### Thinking Process

In the brute force approach, we repeatedly search for the second number, which results in unnecessary comparisons. Instead of searching again, we can remember the elements we've already visited using a hash map. For every element, we simply check whether its required complement already exists.

### Interview Explanation

We traverse the array once while storing each element and its index in a hash map. For every element, we calculate the required complement (`target - current element`) and check whether it already exists in the map. If found, we return their indices immediately; otherwise, we store the current element and continue. This optimization reduces the time complexity to **O(n)** while using **O(n)** extra space.

### Algorithm

1. Create an empty hash map.
2. Traverse the array.
3. Compute `target - currentElement`.
4. If the complement exists in the map, return the answer.
5. Otherwise, store the current element and continue.

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

# 🥇 Optimal Approach (Two Pointers)

### Thinking Process

The array is already sorted, so we don't need extra memory. By placing one pointer at the beginning and another at the end, we can intelligently decide which pointer to move based on the current sum.

### Interview Explanation

The sorted property allows us to eliminate impossible pairs without checking every combination. If the current sum is greater than the target, we move the right pointer to decrease the sum. If the current sum is smaller, we move the left pointer to increase it. This continues until the required pair is found, giving the optimal solution in linear time with constant extra space.

### Algorithm

1. Initialize `left = 0` and `right = n-1`.
2. Calculate the current sum.
3. If the sum equals the target, return the indices.
4. If the sum is greater than the target, decrement `right`.
5. Otherwise, increment `left`.

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Better (Hash Map) | O(n) | O(n) |
| Optimal (Two Pointers) | O(n) | O(1) |

---

# ⚠️ Edge Cases

- Array contains only two elements.
- Target is formed by the first and last element.
- Duplicate values exist.
- Negative numbers are present.
- Target is negative.

---

# ❌ Common Mistakes

- Forgetting the array is **1-indexed**.
- Initializing the right pointer as `n` instead of `n-1`.
- Returning 0-based indices.
- Using the hash map solution in interviews without noticing the constant space constraint.
- Forgetting that the array is already sorted.

---

# 🎤 Interview Explanation

When I first solved this problem, I considered checking every pair using two nested loops, but that takes **O(n²)** time. Then I realized that repeatedly searching for the second element is unnecessary, so I improved it using a hash map, reducing the complexity to **O(n)** with extra space. Finally, I observed that the array is already sorted and the problem requires constant extra space. This naturally leads to the two-pointer approach, where we move the left or right pointer depending on whether the current sum is smaller or larger than the target, achieving **O(n)** time and **O(1)** space.

---

# 🧠 Pattern Recognition

- Two Pointers
- Opposite Direction Pointers
- Sorted Array
- Hashing
- Array

---

# 📚 Key Learnings

- Always identify whether the array is sorted.
- Sorted arrays often indicate a two-pointer solution.
- Hashing removes repeated searching.
- Constant space constraints are strong hints toward two pointers.
- Always look for opportunities to eliminate unnecessary comparisons.

---

# 💻 C++17 Solution

### Optimal Solution (Two Pointers)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1};

            if (sum > target)
                right--;
            else
                left++;
        }

        return {};
    }
};
```

---

# 📝 Revision Notes

- Brute Force → Check every pair.
- Better → Store visited elements in a hash map.
- Optimal → Sorted array ⇒ Two pointers.
- Move left if sum is smaller.
- Move right if sum is larger.
- Return 1-based indices.

---
