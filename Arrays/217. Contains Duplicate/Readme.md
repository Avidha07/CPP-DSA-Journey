# 217. Contains Duplicate

## Problem Statement

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is **distinct**.

### Examples

| Example | Input | Output | Reason |
|---------|-------|--------|--------|
| 1 | `nums = [1, 2, 3, 1]` | `true` | `1` appears at index 0 and 3 |
| 2 | `nums = [1, 2, 3, 4]` | `false` | All elements are distinct |
| 3 | `nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]` | `true` | Multiple duplicates exist |

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## Approaches

---

### Approach 1 — Brute Force

#### Intuition

Compare every pair `(i, j)` where `i < j`. If `nums[i] == nums[j]` at any point, a duplicate exists. This is the most straightforward idea but checks every combination.

#### Algorithm

1. Start outer loop `i` from index `0` to `n-2`.
2. Start inner loop `j` from `i+1` to `n-1`.
3. If `nums[i] == nums[j]`, return `true`.
4. If no match found after all iterations, return `false`.

#### Code (C++)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Dry Run

For `nums = [1, 2, 3, 1]`:

| i | j | nums[i] | nums[j] | Match? |
|---|---|---------|---------|--------|
| 0 | 1 | 1 | 2 | No |
| 0 | 2 | 1 | 3 | No |
| 0 | 3 | 1 | 1 | **Yes → return true** |

#### Complexity

| | Value |
|---|---|
| Time | **O(n²)** — nested loops comparing every pair |
| Space | **O(1)** — no extra data structure used |

---

### Approach 2 — Sorting (Better Approach)

#### Intuition

If you sort the array, any duplicate elements will end up **adjacent** to each other. You only need one pass to check neighbours.

#### Algorithm

1. Sort `nums` using `std::sort` — O(n log n).
2. Iterate from index `1` to `n-1`.
3. If `nums[i] == nums[i-1]`, a duplicate is found → return `true`.
4. If the loop ends without a match, return `false`.

#### Code (C++)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
```

#### Dry Run

For `nums = [1, 2, 3, 1]`:

- After sorting: `[1, 1, 2, 3]`

| i | nums[i] | nums[i-1] | Match? |
|---|---------|-----------|--------|
| 1 | 1 | 1 | **Yes → return true** |

#### Complexity

| | Value |
|---|---|
| Time | **O(n log n)** — dominated by the sort step |
| Space | **O(1)** or **O(log n)** — depends on sort's internal stack usage |

> ⚠️ **Side effect:** This approach modifies the original array. If the caller needs the original order preserved, you must make a copy first.

---

### Approach 3 — Hash Set (Optimal Approach)

#### Intuition

Use an `unordered_set` as a "seen so far" tracker. For each element, check if it already exists in the set:
- If yes → duplicate found → return `true`.
- If no → insert it and continue.

This gives O(1) average lookup and insert per element.

#### Algorithm

1. Create an empty `unordered_set<int> st`.
2. Loop through each element `nums[i]`.
3. If `nums[i]` is already in `st`, return `true`.
4. Otherwise, insert `nums[i]` into `st`.
5. If the loop ends with no match, return `false`.

#### Code (C++)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                return true;
            }
            else {
                st.insert(nums[i]);
            }
        }
        return false;
    }
};
```

#### Dry Run

For `nums = [1, 2, 3, 1]`:

| i | nums[i] | Set before | Found? | Set after |
|---|---------|------------|--------|-----------|
| 0 | 1 | `{}` | No | `{1}` |
| 1 | 2 | `{1}` | No | `{1, 2}` |
| 2 | 3 | `{1, 2}` | No | `{1, 2, 3}` |
| 3 | 1 | `{1, 2, 3}` | **Yes → return true** | — |

#### Complexity

| | Value |
|---|---|
| Time | **O(n)** — single pass; each lookup and insert is O(1) average |
| Space | **O(n)** — set can hold up to n elements in the worst case |

---

## Why `unordered_set` and NOT `unordered_map` here?

This is an important design question.

| Feature | `unordered_set` | `unordered_map` |
|---------|----------------|----------------|
| Stores | Keys only | Key-value pairs |
| Use case | Membership check ("have I seen this?") | Counting / frequency tracking |
| Memory | Less (key only) | More (key + value) |
| Syntax | `st.find(x)`, `st.insert(x)` | `mp[x]++`, `mp.count(x)` |

**In this problem, you only need to know IF a number has been seen before — you do NOT need to know HOW MANY TIMES it appeared.**

A `set` answers: **"Does X exist?"**
A `map` answers: **"How many times does X exist?"**

Using `unordered_map` would still work (e.g. `if (mp[nums[i]]++ > 0) return true;`), but it wastes memory storing a count that you never actually use. `unordered_set` is the right tool for a pure membership/existence check.

---

## Complexity Comparison

| Approach | Time | Space | Modifies Input? |
|----------|------|-------|-----------------|
| Brute Force | O(n²) | O(1) | No |
| Sorting | O(n log n) | O(log n) | **Yes** |
| Hash Set (Optimal) | **O(n)** | O(n) | No |

---

## Edge Cases to Consider

| Case | Input | Expected |
|------|-------|----------|
| Single element | `[1]` | `false` |
| All same | `[2, 2, 2]` | `true` |
| All distinct | `[1, 2, 3, 4]` | `false` |
| Negative numbers | `[-1, -1, 0]` | `true` |
| Large range | `[-10^9, 10^9]` | `false` |
| Duplicate at end | `[1, 2, 3, 4, 1]` | `true` |

---

## What's Important to Know About This Problem

- **Early termination matters.** All three approaches return `true` as soon as the first duplicate is found — they don't scan the whole array unnecessarily.
- **Hash collision caveat.** `unordered_set` has **O(n) worst-case** time if many hash collisions occur (adversarial input). In competitive programming, `std::set` (O(log n) per op, O(n log n) total) is sometimes preferred for guaranteed performance.
- **Alternative one-liner** using the set's size:
  ```cpp
  return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
  ```
  This is clean and idiomatic but does NOT short-circuit — it always processes the entire array even if a duplicate is found early.

---

## Related Problems

| Problem | Link | Concept |
|---------|------|---------|
| 219. Contains Duplicate II | [LeetCode](https://leetcode.com/problems/contains-duplicate-ii/) | Sliding window + hash map |
| 220. Contains Duplicate III | [LeetCode](https://leetcode.com/problems/contains-duplicate-iii/) | Sorted set / bucket sort |
| 1. Two Sum | [LeetCode](https://leetcode.com/problems/two-sum/) | Hash map for complement lookup |
| 349. Intersection of Two Arrays | [LeetCode](https://leetcode.com/problems/intersection-of-two-arrays/) | Hash set membership |

---

*Difficulty: Easy | Tags: Array, Hash Table, Sorting*
