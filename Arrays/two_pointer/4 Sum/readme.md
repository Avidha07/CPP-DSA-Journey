# 18. 4Sum

> **Difficulty:** Medium | **Topic:** Two Pointers, Sorting | **Language:** C++  
> 🔗 [LeetCode #18](https://leetcode.com/problems/4sum/)

---

## 1. Problem Statement

Given an array `nums` of `n` integers and an integer `target`, return **all unique quadruplets** `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a < b < c < d < n`
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

The answer must **not contain duplicate quadruplets**.

**Example:**
```
Input:  nums = [1, 0, -1, 0, -2, 2], target = 0
Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
```

---

## 2. Brute Force Approach

Use **4 nested loops** to try every possible combination of 4 indices `(i, j, k, p)`.  
If their sum equals `target`, sort the quadruplet and insert into a `set` to handle duplicates automatically.

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int p = k + 1; p < n; p++) {
                        long sum = (long)nums[i] + nums[j] + nums[k] + nums[p];
                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[p]};
                            sort(temp.begin(), temp.end());
                            ans.insert(temp);
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
```

---

## 3. Complexity of Brute Force

| | Complexity |
|---|---|
| **Time** | O(n⁴ · log n) — 4 nested loops + sort + set insertion |
| **Space** | O(k) — where k = number of unique quadruplets stored in the set |

❌ Too slow for large inputs. Fails for `n > ~200`.

---

## 4. Better Approach (3 Loops + HashSet)

Eliminate the 4th loop by using an `unordered_set` to look up the required 4th element in O(1).  
Fix `i` and `j` with two outer loops, then for each `k` in a 3rd loop, check if `target - nums[i] - nums[j] - nums[k]` already exists in `seen`.  
Use an outer `set<vector<int>>` to deduplicate results automatically.

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<int> seen;

                for (int k = j + 1; k < n; k++) {
                    long long required = (long long)target - nums[i] - nums[j] - nums[k];

                    if (required >= INT_MIN && required <= INT_MAX && seen.count(required)) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    seen.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
```

---

## 5. Complexity of Better Approach

| | Complexity |
|---|---|
| **Time** | O(n³ · log n) — 3 nested loops + sort + set insertion per quadruplet |
| **Space** | O(n) — for the `seen` HashSet rebuilt at each `(i, j)` pair |

⚠️ Better than brute force but the `set` overhead and deduplication make it slower in practice than the optimal two-pointer approach.

---

## 6. Key Observation

### From Brute Force → Better
Instead of a 4th loop, use a **HashSet** to look up the required 4th element in O(1).  
This reduces 4 loops to 3 loops + HashSet lookup — but deduplication still needs an outer `set`.

### From Better → Optimal
After **sorting** the array:
- Fix the first two elements with loops `i` and `j`
- Use a **two-pointer approach** (`l`, `h`) for the remaining two elements
- Skip duplicates explicitly using index comparisons — no `set` needed at all

> Core insight: **Sorting + Two Pointers** eliminates the need for hashing and deduplication overhead, giving us the most efficient solution.

---

## 7. Optimal Approach with Code

