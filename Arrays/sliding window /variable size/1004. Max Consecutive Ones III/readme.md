# 1004. Max Consecutive Ones III

> **LeetCode #1004**  
> **Difficulty:** Medium  
> **Topics:** Array, Binary Search, Sliding Window, Prefix Sum  
> **Company Tags:** Amazon, Google, Microsoft, Meta, Bloomberg

---

# 📌 Problem Information

### Problem Name
Max Consecutive Ones III

### Problem Link
https://leetcode.com/problems/max-consecutive-ones-iii/

---

# 📝 Problem Statement

You are given a binary array `nums` and an integer `k`.

You can flip **at most `k` zeros** into ones.

Return the **maximum number of consecutive 1's** possible after performing at most `k` flips.

---

# 💡 Intuition

The problem asks for:

- Longest contiguous subarray
- At most `k` modifications (flip 0 → 1)

This is a classic **Variable Size Sliding Window** problem.

Instead of actually flipping zeros, we simply **count how many zeros are inside the current window**.

- If the number of zeros is within `k`, the window is valid.
- If it exceeds `k`, shrink the window until it becomes valid again.

The largest valid window is our answer.

---

# 🔍 Observations

- We never need to physically flip any element.
- The only thing that matters is the **count of zeros** inside the current window.
- Since we only expand and shrink the window once, each element is processed at most twice.

---

# 📊 Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`
- `0 <= k <= nums.length`

A quadratic solution will result in **TLE**, so an **O(n)** approach is required.

---

# 🚀 Brute Force Approach

### Idea

Generate every possible subarray.

For each subarray:

- Count the number of zeros.
- If zeros ≤ `k`, update the answer.

### Complexity

**Time:** O(n²)

**Space:** O(1)

### Why it fails?

For `n = 100000`, checking every subarray is too slow.

---

# 🚀 Better Approach (Prefix Sum)

We can precompute prefix sums of zeros.

Then:

- Find the number of zeros in any subarray in O(1).

However,

we still need to check every possible subarray.

Overall complexity remains **O(n²)**.

---

# ⭐ Optimal Approach (Sliding Window)

## Core Idea

Maintain a window such that:

```
Number of zeros inside window ≤ k
```

Expand the window.

Whenever zeros become greater than `k`:

- Move the left pointer.
- Remove zeros leaving the window.
- Continue until the window becomes valid again.

Update the maximum window length.

---

# 🧠 Algorithm

1. Initialize:
   - `left = 0`
   - `right = 0`
   - `zeroCount = 0`
   - `answer = 0`

2. Expand the window.

3. If current element is `0`,
   increment `zeroCount`.

4. While `zeroCount > k`:
   - Move the left pointer.
   - If a zero leaves the window,
     decrement `zeroCount`.

5. Update the maximum window length.

6. Continue until the array ends.

---

# ✨ Dry Run

### Input

```
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
```

Initially

```
Window = []
Zeros = 0
Answer = 0
```

Expand

```
[1,1,1]
Zeros = 0
Length = 3
```

Add first zero

```
[1,1,1,0]
Zeros = 1
Length = 4
```

Add second zero

```
[1,1,1,0,0]
Zeros = 2
Length = 5
```

Add third zero

```
Zeros = 3
```

Now

```
Zeros > k
```

Shrink from the left until

```
Zeros = 2
```

Continue expanding.

Maximum valid window becomes

```
Length = 6
```

Answer

```
6
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

Only a few variables are used.

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Prefix Sum | O(n²) | O(n) |
| Sliding Window | **O(n)** | **O(1)** |

---

# ⚠️ Edge Cases

### Case 1

```
nums = [1,1,1]
k = 0
```

Answer = 3

---

### Case 2

```
nums = [0,0,0]
k = 0
```

Answer = 0

---

### Case 3

```
nums = [0,0,0]
k = 3
```

Answer = 3

---

### Case 4

```
nums = [1]
k = 0
```

Answer = 1

---

### Case 5

```
nums = [0]
k = 1
```

Answer = 1

---

# ❌ Common Mistakes

### Mistake 1

Actually flipping zeros.

Flipping is unnecessary.

Only maintain the zero count.

---

### Mistake 2

Shrinking only once.

Incorrect

```cpp
if(cnt > k)
```

Correct

```cpp
while(cnt > k)
```

Always shrink until the window becomes valid.

---

### Mistake 3

Forgetting to decrement the zero count.

```cpp
if(nums[i] == 0)
    cnt--;
```

---

### Mistake 4

Updating the answer before making the window valid.

Always shrink first.

---

### Mistake 5

Using `INT_MIN` for initialization.

Since the answer cannot be negative,

```cpp
int maxi = 0;
```

is cleaner.

---

# 🎤 Interview Explanation

> "The problem asks for the longest contiguous subarray where we can flip at most `k` zeros. Instead of actually flipping values, I maintain the count of zeros inside the sliding window. If the zero count exceeds `k`, I move the left pointer until the window becomes valid again. Every valid window is a candidate answer, and since each element enters and leaves the window only once, the overall complexity is O(n)."

---

# 🧩 Pattern Recognition

This belongs to the **Variable Size Sliding Window** pattern.

### Keywords

- Longest Subarray
- At Most K
- Binary Array
- Flip
- Consecutive
- Maximum Length

Whenever you see:

> **Longest Subarray + At Most K Changes**

Think:

> **Sliding Window**

---

# 🔗 Related Problems

1. LeetCode 424 - Longest Repeating Character Replacement
2. LeetCode 904 - Fruit Into Baskets
3. LeetCode 1493 - Longest Subarray of 1's After Deleting One Element
4. LeetCode 2024 - Maximize the Confusion of an Exam
5. LeetCode 487 - Max Consecutive Ones II
6. LeetCode 209 - Minimum Size Subarray Sum

---

# 📚 Key Learnings

- Variable Size Sliding Window.
- Maintain the number of invalid elements (zeros).
- Shrink only when constraints are violated.
- Don't simulate flips.
- Each element is visited at most twice.
- "At Most K" problems often use Sliding Window.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int cnt = 0;
        int maxi = 0;

        while (j < n) {

            if (nums[j] == 0)
                cnt++;

            while (cnt > k) {

                if (nums[i] == 0)
                    cnt--;

                i++;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};
```

---

# 📝 Revision Notes

✅ Variable Size Sliding Window

✅ Count zeros inside the window

✅ Shrink while `zeroCount > k`

✅ Update maximum window size

✅ No actual flipping required

**Pattern to Remember**

```
Expand Window
        ↓
Count Zeros
        ↓
Zeros > K ?
        ↓
Shrink Window
        ↓
Update Answer
```

---

# 🔄 Revision Tracker

| Revision | Date | Notes |
|----------|------|-------|
| 1 | ______ | Learned Variable Sliding Window |
| 2 | ______ | Practiced Dry Run |
| 3 | ______ | Solved Without Help |
| 4 | ______ | Interview Revision |

---

# ⭐ Takeaway

This is one of the **most important Sliding Window interview problems**. The key observation is that we never need to flip any zeros—we only track how many zeros exist inside the current window. As long as the number of zeros does not exceed `k`, the window is valid. This leads to a simple and highly efficient **O(n)** Sliding Window solution, a pattern that appears frequently in coding interviews.
