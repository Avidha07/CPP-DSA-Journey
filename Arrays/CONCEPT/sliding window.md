# 🪟 Sliding Window Technique

A complete guide to understanding and mastering the Sliding Window algorithm — from brute force to optimized approach.

---

## 📋 Table of Contents

- [Problem Statement](#-problem-statement)
- [Brute Force Approach](#-brute-force-approach)
- [The Problem with Brute Force](#-the-problem-with-brute-force)
- [Origin of Sliding Window](#-origin-of-sliding-window)
- [How to Identify Sliding Window Problems](#-how-to-identify-sliding-window-problems)
- [Types of Sliding Window](#-types-of-sliding-window)
- [Complexity Analysis](#-complexity-analysis)
- [Example Walkthrough](#-example-walkthrough)

---

## 📌 Problem Statement

Given an array:

```
2  3  5  2  9  7  1
```

**Tasks:**
1. Find all subarrays of length `k = 3`
2. Find the sum of each subarray
3. Return the **maximum sum** among all subarrays

**Expected Output:** `18` → from subarray `[2, 9, 7]`

---

## 💪 Brute Force Approach

Use nested loops to calculate the sum of every subarray of size `k`.

```cpp
int maxSumBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;

        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}
```

### Subarrays of size `3`:

| Subarray | Elements    | Sum |
|----------|-------------|-----|
| S1       | [2, 3, 5]   | 10  |
| S2       | [3, 5, 2]   | 10  |
| S3       | [5, 2, 9]   | 16  |
| S4       | [2, 9, 7]   | **18** |
| S5       | [9, 7, 1]   | 17  |

✅ **Maximum Sum = `18`**

---

## ⚠️ The Problem with Brute Force

The brute force approach performs **redundant calculations**:

```
S1 = 2 + [3 + 5]
S2 =     [3 + 5] + 2      ← 3+5 recalculated!
S3 =         [5 + 2] + 9  ← 5+2 recalculated!
```

Elements in the overlapping region are computed multiple times — this is **wasteful**.

**Instead**, we can:
- ➕ **Add** the new incoming element (right side)
- ➖ **Subtract** the outgoing element (left side)

The window stays **contiguous** and simply **slides** one step at a time.

---

## 💡 Origin of Sliding Window

The **Sliding Window** technique eliminates redundant work by reusing the previous window's sum.

```
Window 1:  [2, 3, 5]        sum = 10
Window 2:  [3, 5, 2]        sum = 10 - 2 + 2 = 10  ← subtract 2 (left), add 2 (right)
Window 3:  [5, 2, 9]        sum = 10 - 3 + 9 = 16  ← subtract 3 (left), add 9 (right)
Window 4:  [2, 9, 7]        sum = 16 - 5 + 7 = 18  ← subtract 5 (left), add 7 (right)
Window 5:  [9, 7, 1]        sum = 18 - 2 + 1 = 17  ← subtract 2 (left), add 1 (right)
```

> 💭 The window "slides" forward — that's where the name **Sliding Window** comes from.

---

## 🔍 How to Identify Sliding Window Problems

Look for these signals in a problem:

### 📦 Data Structures
- Array
- String

### 🔎 Keywords in the Problem
| Category | Keywords |
|----------|----------|
| Pattern  | subarray, substring, contiguous sequence |
| Objective | largest, smallest, maximum, minimum, longest, shortest |
| Window   | of size `k`, with sum `s`, at most `x` distinct, etc. |

### ✅ Quick Checklist
- [ ] Does it involve a **contiguous** part of an array/string?
- [ ] Is there an **optimization goal** (max, min, longest, shortest)?
- [ ] Is there a **constraint** on window size or content?

If **yes** to most → it's likely a **Sliding Window** problem.

---

## 📂 Types of Sliding Window

### 1. 🔒 Fixed Sliding Window

The window size **remains constant** throughout.

**Example Problem:** Find the maximum sum of a subarray of size `k`

```cpp
int maxSumFixed(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, maxi = INT_MIN;

    // Build the first window
    for (int i = 0; i < k; i++)
        sum += nums[i];

    maxi = sum;

    // Slide the window
    for (int i = k; i < n; i++) {
        sum += nums[i];       // Add incoming element
        sum -= nums[i - k];   // Remove outgoing element
        maxi = max(maxi, sum);
    }

    return maxi;
}
```

**Visual:**
```
[2  3  5] 2  9  7  1    → sum = 10
 2 [3  5  2] 9  7  1    → sum = 10
 2  3 [5  2  9] 7  1    → sum = 16
 2  3  5 [2  9  7] 1    → sum = 18 ✅
 2  3  5  2 [9  7  1]   → sum = 17
```

---

### 2. 🔓 Variable Sliding Window

The window size **changes dynamically** based on a condition.

**Example Problem:** Find the longest subarray with sum = `5`

```cpp
int longestSubarrayWithSum(vector<int>& nums, int target) {
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        // Shrink window if sum exceeds target
        while (sum > target) {
            sum -= nums[left];
            left++;
        }

        // Check if current window is valid
        if (sum == target)
            maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

**Key Difference:**
| | Fixed Window | Variable Window |
|---|---|---|
| Window Size | Always `k` | Expands / Shrinks |
| Shrink Condition | Never | Based on problem constraint |
| Use Case | Sum of size k, avg of k elements | Longest/shortest with condition |

---

## 📊 Complexity Analysis

| Approach | Time Complexity | Space Complexity |
|----------|----------------|-----------------|
| Brute Force | O(n × k) | O(1) |
| Sliding Window (Fixed) | O(n) | O(1) |
| Sliding Window (Variable) | O(n) | O(1) |

> 🚀 Sliding Window reduces time from **O(n × k)** to **O(n)** — a significant improvement for large inputs.

---

## 🧩 Example Walkthrough

**Array:** `[2, 3, 5, 2, 9, 7, 1]`, `k = 3`

```
Step 1: Build first window
        [2 + 3 + 5] = 10  →  maxi = 10

Step 2: Slide
        10 - 2 + 2 = 10   →  maxi = 10

Step 3: Slide
        10 - 3 + 9 = 16   →  maxi = 16

Step 4: Slide
        16 - 5 + 7 = 18   →  maxi = 18  ✅

Step 5: Slide
        18 - 2 + 1 = 17   →  maxi = 18  (no update)

Answer: 18
```

---

## 🗂️ Related Problems to Practice

### Fixed Window
- Maximum sum subarray of size `k`
- Average of all subarrays of size `k`
- Count of occurrences of anagram in a string

### Variable Window
- Longest substring without repeating characters
- Longest subarray with sum ≤ `k`
- Minimum window substring
- Fruits into baskets (at most 2 distinct)

---

## 📝 Summary

```
Brute Force         →  O(n × k)  — redundant work
Sliding Window      →  O(n)      — reuse previous computation

Fixed Window        →  window size = constant k
Variable Window     →  window expands/shrinks by condition
```

> **Core Idea:** Instead of recomputing from scratch, slide the window — add the new element, remove the old one.

---

*Happy Coding! 🚀*
