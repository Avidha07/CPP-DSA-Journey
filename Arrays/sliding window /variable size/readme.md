# Variable Size Sliding Window

> A complete guide to understanding the **Variable Size Sliding Window** pattern used in coding interviews and competitive programming.

---

# 📌 What is Variable Size Sliding Window?

A **Variable Size Sliding Window** is a technique where the **window size is not fixed**.

Unlike the Fixed Size Sliding Window, here the window **expands** and **shrinks dynamically** depending on the given condition.

The window is represented using two pointers:

- `i` → Left pointer (Start of window)
- `j` → Right pointer (End of window)

The window keeps changing its size while traversing the array/string.

---

# 📖 Example

Consider the array:

```text
[a b c d e f]
```

Possible windows can be:

```text
[a]
[ab]
[abc]
[b]
[bc]
[bcde]
[cd]
[cdef]
```

Notice that the window size is **not fixed**.

---

# 🎯 When to Use Variable Sliding Window?

Use this technique whenever the problem asks for:

- Longest Subarray
- Longest Substring
- Maximum Length
- Minimum Window
- Smallest Subarray
- Exactly K
- At Most K
- Distinct Characters
- Frequency Constraints

---

# 🧠 General Algorithm

```cpp
int i = 0;
int j = 0;

while (j < n)
{
    // Include current element
    add(nums[j]);

    // Shrink window if condition becomes invalid
    while (window becomes invalid)
    {
        remove(nums[i]);
        i++;
    }

    // Update answer
    updateAnswer();

    // Expand window
    j++;
}
```

---

# ⭐ Golden Rule

Always remember this order:

```text
Expand
   ↓
Check
   ↓
Shrink
   ↓
Update Answer
```

or simply

```text
Expand → Check → Shrink → Update
```

This sequence solves almost every Variable Sliding Window problem.

---

# 🟢 Pattern 1 : Longest Valid Window

## Goal

Find the **maximum/longest** window satisfying a condition.

### Examples

| LeetCode # | Problem |
|------------|---------|
| 3 | Longest Substring Without Repeating Characters |
| 1004 | Max Consecutive Ones III |
| 424 | Longest Repeating Character Replacement |
| 904 | Fruit Into Baskets |
| 1493 | Longest Subarray of 1's After Deleting One Element |
| 2024 | Maximize the Confusion of an Exam |
| 1695 | Maximum Erasure Value |
| 1838 | Frequency of the Most Frequent Element |


---

## Template

```cpp
int i = 0;
int j = 0;

while (j < n)
{
    add(nums[j]);

    while (window is invalid)
    {
        remove(nums[i]);
        i++;
    }

    ans = max(ans, j - i + 1);

    j++;
}
```

### Logic

```text
Expand Window

↓

Condition Invalid?

↓

Yes → Shrink Window

↓

Condition Valid?

↓

Update Maximum Answer
```

---

# 🔵 Pattern 2 : Minimum Valid Window

## Goal

Find the **smallest/minimum** window satisfying a condition.

### Examples
| LeetCode # | Problem |
|------------|---------|
| 76 | Minimum Window Substring |
| 209 | Minimum Size Subarray Sum |
| 862 | Shortest Subarray with Sum at Least K *(uses Prefix Sum + Deque)* |

> **Note:** Problem **862** is not a pure sliding window problem because it involves negative numbers and is solved using **Prefix Sum + Monotonic Deque**.

---

## Template

```cpp
int i = 0;
int j = 0;

while (j < n)
{
    add(nums[j]);

    while (window is valid)
    {
        ans = min(ans, j - i + 1);

        remove(nums[i]);
        i++;
    }

    j++;
}
```

### Logic

```text
Expand Window

↓

Condition Valid?

↓

Yes → Update Minimum Answer

↓

Shrink Window

↓

Still Valid?

↓

Keep Shrinking

↓

Invalid?

↓

Expand Again
```

---

# 🟣 Pattern 3 : Exactly K

Many interview problems ask for **Exactly K**.

Instead of solving directly,

use

```text
Exactly(K) = AtMost(K) - AtMost(K - 1)
```

---

## Formula

```text
Exactly K
=
AtMost(K)
-
AtMost(K-1)
```

---

## Examples

| LeetCode # | Problem |
|------------|---------|
| 992 | Subarrays with K Different Integers |
| 1248 | Count Number of Nice Subarrays |
| 930 | Binary Subarrays With Sum |
| 3306 | Count of Substrings Containing Every Vowel and K Consonants II |
| 3305 | Count of Substrings Containing Every Vowel and K Consonants I |

---

# 📊 Complexity

| Operation | Complexity |
|-----------|------------|
| Left Pointer | O(N) |
| Right Pointer | O(N) |
| Overall Time Complexity | **O(N)** |
| Space Complexity | Depends on the Data Structure Used |

Since both pointers move only in the forward direction, each element is processed at most twice.

---

# 🔥 Common Mistakes

❌ Forgetting to remove elements while shrinking.

❌ Updating the answer before fixing an invalid window.

❌ Using `max()` for minimum window problems.

❌ Shrinking only once instead of using a `while` loop.

❌ Confusing **Exactly K** with **At Most K**.

---
# 🎯 Decision Tree

```text
                Sliding Window
                      │
         ┌────────────┴────────────┐
         │                         │
     Fixed Size             Variable Size
                                   │
          ┌────────────┬────────────┬────────────┐
          │            │            │
      Longest      Minimum      Exactly K
     (Pattern 1)  (Pattern 2)  (Pattern 3)
```

---

