# 1493. Longest Subarray of 1's After Deleting One Element

## 🔗 Problem Information

- **Platform:** LeetCode
- **Problem Number:** 1493
- **Difficulty:** Medium
- **Topic:** Array, Sliding Window, Two Pointers
- **Pattern:** Variable Size Sliding Window

---

# Problem Statement

Given a binary array `nums`, delete **exactly one element** from the array.

Return the length of the longest non-empty subarray containing only `1`s after deleting one element.

If there is no such subarray, return `0`.

---

# Intuition

Deleting a `0` can merge two consecutive groups of `1`s into one larger group.

Therefore, instead of actually deleting an element, we maintain a sliding window that contains **at most one zero**.

Whenever the window contains more than one zero, we shrink it from the left until it becomes valid again.

Since one deletion is mandatory, the answer for every valid window is:

```
Window Length - 1
```

---

# Observations

- We can delete **only one element**.
- The best deletion is usually deleting a `0`.
- If the array contains all `1`s, we still must delete one `1`.
- Therefore, every valid window can contain **at most one zero**.

---

# Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`

---

# Approach 1 — Brute Force

### Idea

Try deleting every element one by one.

For every deletion:

- Construct the new array.
- Find the longest consecutive sequence of `1`s.

### Complexity

- **Time:** `O(n²)`
- **Space:** `O(n)`

---

# Approach 2 — Better

Not required.

The optimal sliding window solution directly solves the problem in linear time.

---

# Approach 3 — Optimal (Variable Size Sliding Window)

## Idea

Maintain a sliding window having **at most one zero**.

### Expand

Move the right pointer.

- If `nums[right] == 0`
  - Increment `zeroCount`.

### Shrink

Whenever

```
zeroCount > 1
```

Move the left pointer until the window again contains only one zero.

### Calculate Answer

Current window size

```
right - left + 1
```

Since one deletion is mandatory,

```
Answer = Window Size - 1
```

which simplifies to

```
right - left
```

---

# Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(n) |
| Optimal Sliding Window | O(n) | O(1) |

---

# Edge Cases

### Case 1

```
nums = [1,1,1]
```

Delete one `1`.

Output

```
2
```

---

### Case 2

```
nums = [0]
```

Delete the only element.

Output

```
0
```

---

### Case 3

```
nums = [0,0,0]
```

Output

```
0
```

---

### Case 4

```
nums = [1,1,0,1]
```

Delete the zero.

Output

```
3
```

---

# Common Mistakes

### ❌ Forgetting that deletion is mandatory

For

```
[1,1,1]
```

Answer is **2**, not **3**.

---

### ❌ Allowing more than one zero inside the window

The window must always satisfy

```
zeroCount <= 1
```

---

### ❌ Returning window size directly

Wrong

```cpp
ans = max(ans, right - left + 1);
```

Correct

```cpp
ans = max(ans, right - left);
```

because

```
(window size) - 1
=
(right-left+1)-1
=
right-left
```

---

# Interview Explanation

If asked in an interview:

> We maintain a sliding window containing at most one zero. This represents deleting that zero to make the entire window consist of `1`s. If another zero enters the window, we shrink it until only one zero remains. Since one deletion is compulsory, the answer for every valid window is `(window size - 1)`.

---

# Pattern Recognition

This is a classic

- Variable Size Sliding Window
- At Most K Bad Elements

Here,

```
K = 1 zero
```

Whenever you see problems like:

- Flip at most K zeros
- Replace at most K characters
- Delete one element
- Allow at most K mismatches

Think about **Variable Size Sliding Window**.

---

# Key Learnings

- Maintain a window satisfying the given constraint.
- Shrink the window only when it becomes invalid.
- For mandatory deletion problems, adjust the answer accordingly.
- Sometimes the formula can be simplified mathematically:

```
(window size - 1)

↓

(right-left+1)-1

↓

right-left
```
The window size is right - left + 1, but one deletion is mandatory. Since every valid window contains at most one zero, the answer after deleting one element is (right - left + 1) - 1, which simplifies to right - left.

---

# C++17 Solution

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int right = 0;

        int zeroCount = 0;
        int ans = 0;

        while (right < n) {

            if (nums[right] == 0)
                zeroCount++;

            while (zeroCount > 1) {

                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            ans = max(ans, right - left);

            right++;
        }

        return ans;
    }
};
```

---

# Revision Notes

- Maintain **at most one zero** inside the window.
- Shrink whenever `zeroCount > 1`.
- Final answer is `right - left`.
- Remember that **one deletion is compulsory**, even if all elements are `1`.

---
