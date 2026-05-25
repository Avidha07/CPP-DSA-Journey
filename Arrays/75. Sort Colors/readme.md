# Sort Colors — Dutch National Flag Problem

> **LeetCode 75** · Array · Two Pointers · Medium

---

## Problem Statement

Given an array `nums` containing only `0`s, `1`s, and `2`s, sort it **in-place** so that all `0`s come first, followed by all `1`s, then all `2`s — without using the built-in sort function.

**Example:**
```
Input:  [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

---

## Approaches

### 🔴 Brute Force — Count + Overwrite (while loop)

**Intuition:** Count how many 0s, 1s, and 2s exist. Then overwrite the array using those counts.

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)      zero++;
            else if (nums[i] == 1) one++;
            else                   two++;
        }

        int k = 0;
        while (zero--) nums[k++] = 0;
        while (one--)  nums[k++] = 1;
        while (two--)  nums[k++] = 2;
    }
};
```

**Algorithm:**
1. Traverse the array and count the frequency of `0`, `1`, and `2`.
2. Use three `while` loops to overwrite the array — first with `zero` 0s, then `one` 1s, then `two` 2s.

| Complexity | Value |
|------------|-------|
| Time       | O(2n) — two passes |
| Space      | O(1) — only three counters |

---

### 🟡 Better — Count + Overwrite (for loop)

**Intuition:** Functionally identical to brute force. Instead of `while(zero--)`, uses `for` loops with an index range per value. The result and complexity are the same.

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)      zero++;
            else if (nums[i] == 1) one++;
            else                   two++;
        }

        for (int i = 0; i < zero; i++)
            nums[i] = 0;
        for (int i = zero; i < zero + one; i++)
            nums[i] = 1;
        for (int i = zero + one; i < nums.size(); i++)
            nums[i] = 2;
    }
};
```

> ⚠️ **Note:** The brute and better approaches here are algorithmically identical — both do two passes and use O(1) space. The distinction is only stylistic (while vs for loop). The true improvement comes in the optimal approach below.

| Complexity | Value |
|------------|-------|
| Time       | O(2n) — two passes |
| Space      | O(1) |

---

### 🟢 Optimal — Dutch National Flag Algorithm (One Pass)

**Intuition:** Since the array has only three distinct values (0, 1, 2), we can use three pointers to partition the array into three zones in a **single pass** — without counting anything first.

```
Zone 1: [0, low)     → all 0s  (sorted)
Zone 2: [low, mid)   → all 1s  (sorted)
Zone 3: (high, n-1]  → all 2s  (sorted)
Zone 4: [mid, high]  → unsorted (actively being processed)
```

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
                // mid is NOT incremented here — the swapped value needs re-checking
            }
        }
    }
};
```

**Algorithm:**
1. Start with `low = 0`, `mid = 0`, `high = n - 1`.
2. While `mid <= high`:
   - `nums[mid] == 0` → swap with `nums[low]`, move both `low` and `mid` forward.
   - `nums[mid] == 1` → already in place, move `mid` forward.
   - `nums[mid] == 2` → swap with `nums[high]`, move `high` backward (**do not** move `mid` — the incoming element needs to be re-checked).
3. Stop when `mid > high` — all zones are correctly filled.

**Why not move `mid` after swapping with `high`?**

When you swap `nums[mid]` with `nums[high]`, the value coming from the right could be a `0`, `1`, or `2` — it hasn't been checked yet. If you move `mid` forward, you'd skip evaluating it. So `mid` stays and re-evaluates the swapped value in the next iteration.

| Complexity | Value |
|------------|-------|
| Time       | O(n) — **single pass** |
| Space      | O(1) — in-place with only 3 pointers |

---

## Why Three Approaches If All Are O(n)?

A common question — if all three have O(n) time and O(1) space, why does the progression matter?

| Approach | Passes | Why It Matters |
|----------|--------|----------------|
| Brute / Better | **2 passes** — one to count, one to overwrite | Simple to understand but reads the array twice |
| Optimal | **1 pass** | Processes each element exactly once; no second scan needed |

The pedagogical goal of brute → better → optimal is to train the **thought process** of incremental refinement. In an interview, demonstrating that you can arrive at the one-pass Dutch National Flag solution shows:

- Awareness of pointer-based partitioning techniques.
- Understanding of *why* `mid` doesn't move on a `2` swap (a subtle invariant that interviewers test).
- Ability to reduce the number of array traversals even when the asymptotic class is the same.

O(n) vs O(2n) is the same asymptotic class, but in competitive programming and systems programming, **reducing constant factors and cache misses** from multiple passes can matter in practice.

---

## Dutch National Flag — Visual Walkthrough

```
Input: [2, 0, 2, 1, 1, 0]
        low=0, mid=0, high=5

Step 1: nums[0]=2 → swap(mid,high) → [0,0,2,1,1,2], high=4
Step 2: nums[0]=0 → swap(mid,low) → [0,0,2,1,1,2], low=1,mid=1
Step 3: nums[1]=0 → swap(mid,low) → [0,0,2,1,1,2], low=2,mid=2
Step 4: nums[2]=2 → swap(mid,high) → [0,0,1,1,2,2], high=3
Step 5: nums[2]=1 → mid=3
Step 6: nums[3]=1 → mid=4 → mid > high → STOP

Output: [0, 0, 1, 1, 2, 2] ✅
```

---

## Key Takeaways

- The **counting approach** (brute/better) is intuitive but requires two passes.
- The **Dutch National Flag** algorithm solves it in one pass using three pointers.
- The subtle invariant: **do not advance `mid` when swapping with `high`** — this is the most common mistake.
- All approaches use O(1) extra space (no auxiliary array needed).

---

## Related Problems

- [LeetCode 283 — Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [LeetCode 905 — Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)
- [LeetCode 215 — Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
