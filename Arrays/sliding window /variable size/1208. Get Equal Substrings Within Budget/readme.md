# 1208. Get Equal Substrings Within Budget

> **Difficulty:** Medium  
> **Pattern:** Variable Size Sliding Window, Two Pointers

---

# 🧩 Problem Summary

Given two strings `s` and `t` of the same length and an integer `maxCost`.

Changing `s[i]` to `t[i]` costs:

```cpp
abs(s[i] - t[i])
```

Return the **maximum length substring** that can be converted within the given budget.

---

# 💡 Intuition

Instead of comparing characters, calculate the **cost of converting** each character.

Example:

```text
s = abcd
t = bcdf
```

Cost Array:

```text
[1, 1, 1, 2]
```

Now the problem becomes:

> Find the **Longest Subarray** whose **sum of costs ≤ maxCost**.

This is a classic **Variable Size Sliding Window** problem.

---

# ❌ Brute Force

Generate every possible substring.

For every substring:

- Calculate total conversion cost.
- If cost ≤ maxCost, update answer.

### Time Complexity

```text
O(N²)
```

---

# ✅ Optimal Approach (Sliding Window)

Maintain a window `[i...j]`.

- Expand the window by moving `j`.
- Add current conversion cost.
- If total cost exceeds `maxCost`, shrink the window from the left.
- Update maximum window length.

---

# 🔄 Algorithm

1. Initialize `i = 0`, `j = 0`
2. Maintain `currentCost`
3. Expand window
4. Add

```cpp
abs(s[j] - t[j])
```

5. While cost exceeds budget

```cpp
currentCost -= abs(s[i] - t[i]);
i++;
```

6. Update answer

---

# ✨ Dry Run

### Input

```text
s = "abcd"
t = "bcdf"
maxCost = 3
```

Cost Array

```text
[1,1,1,2]
```

### Step 1

Window

```text
[1]
```

Cost = 1 ✅

Answer = 1

---

### Step 2

Window

```text
[1,1]
```

Cost = 2 ✅

Answer = 2

---

### Step 3

Window

```text
[1,1,1]
```

Cost = 3 ✅

Answer = 3

---

### Step 4

Window

```text
[1,1,1,2]
```

Cost = 5 ❌

Shrink

Remove first cost

```text
5 - 1 = 4
```

Still greater

Remove second cost

```text
4 - 1 = 3
```

Window becomes

```text
[1,2]
```

Answer remains

```text
3
```

---

# ✅ Correct Code

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int n = s.length();

        int i = 0, j = 0;
        int currentCost = 0;
        int maxLength = 0;

        while (j < n) {

            currentCost += abs(s[j] - t[j]);

            while (currentCost > maxCost) {
                currentCost -= abs(s[i] - t[i]);
                i++;
            }

            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};
```

---

# ❌ Mistake I Made

I wrote:

```cpp
while(currentCost > maxCost)
{
    currentCost--;
    i++;
}
```

### Why is it Wrong?

I assumed removing one character decreases the cost by **1**.

But every character has a **different conversion cost**.

Example:

```text
Cost Array

[5,2,8]
```

Total Cost

```text
15
```

Removing the first element should give

```text
15 - 5 = 10
```

NOT

```text
15 - 1 = 14
```

Hence,

```cpp
currentCost--;
```

is incorrect.

---

# ⭐ Key Observation

The value entering the window is

```cpp
abs(s[j] - t[j])
```

Therefore, the value leaving the window must also be

```cpp
abs(s[i] - t[i])
```

Golden Rule:

```cpp
Window Expand
sum += value;

Window Shrink
sum -= same value;
```

---

# Interview Explanation 
In this problem, I first observed that instead of comparing the characters directly, I only need the cost required to convert each character of s into t, which is abs(s[i] - t[i]). This converts the problem into finding the longest contiguous subarray whose total cost is less than or equal to maxCost. Since all conversion costs are non-negative, I used the Variable Size Sliding Window approach. I maintain two pointers, i and j, along with a running sum of the current window's cost. I expand the window by moving j and adding the current conversion cost. Whenever the total cost exceeds maxCost, I shrink the window from the left by subtracting the cost of the character leaving the window and moving i forward. During this process, I keep updating the maximum valid window length. This approach visits each element at most twice, giving a time complexity of O(N) and a space complexity of O(1).

# 🧠 Interview Takeaway

Whenever solving a **Variable Size Sliding Window** problem, ask yourself:

### Question 1

**What value am I adding into the window?**

### Question 2

**When shrinking the window, what exactly should I remove?**

The answer should always be:

> **Remove the same value that was added earlier.**

---

# ⏱ Complexity Analysis

**Time Complexity:** `O(N)`

**Space Complexity:** `O(1)`

---

