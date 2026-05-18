# 🔢 Longest Consecutive Sequence

> **LeetCode Problem #128** | Difficulty: `Medium` | Topic: `Arrays` `Hash Set`

---

## 📌 Problem Statement

Given an unsorted array of integers `nums`, return the **length of the longest consecutive elements sequence**.

You must write an algorithm that runs in **O(n)** time.

### Example

```
Input:  nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive sequence is [1, 2, 3, 4].

Input:  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest consecutive sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8].
```

### Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## 🧠 Approaches

---

### ✅ Approach 1 — Brute Force (Sorting)

#### 💡 Intuition

Sort the array first so consecutive elements are adjacent. Then do a single linear scan to count streaks, skipping duplicates.

#### 🔍 Algorithm

1. Handle the edge case where `nums` is empty → return `0`.
2. Sort the array.
3. Iterate from index `1` to `n-1`:
   - If `nums[i] == nums[i-1]` → duplicate, skip.
   - If `nums[i] - nums[i-1] == 1` → consecutive, increment counter.
   - Otherwise → streak broken, reset counter to `1`.
4. Track and return the maximum streak seen.

#### 💻 Code (C++)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int cnt = 1;
        int longest = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;                    // skip duplicate
            } else if (nums[i] - nums[i - 1] == 1) {
                cnt++;                       // extend streak
            } else {
                cnt = 1;                     // reset streak
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
```

#### ⏱️ Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(n log n)` — dominated by sorting |
| **Space** | `O(1)` — in-place sort, no extra data structures |

#### ⚠️ Limitations

- Does **not** satisfy the `O(n)` requirement from the problem.
- Sorting modifies the original array.

---

### 🚀 Approach 2 — Optimal (Hash Set)

#### 💡 Intuition

Use an `unordered_set` for O(1) lookups. For each number, only **start counting** if it's the beginning of a sequence (i.e., `num - 1` does not exist in the set). This ensures each sequence is processed only once.

#### 🔍 Algorithm

1. Insert all elements into an `unordered_set` (handles duplicates automatically).
2. Iterate over each element in the set:
   - Check if `it - 1` exists in the set.
   - If **not** → `it` is the start of a new sequence.
   - Count how far the sequence extends using a `while` loop.
   - Update `longest` accordingly.
3. Return `longest`.

#### 💻 Code (C++)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (auto it : st) {
            // Only start a sequence from its smallest element
            if (st.find(it - 1) == st.end()) {
                int current = it;
                int cnt = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
```

#### ⏱️ Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(n)` — each element is visited at most twice (once during set iteration, once during `while` extension) |
| **Space** | `O(n)` — for the hash set |

#### ✅ Why This is Optimal

- Satisfies the problem's `O(n)` time constraint.
- The key insight: by only starting sequences at their **minimum element**, we avoid redundant work. Each number is part of exactly one sequence traversal.

---

## 📊 Comparison Table

| | Brute Force | Optimal |
|---|---|---|
| **Strategy** | Sort + Linear Scan | Hash Set |
| **Time Complexity** | `O(n log n)` | `O(n)` |
| **Space Complexity** | `O(1)` | `O(n)` |
| **Handles Duplicates** | ✅ (skip logic) | ✅ (set deduplication) |
| **Modifies Input** | ✅ Yes (sorts array) | ❌ No |
| **Meets O(n) Requirement** | ❌ | ✅ |

---

## 🗂️ Related Problems

| Problem | Difficulty |
|---|---|
| [Missing Number](https://leetcode.com/problems/missing-number/) | Easy |
| [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | Easy |
| [Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence/) | Medium |

---

## 🏷️ Tags

`Array` `Hash Table` `Union Find` `Sorting`

---

*LeetCode #128 — Longest Consecutive Sequence*
