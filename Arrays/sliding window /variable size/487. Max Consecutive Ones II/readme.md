# 487. Max Consecutive Ones II

## 📌 Problem Information

* **Problem Name:** 487.Max Consecutive Ones II
* **Platform:** Leetcode
* **Difficulty:** Medium
* **Topic:** Sliding Window, Two Pointers
* **Pattern:** Variable Size Sliding Window

---

# 📝 Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`s that can be obtained by flipping **at most one** `0` into `1`.

---

## 💡 Intuition

We are allowed to flip **only one** `0`.

Instead of checking every possible flip, maintain a **sliding window** that always contains **at most one zero**.

* Expand the window by moving the right pointer.
* Count the number of zeros inside the window.
* If the number of zeros becomes greater than one, shrink the window from the left until it again contains at most one zero.
* The largest valid window is the answer.

---

# 🔍 Observations

* If the array contains only `1`s, the answer is the length of the array.
* The window is valid only when it contains **0 or 1 zero**.
* Once two zeros appear, move the left pointer until one zero is removed.

---

# 📌 Constraints

* `1 <= nums.length <= 10^4`
* `nums[i]` is either `0` or `1`.

---

# 🐢 Brute Force Approach

### Idea

For every starting index:

* Extend the subarray.
* Count zeros.
* Stop once more than one zero appears.
* Track the maximum valid length.

### Algorithm

1. Start from every index.
2. Count zeros while expanding.
3. Break when zeros exceed one.
4. Update the maximum length.

### Time Complexity

**O(N²)**

### Space Complexity

**O(1)**

---

# 🚀 Optimal Approach (Sliding Window)

## Idea

Maintain a window containing **at most one zero**.

* Expand the right pointer.
* Increment zero count whenever a zero is encountered.
* If zero count exceeds one, shrink the window from the left until it becomes valid again.
* Update the maximum window size.

---

## Algorithm

1. Initialize:

   * `left = 0`
   * `zeroCount = 0`
   * `maxLen = 0`
2. Traverse using the right pointer.
3. If `nums[right] == 0`, increment `zeroCount`.
4. While `zeroCount > 1`:

   * If `nums[left] == 0`, decrement `zeroCount`.
   * Move `left`.
5. Update:

   * `maxLen = max(maxLen, right - left + 1)`
6. Return `maxLen`.

---

# ✅ Dry Run

### Input

```text
nums = [1,0,1,1,0]
```

| Left | Right | Window      | Zero Count | Max Length |
| ---- | ----- | ----------- | ---------- | ---------- |
| 0    | 0     | [1]         | 0          | 1          |
| 0    | 1     | [1,0]       | 1          | 2          |
| 0    | 2     | [1,0,1]     | 1          | 3          |
| 0    | 3     | [1,0,1,1]   | 1          | 4          |
| 0    | 4     | [1,0,1,1,0] | 2          | Invalid    |

Shrink the window:

* Remove `1`
* Remove first `0`

New window:

```text
[1,1,0]
```

Length = 3

Maximum remains **4**.

---

# 📊 Complexity Comparison

| Approach       | Time  | Space |
| -------------- | ----- | ----- |
| Brute Force    | O(N²) | O(1)  |
| Sliding Window | O(N)  | O(1)  |

---

# ⚠️ Edge Cases

### Case 1

```text
Input: [1,1,1,1]

Output: 4
```

---

### Case 2

```text
Input: [0]

Output: 1
```

---

### Case 3

```text
Input: [0,0,0]

Output: 1
```

---

### Case 4

```text
Input: [1,0]

Output: 2
```

---

# ❌ Common Mistakes

* Using `if` instead of `while` when shrinking the window.
* Forgetting to decrease the zero count when the left pointer passes a zero.
* Using `nums.size()` instead of `nums.length` in Java.
* Using `max()` instead of `Math.max()` in Java.

---

# 🎯 Interview Explanation

If asked to explain:

> We maintain a sliding window that contains at most one zero because only one flip is allowed. The right pointer expands the window, and whenever the window becomes invalid (more than one zero), the left pointer shrinks it until it becomes valid again. Every valid window represents a possible answer, so we keep track of the maximum window size.

---

# 🧠 Pattern Recognition

This problem belongs to the **Variable Size Sliding Window** pattern.

### Key Indicators

* Find the **longest** or **maximum** subarray.
* Window validity depends on a condition.
* Shrink the window whenever the condition is violated.



---

# 💻 Cpp Solution

```c++

    public int findMaxConsecutiveOnes(int[] nums) {

        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int maxLen = 0;

        while(right < n) {

            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}
```

---

# 📝 Revision Notes

* Variable Size Sliding Window.
* Keep **at most one zero** inside the window.
* Expand using the right pointer.
* Shrink using the left pointer while the window is invalid.
* Update the answer after every valid window.
* Time Complexity: **O(N)**
* Space Complexity: **O(1)**

---

# 📚 Key Learnings

* Convert a "flip at most one element" problem into a sliding window constraint.
* Track constraint violations using a counter (`zeroCount`).
* Always use a `while` loop to restore window validity.
* Sliding Window often reduces quadratic solutions to linear time.


