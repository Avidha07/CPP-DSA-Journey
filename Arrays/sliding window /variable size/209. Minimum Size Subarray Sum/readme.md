# 209. Minimum Size Subarray Sum

> **LeetCode #209**  
> **Difficulty:** Medium  
> **Topics:** Array, Binary Search, Sliding Window, Prefix Sum  
> **Company Tags:** Amazon, Google, Microsoft, Meta, Apple, Bloomberg

---

# 📌 Problem Information

### Problem Name
Minimum Size Subarray Sum

### Problem Link
https://leetcode.com/problems/minimum-size-subarray-sum/

---

# 📝 Problem Statement

Given an array of **positive integers** `nums` and a positive integer `target`, return the **minimum length** of a contiguous subarray whose **sum is greater than or equal to `target`**.

If no such subarray exists, return **0**.

---

# 💡 Intuition

The problem asks for:

- A **contiguous subarray**
- Minimum length
- Sum ≥ Target
- All elements are **positive**

Since every element is positive:

- Expanding the window always increases (or keeps) the sum.
- Once the sum becomes greater than or equal to the target, we should shrink the window as much as possible to find the smallest valid subarray.

This makes it a perfect **Variable Size Sliding Window** problem.

---

# 🔍 Observations

- All elements are **positive**.
- Because numbers are positive:
  - Removing elements always decreases the sum.
  - Expanding always increases the sum.
- Therefore, each element enters and leaves the window at most once.
- Sliding Window works in **O(n)**.

---

# 📊 Constraints

- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

An **O(n²)** solution will result in **TLE**, so an **O(n)** approach is expected.

---

# 🚀 Brute Force Approach

### Idea

Generate every possible subarray.

For each subarray:

- Calculate its sum.
- If the sum ≥ target, update the minimum length.

### Complexity

**Time:** O(n²)

**Space:** O(1)

### Why it fails?

For `n = 100000`, checking every possible subarray is too slow.

---

# 🚀 Better Approach (Prefix Sum + Binary Search)

### Idea

1. Compute prefix sums.
2. For every starting index:
   - Use Binary Search to find the smallest ending index where the required sum is achieved.

### Complexity

**Time:** O(n log n)

**Space:** O(n)

This is the follow-up solution mentioned in the problem.

---

# ⭐ Optimal Approach (Sliding Window)

## Core Idea

Maintain a window whose sum is continuously tracked.

- Expand the window until the sum becomes **greater than or equal to the target**.
- Once the window satisfies the condition, shrink it from the left to make it as small as possible.
- Record the minimum length.

Repeat until the array ends.

---

# 🧠 Algorithm

1. Initialize:
   - `left = 0`
   - `right = 0`
   - `sum = 0`
   - `minLength = INT_MAX`

2. Expand the window by moving `right`.

3. Add the current element to the running sum.

4. While the sum is greater than or equal to the target:
   - Update the minimum length.
   - Remove the left element from the sum.
   - Move the left pointer.

5. Continue until the array ends.

6. If no valid window exists, return `0`.

---

# ✨ Dry Run

### Input

```
target = 7

nums = [2,3,1,2,4,3]
```

Initially

```
Window = []
Sum = 0
Answer = INF
```

Expand

```
[2]
Sum = 2
```

Expand

```
[2,3]
Sum = 5
```

Expand

```
[2,3,1]
Sum = 6
```

Expand

```
[2,3,1,2]
Sum = 8
```

Now

```
Sum ≥ Target
```

Update

```
Length = 4
```

Shrink

```
[3,1,2]
Sum = 6
```

Continue expanding

```
[3,1,2,4]
Sum = 10
```

Shrink

```
[1,2,4]
Length = 3
```

Shrink again

```
[2,4]
Sum = 6
```

Continue

```
[2,4,3]
Sum = 9
```

Shrink

```
[4,3]
Length = 2
```

Answer

```
2
```

---

# 📈 Complexity Analysis

Each element:

- Enters the window once.
- Leaves the window once.

Therefore,

**Time Complexity**

