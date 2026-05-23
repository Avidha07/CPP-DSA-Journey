# 283. Move Zeroes

![LeetCode](https://img.shields.io/badge/LeetCode-Easy-brightgreen) ![Topic](https://img.shields.io/badge/Topic-Two%20Pointers-blue) ![Topic](https://img.shields.io/badge/Topic-Array-blue)

## Problem Statement

Given an integer array `nums`, move all `0`s to the end of it while maintaining the **relative order** of the non-zero elements.

> **Note:** You must do this **in-place** without making a copy of the array.

### Examples

```
Input:  nums = [1, 0, 2, 3, 2, 0, 0, 4, 5, 1]
Output: nums = [1, 2, 3, 2, 4, 5, 1, 0, 0, 0]

Input:  nums = [0]
Output: nums = [0]

Input:  nums = [0, 1, 0, 3, 12]
Output: nums = [1, 3, 12, 0, 0]
```

---

## Approach 1 — Brute Force (Extra Array)

### Intuition

Copy all non-zero elements into a temporary array, write them back to the start of `nums`, then fill the remaining positions with zeros.

### Algorithm

1. Create a temporary array `v` of size `N`, initialized to `0`.
2. Traverse `nums` and copy every non-zero element into `v` in order.
3. Copy `v` back into `nums`.

Since `v` was pre-filled with zeros, the trailing positions are automatically correct.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        int ind = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                v[ind] = nums[i];
                ind++;
            }
        }

        for (int i = 0; i < n; i++) {
            nums[i] = v[i];
        }
    }
};
```

### Complexity

| | Complexity |
|---|---|
| **Time** | O(N) |
| **Space** | O(N) — extra array of size N |

---

## Approach 2 — Optimal (Two Pointers)

### Intuition

Instead of using extra space, use two pointers directly on `nums`:

- Pointer **`j`** tracks the position of the first (and next available) zero.
- Pointer **`i`** scans ahead looking for non-zero elements.

Whenever `i` finds a non-zero element, swap `nums[i]` with `nums[j]`, then advance `j`. This pushes non-zero values to the front and zeros to the back — all in-place.

### Why Does `i` Start at `j + 1`?

`j` is the index of the **first zero** in the array.  
This means every element before `j` (indices `0` to `j-1`) is already non-zero — that prefix is already correct and needs no work.  
Starting `i` at `j + 1` skips the known-good prefix and begins scanning from the very next element after the first zero, saving unnecessary comparisons.

### Algorithm

1. Iterate through `nums` to find the index `j` of the first `0`.
2. If no zero exists (`j == -1`), the array is already sorted — return early.
3. Set `i = j + 1` and scan forward.
4. Whenever `nums[i] != 0`, swap `nums[i]` with `nums[j]` and increment `j`.
5. Repeat until `i` reaches the end.

### Dry Run

```
nums = [1, 0, 2, 3, 2, 0, 0, 4, 5, 1]
         ^
         j = 1  (first zero found)
         i starts at 2

Step 1: i=2, nums[2]=2 → swap(nums[2], nums[1]) → [1, 2, 0, 3, 2, 0, 0, 4, 5, 1], j=2
Step 2: i=3, nums[3]=3 → swap(nums[3], nums[2]) → [1, 2, 3, 0, 2, 0, 0, 4, 5, 1], j=3
Step 3: i=4, nums[4]=2 → swap(nums[4], nums[3]) → [1, 2, 3, 2, 0, 0, 0, 4, 5, 1], j=4
Step 4: i=5, nums[5]=0 → skip
Step 5: i=6, nums[6]=0 → skip
Step 6: i=7, nums[7]=4 → swap(nums[7], nums[4]) → [1, 2, 3, 2, 4, 0, 0, 0, 5, 1], j=5
Step 7: i=8, nums[8]=5 → swap(nums[8], nums[5]) → [1, 2, 3, 2, 4, 5, 0, 0, 0, 1], j=6
Step 8: i=9, nums[9]=1 → swap(nums[9], nums[6]) → [1, 2, 3, 2, 4, 5, 1, 0, 0, 0], j=7

Output: [1, 2, 3, 2, 4, 5, 1, 0, 0, 0] ✓
```

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;

        // Step 1: Find the first zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // Step 2: No zeros found — already done
        if (j == -1) return;

        // Step 3: i always starts from j+1
        // because everything before j is already non-zero
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

### Complexity

| | Complexity |
|---|---|
| **Time** | O(N) |
| **Space** | O(1) — no extra space used |

---

## Comparison

| | Brute Force | Optimal |
|---|---|---|
| **Time** | O(N) | O(N) |
| **Space** | O(N) | O(1) |
| **In-place** | ✗ | ✓ |
| **Extra array** | Yes | No |

---

## Key Takeaway

> The two-pointer technique avoids allocating extra memory by using `j` as a "write cursor" for non-zero values and `i` as a "read cursor" that scans ahead. The invariant is: everything to the left of `j` is non-zero; `j` always points to the next zero slot waiting to be filled.
