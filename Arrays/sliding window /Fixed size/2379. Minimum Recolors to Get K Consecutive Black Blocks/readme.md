# 2379. Minimum Recolors to Get K Consecutive Black Blocks

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Easy |
| Topic | Strings |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/ |
| Companies | Amazon, Google, Microsoft |

---

# 📝 Problem Statement

You are given a string `blocks` consisting of `'W'` (White) and `'B'` (Black) blocks.

In one operation, you can recolor a white block into a black block.

Return the **minimum number of recolors** required so that there exists **at least one substring of length `k` consisting entirely of black blocks**.

---

# 💡 Intuition

A substring of length `k` becomes completely black if **all white blocks inside it are recolored**.

Therefore, for every window of size `k`, we only need to count:

> **How many white blocks (`'W'`) are present?**

The window having the **minimum number of white blocks** requires the fewest recoloring operations.

Since the window size is fixed, this is a **Fixed Size Sliding Window** problem.

---

# 👀 Observations

- Every valid window has exactly `k` blocks.
- Black blocks require no operation.
- White blocks must be recolored.
- The answer is simply the **minimum number of `'W'`** in any window of size `k`.

---

# 📋 Constraints

- `1 <= n <= 100`
- `blocks[i]` is either `'W'` or `'B'`
- `1 <= k <= n`

Although `n` is small, Sliding Window provides the optimal and most scalable solution.

---

# 🐢 Approach 1 — Brute Force

## Idea

Generate every substring of length `k`.

For each substring:

- Count the number of white blocks.
- Keep the minimum count.

---

## Algorithm

1. Generate every window of size `k`.
2. Count `'W'` in the window.
3. Update the minimum answer.
4. Return the minimum.

---

## Dry Run

```
blocks = "WBWBBBW"

k = 2

WB -> 1

BW -> 1

WB -> 1

BB -> 0

BB -> 0

BW -> 1

Answer = 0
```

---

## Time Complexity

```
O((n-k+1) × k)
```

---

## Space Complexity

```
O(k)
```

---

## Why is it inefficient?

For every window, we recount all `k` characters even though adjacent windows overlap.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Instead of recounting white blocks in every window:

- Maintain the number of white blocks in the current window.
- When the window slides:
  - Remove the outgoing character.
  - Add the incoming character.
- Track the minimum white count.

This avoids repeatedly scanning the same characters.

> **Note:** Your current solution uses a sliding window but still iterates through all `k` characters in every window, making it **O(n × k)**. The optimal sliding window maintains the white count incrementally and runs in **O(n)**.

---

## Algorithm

1. Count white blocks in the first window.
2. Store it as the initial answer.
3. Slide the window:
   - If the outgoing block is white, decrement the count.
   - If the incoming block is white, increment the count.
4. Update the minimum white count.
5. Return the minimum.

---

## Dry Run

### Input

```
blocks = "WBBWWBBWBW"

k = 7
```

First Window

```
WBBWWBB

White = 3

Minimum = 3
```

Slide

```
BBWWBBW

White = 3
```

Slide

```
BWWBBWB

White = 4
```

Slide

```
WWBBWBW

White = 4
```

Minimum White Count

```
3
```

Answer

```
3
```

---

## Time Complexity

### Current Solution

```
O(n × k)
```

### Optimal Sliding Window

```
O(n)
```

---

## Space Complexity

### Current Solution

```
O(k)
```

### Optimal Sliding Window

```
O(1)
```

---

## Why does this approach work?

The only information needed for each window is the number of white blocks.

When the window moves:

```
New White Count

=

Previous White Count

- Outgoing White

+ Incoming White
```

Each character enters and leaves the window exactly once, resulting in an **O(n)** solution.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O((n-k+1) × k) | O(k) |
| Your Solution | O(n × k) | O(k) |
| Optimal Sliding Window | O(n) | O(1) |

---

# ⚠️ Edge Cases

- `k = 1`
- `k = n`
- All blocks are black.
- All blocks are white.
- Only one block.
- Multiple windows having the same minimum recolors.

---

# ❌ Common Mistakes

### Mistake 1

Recounting white blocks for every window.

```cpp
for(int p = 0; p < k; p++)
{
    if(str[p] == 'W')
        cnt++;
}
```

This increases the complexity to **O(n × k)**.

---

### Mistake 2

Storing the entire substring.

```cpp
string str;
```

Only the count of white blocks is needed.

---

### Mistake 3

Forgetting to reset the white count.

```cpp
cnt = 0;
```

If not reset (or maintained correctly), the answer becomes incorrect.

---

# 🎤 Interview Explanation

> Since the window size is fixed (`k`), I use a Fixed Size Sliding Window. The number of recolors needed for a window is simply the number of white blocks inside it. I first count the white blocks in the initial window and then slide the window one position at a time, updating the white count by removing the outgoing block and adding the incoming block. The minimum white count across all windows is the answer. This achieves O(n) time complexity.

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Fixed Size Sliding Window
- ✅ String Traversal
- ✅ Running Count

---



# 📚 Key Learnings

- Minimum recolors = minimum white blocks in any window.
- Fixed-size Sliding Window is ideal.
- Maintain only the white count.
- Avoid storing substrings unnecessarily.
- Update counts incrementally for O(n) complexity.

---

# 💻 C++17 Solution (Your Solution)

```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();

        int i = 0, j = 0;

        int cnt = 0;
        int mini = INT_MAX;

        string str = "";

        while (j < n) {

            str += blocks[j];

            if (j - i + 1 == k) {

                for (int p = 0; p < k; p++) {
                    if (str[p] == 'W')
                        cnt++;
                }

                mini = min(mini, cnt);

                str.erase(0, 1);

                cnt = 0;

                i++;
            }

            j++;
        }

        return mini;
    }
};
```

---

# ⭐ Revision Notes

- Window size = `k`.
- Count white blocks.
- Answer = minimum white count.
- Current solution → **O(n × k)**.
- Optimal solution → maintain white count incrementally (**O(n)**).
- No need to store the entire substring.
- Time → **O(n)** *(optimal)*
- Space → **O(1)** *(optimal)*

---