```
O(n)
```

**Space Complexity**

```
O(1)
```

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Prefix Sum + Binary Search | O(n log n) | O(n) |
| Sliding Window | **O(n)** | **O(1)** |

---

# ⚠️ Edge Cases

### Case 1

```
target = 4

nums = [1,4,4]
```

Answer

```
1
```

---

### Case 2

```
target = 11

nums = [1,1,1,1]
```

Answer

```
0
```

No valid subarray.

---

### Case 3

```
target = 5

nums = [5]
```

Answer

```
1
```

---

### Case 4

```
target = 100

nums = [1,2,3]
```

Answer

```
0
```

---

### Case 5

```
nums = [2,2,2,2]
target = 4
```

Answer

```
2
```

---

# ❌ Common Mistakes

### Mistake 1

Using Sliding Window when the array contains negative numbers.

This approach only works because **all numbers are positive**.

---

### Mistake 2

Using

```cpp
if(sum >= target)
```

instead of

```cpp
while(sum >= target)
```

We must keep shrinking to obtain the **minimum** length.

---

### Mistake 3

Forgetting to subtract the left element.

```cpp
sum -= nums[i];
```

---

### Mistake 4

Returning `INT_MAX`.

If no valid window exists,

return

```cpp
0
```

---

### Mistake 5

Updating the answer after shrinking.

Always update **before** removing the left element.

---

# 🎤 Interview Explanation

> "Since every element is positive, the window sum only increases when expanding and decreases when shrinking. I maintain a sliding window and keep adding elements until the sum becomes at least the target. Then I continuously shrink the window from the left to make it as small as possible while still satisfying the condition. Every element enters and leaves the window at most once, giving an O(n) solution."

---

# 🧩 Pattern Recognition

This is a classic **Variable Size Sliding Window** problem.

### Keywords

- Minimum Length
- Contiguous Subarray
- Sum ≥ Target
- Positive Integers
- Shrink Window
- Running Sum

Whenever you see

> **Minimum Subarray + Positive Numbers + Sum Constraint**

Think

> **Sliding Window**

---

# 📚 Key Learnings

- Variable Size Sliding Window.
- Running sum optimization.
- Shrink the window while the condition is satisfied.
- Positive numbers make Sliding Window possible.
- Each element is processed at most twice.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int sum = 0;
        int minl = INT_MAX;

        while (j < n) {

            sum += nums[j];

            while (sum >= target) {

                minl = min(minl, j - i + 1);

                sum -= nums[i];
                i++;
            }

            j++;
        }

        return (minl == INT_MAX) ? 0 : minl;
    }
};
```

---

# ⭐ Follow-Up Solution (O(n log n))

The follow-up asks for an **O(n log n)** solution.

### Idea

- Compute the Prefix Sum array.
- For every starting index:
  - Use Binary Search on the prefix sums to find the smallest ending index where:

```
prefix[end] - prefix[start] ≥ target
```

### Complexity

**Time**

```
O(n log n)
```

**Space**

```
O(n)
```

---

# 📝 Revision Notes

✅ Variable Size Sliding Window

✅ Running Sum

✅ Positive Numbers

✅ Shrink while `sum ≥ target`

✅ Track minimum length

**Pattern to Remember**

```
Expand Window
        ↓
Update Sum
        ↓
Sum ≥ Target ?
        ↓
Update Answer
        ↓
Shrink Window
        ↓
Repeat
```

---

# 🔄 Revision Tracker

| Revision | Date | Notes |
|----------|------|-------|
| 1 | ______ | Learned Sliding Window |
| 2 | ______ | Practiced Dry Run |
| 3 | ______ | Solved Without Help |
| 4 | ______ | Interview Revision |

---

# ⭐ Takeaway

This is one of the **most important Variable Size Sliding Window** problems. The crucial observation is that **all elements are positive**, allowing us to safely expand and shrink the window while maintaining a running sum. Whenever the sum reaches the target, we immediately try to minimize the window, leading to an efficient **O(n)** solution that is frequently asked in coding interviews.
