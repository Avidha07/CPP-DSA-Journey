# 1695. Maximum Erasure Value

> **LeetCode #1695**  
> **Difficulty:** Medium  
> **Topics:** Array, Hash Table, Sliding Window, Two Pointers  
> **Company Tags:** Amazon, Google, Microsoft, Bloomberg, Adobe

---

# 📌 Problem Information

### Problem Name
Maximum Erasure Value

### Problem Link
https://leetcode.com/problems/maximum-erasure-value/

---

# 📝 Problem Statement

You are given an array of **positive integers** `nums`.

You need to choose **exactly one contiguous subarray** such that:

- Every element inside the chosen subarray is **unique**.
- The score obtained is the **sum of all elements** in that subarray.

Return the **maximum possible score**.

---

# 💡 Intuition

The moment we see:

- contiguous subarray
- unique elements
- maximize something

it strongly suggests a **Sliding Window + Hash Set** approach.

The idea is simple:

- Expand the window by moving the right pointer.
- If a duplicate appears, shrink the window from the left until the duplicate is removed.
- Maintain the running sum of the current unique window.
- Update the maximum sum whenever the window becomes valid.

---

# 🔍 Observations

- Every number is **positive**.
- Because all numbers are positive:
  - Expanding the window always increases the sum.
  - We never want to remove elements unless forced by duplicates.
- A Hash Set can quickly tell whether an element already exists in the current window.
- Each element is inserted and removed at most once.

---

# 📊 Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

An **O(n²)** solution will result in **TLE**, so an **O(n)** approach is required.

---

# 🚀 Brute Force Approach

### Idea

Generate every possible subarray.

For every subarray:

- Check whether all elements are unique.
- If unique, calculate its sum.
- Update the maximum answer.

### Complexity

**Time:** O(n²)

or

O(n³) if uniqueness is checked separately.

**Space:** O(n)

### Why it fails?

For `n = 100000`, generating every subarray is impossible within the time limit.

---

# 🚀 Better Approach (Prefix Sum + Hashing)

We can use prefix sums to compute subarray sums faster.

However,

we still need to detect duplicates for every possible window.

Although sum calculation becomes O(1), duplicate checking still dominates.

Overall complexity remains around **O(n²)**.

Still not efficient enough.

---

# ⭐ Optimal Approach (Sliding Window + Hash Set)

### Core Idea

Maintain a window containing only unique elements.

For every new element:

- If it is not present:
  - Add it to the window.
  - Increase the running sum.
- If it already exists:
  - Remove elements from the left until the duplicate disappears.
  - Continue expanding.

Keep updating the maximum sum throughout the process.

---

# 🧠 Algorithm

1. Initialize:
   - left pointer = 0
   - right pointer = 0
   - running sum = 0
   - maximum sum = 0
   - Hash Set

2. Expand the window.

3. If duplicate found:
   - Remove elements from left.
   - Update running sum.
   - Erase them from Hash Set.

4. Insert the current element.

5. Add it to the running sum.

6. Update answer.

7. Continue until the array ends.

---

# ✨ Dry Run

### Input

```
nums = [4,2,4,5,6]
```

Initial

```
Window = []
Sum = 0
Answer = 0
```

Add 4

```
[4]
Sum = 4
Answer = 4
```

Add 2

```
[4,2]
Sum = 6
Answer = 6
```

Next element = 4 (duplicate)

Remove from left

```
Remove 4

Window = [2]
Sum = 2
```

Now insert 4

```
[2,4]
Sum = 6
```

Insert 5

```
[2,4,5]
Sum = 11
Answer = 11
```

Insert 6

```
[2,4,5,6]
Sum = 17
Answer = 17
```

Final Answer

```
17
```

---

# 📈 Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Insert into Hash Set | O(1) |
| Remove from Hash Set | O(1) |
| Each element processed at most twice | O(n) |

### Overall

**Time Complexity**

```
O(n)
```

**Space Complexity**

```
O(n)
```

(Hash Set)

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) / O(n³) | O(n) |
| Better | O(n²) | O(n) |
| Sliding Window + Hash Set | **O(n)** | **O(n)** |

---

# ⚠️ Edge Cases

### Case 1

```
nums = [5]
```

Answer = 5

---

### Case 2

```
nums = [1,2,3,4]
```

Entire array is unique.

Answer = 10

---

### Case 3

```
nums = [2,2,2]
```

Only one element can be chosen.

Answer = 2

---

### Case 4

```
nums = [1,2,1,3]
```

Need to shrink the window when duplicate appears.

---

### Case 5

Large input (`10^5` elements)

Sliding Window still works efficiently in linear time.

---

# ❌ Common Mistakes

### Mistake 1

Using a frequency map but forgetting to decrease frequency while shrinking.

---

### Mistake 2

Not updating the running sum while removing elements.

```cpp
sum -= nums[i];
```

---

### Mistake 3

Updating the answer before removing duplicates.

Always ensure the window is valid first.

---

### Mistake 4

Resetting the entire window after finding a duplicate.

Only remove elements until the duplicate disappears.

---

# 🎤 Interview Explanation

> "Since all elements are positive, expanding the window always increases the current sum. Therefore, we maintain the largest possible window containing unique elements. A Hash Set allows constant-time duplicate detection. Whenever a duplicate is encountered, we shrink the window from the left while removing elements from both the set and the running sum. Each element enters and leaves the window at most once, giving an O(n) solution."

---

# 🧩 Pattern Recognition

This problem belongs to the **Variable Size Sliding Window** pattern.

### Keywords

- Longest/Maximum Subarray
- Unique Elements
- No Duplicates
- Contiguous Subarray
- Hash Set
- Two Pointers

Whenever you see these keywords together,

think:

> **Sliding Window + Hash Set**

---

# 📚 Key Learnings

- Variable-size Sliding Window.
- Maintaining a running sum efficiently.
- Using a Hash Set for O(1) duplicate detection.
- Shrinking the window only when necessary.
- Every element is processed at most twice, leading to linear time complexity.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int sum = 0;
        int maxiSum = 0;

        unordered_set<int> st;

        while (j < n) {

            while (st.find(nums[j]) != st.end()) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            st.insert(nums[j]);
            sum += nums[j];

            maxiSum = max(maxiSum, sum);

            j++;
        }

        return maxiSum;
    }
};
```

---

# 📝 Revision Notes

✅ Variable Size Sliding Window

✅ Hash Set for uniqueness

✅ Running Sum

✅ Shrink until duplicate disappears

✅ Each element enters and exits the window once

**Pattern to Remember**

```
Expand Window
        ↓
Duplicate?
        ↓
Shrink Window
        ↓
Insert Current
        ↓
Update Answer
```

---

# 🔄 Revision Tracker

| Revision | Date | Notes |
|----------|------|-------|
| 1 | ______ | Learned Sliding Window + Hash Set |
| 2 | ______ | Practiced Dry Run |
| 3 | ______ | Solved Without Help |
| 4 | ______ | Interview Revision |

---

## ⭐ Takeaway

This is a classic **Variable Size Sliding Window** problem where maintaining **uniqueness** is the key. The combination of a **Hash Set** for duplicate detection and a **running sum** allows us to find the maximum unique subarray sum efficiently in **O(n)** time.