**Steps:**
1. Sort the array
2. Loop `i` from `0` to `n-4`, skip if `nums[i] == nums[i-1]`
3. Loop `j` from `i+1` to `n-3`, skip if `nums[j] == nums[j-1]`
4. Set `l = j+1`, `h = n-1`; run two-pointer while `l < h`
5. If sum matches → record, skip duplicates, move both pointers
6. If sum too large → decrement `h`; if too small → increment `l`

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicate j

                int l = j + 1, h = n - 1;

                while (l < h) {
                    long sum = (long)nums[i] + nums[j] + nums[l] + nums[h];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});

                        // skip duplicate l and h
                        while (l < h && nums[l] == nums[l + 1]) l++;
                        while (l < h && nums[h] == nums[h - 1]) h--;

                        l++;
                        h--;
                    } else if (sum > target) {
                        h--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
```

---

## 8. Complexity of Optimal Approach

| | Complexity |
|---|---|
| **Time** | O(n³) — two fixed loops O(n²) × two-pointer O(n) |
| **Space** | O(1) extra — output list not counted; sorting is in-place |

✅ Efficient and handles all duplicates without extra data structures.

---

## 9. Dry Run

**Input:** `nums = [1, 0, -1, 0, -2, 2]`, `target = 0`  
**After sort:** `[-2, -1, 0, 0, 1, 2]`

---

**i = 0, nums[i] = -2**

| j | nums[j] | l | h | nums[l] | nums[h] | sum | Action |
|---|---------|---|---|---------|---------|-----|--------|
| 1 | -1 | 2 | 5 | 0 | 2 | -1 | sum < 0 → l++ |
| 1 | -1 | 3 | 5 | 0 | 2 | -1 | sum < 0 → l++ |
| 1 | -1 | 4 | 5 | 1 | 2 | 0 | ✅ add [-2,-1,1,2] → l++, h-- |
| 1 | -1 | 5 | 4 | — | — | loop ends | |
| 2 | 0 | 3 | 5 | 0 | 2 | 0 | ✅ add [-2,0,0,2] → l++, h-- |
| 2 | 0 | 4 | 4 | — | — | loop ends | |
| 3 | 0 | — | — | skip dup j=3 | | | |

**i = 1, nums[i] = -1**

| j | nums[j] | l | h | nums[l] | nums[h] | sum | Action |
|---|---------|---|---|---------|---------|-----|--------|
| 2 | 0 | 3 | 5 | 0 | 2 | 1 | sum > 0 → h-- |
| 2 | 0 | 3 | 4 | 0 | 1 | 0 | ✅ add [-1,0,0,1] → l++, h-- |
| 2 | 0 | 4 | 3 | — | — | loop ends | |
| 3 | 0 | skip dup | | | | | |

**i = 2 onwards → not enough elements for valid quadruplet → loop ends**

**Final Output:** `[[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]` ✅

---

## 10. Edge Cases

| Case | Input | Expected Output |
|---|---|---|
| All same elements | `[0,0,0,0]`, target=0 | `[[0,0,0,0]]` |
| No valid quadruplet | `[1,2,3,4]`, target=100 | `[]` |
| Negative target | `[-3,-2,-1,0,0,1,2,3]`, target=-6 | `[[-3,-2,-1,0]]` (and others) |
| Array size exactly 4 | `[1,1,1,1]`, target=4 | `[[1,1,1,1]]` |
| Large values (overflow risk) | `[1000000000,1000000000,...]` | Use `long` for sum — handled ✅ |
| Duplicate heavy input | `[0,0,0,0,0,0]`, target=0 | `[[0,0,0,0]]` — not repeated |

> ⚠️ Always cast to `long` before summing 4 integers. `int` overflow is a classic bug here.

---

## 11. Interview Explanation

*"So the problem is asking me to find all unique groups of 4 numbers in an array that add up to a given target — and I need to avoid duplicates in the result.*

*The brute force would be 4 nested loops checking every combination, but that's O(n⁴) which is too slow.*

*The key insight is — if I sort the array first, I can fix the first two elements using two outer loops, and then for the remaining two elements I use the classic two-pointer technique — one pointer from the left and one from the right. This brings it down to O(n³).*

*For duplicates — since the array is sorted, I just skip over consecutive equal values for each pointer. For `i`, I check `nums[i] == nums[i-1]`. Same for `j`. And after finding a valid quadruplet, I skip duplicates for `l` and `h` before moving the pointers.*

*One important thing — the sum of 4 integers can overflow a 32-bit int, so I cast to `long` before adding.*

*Time complexity is O(n³) and space is O(1) extra, not counting the output."*

---

## 12. Follow-up Questions with Answers

**Q1. Why do we use `long` for the sum? Isn't `int` enough?**  
> No. Each element can be up to ~10⁹. Adding 4 such values can reach ~4×10⁹, which exceeds `INT_MAX` (~2.1×10⁹). Casting to `long` before the addition prevents silent integer overflow.

**Q2. How is this problem different from 3Sum, and can we generalize it?**  
> 3Sum fixes 1 element and uses two pointers for the remaining 2 — O(n²). 4Sum adds one more fixed loop — O(n³). This pattern generalizes to **k-Sum**: fix `k-2` elements with loops, then use two pointers. Time complexity is O(nᵏ⁻¹).

**Q3. Why use `set` in brute force but not in the optimal approach?**  
> In brute force, elements are picked in arbitrary order so duplicates can appear and we need a `set` to filter them. In the optimal approach, the array is sorted and we explicitly skip duplicate values for each pointer, so no extra data structure is needed — making it more space-efficient.

**Q4. What if the array has fewer than 4 elements?**  
> The outer loop condition `i < n - 3` naturally handles this — if `n < 4`, the loop never executes and we return an empty vector.

**Q5. Can this be solved using hashing to get better than O(n³)?**  
> O(n²) with hashing is theoretically possible — fix `i` and `j`, then use a hashmap to find pairs summing to `target - nums[i] - nums[j]`. However, deduplication becomes complex. In practice, the two-pointer O(n³) solution is preferred in interviews for its clarity and correctness.

---

*Pattern: Two Pointers + Sorting | Related: [Two Sum](https://leetcode.com/problems/two-sum/), [3Sum](https://leetcode.com/problems/3sum/), [3Sum Closest](https://leetcode.com/problems/3sum-closest/)*
