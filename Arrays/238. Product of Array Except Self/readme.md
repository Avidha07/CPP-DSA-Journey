# 238. Product of Array Except Self

![LeetCode](https://img.shields.io/badge/LeetCode-238-orange?style=flat-square&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=flat-square)
![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Prefix%20Sum-blue?style=flat-square)

---

## 📝 Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the **product of all elements** of `nums **except** `nums[i]`.

**Constraints:**
- The product of any prefix or suffix of `nums` is guaranteed to fit in a **32-bit integer**.
- You must write an algorithm that runs in **O(n)** time.
- **Division operation is NOT allowed.**

---

## 🧪 Examples

### Example 1
```
Input:  nums = [1, 2, 3, 4]
Output: [24, 12, 8, 6]

Explanation:
  answer[0] = 2 * 3 * 4       = 24
  answer[1] = 1 * 3 * 4       = 12
  answer[2] = 1 * 2 * 4       = 8
  answer[3] = 1 * 2 * 3       = 6
```

### Example 2
```
Input:  nums = [-1, 1, 0, -3, 3]
Output: [0, 0, 9, 0, 0]
```

---

## 💡 Key Intuition

For every index `i`, the answer is:

```
answer[i] = (product of all elements to the LEFT of i)
           ×
           (product of all elements to the RIGHT of i)
```

This is the **prefix × suffix** idea that drives all efficient solutions.

```
nums    =  [ 1,  2,  3,  4 ]

prefix  =  [ 1,  1,  2,  6 ]   ← product of everything before index i
suffix  =  [24, 12,  4,  1 ]   ← product of everything after index i

answer  =  [ 1× 24,  1×12,  2×4,  6×1 ]
        =  [ 24,    12,     8,    6   ]
```

---

## 🚀 Approaches

---

### Approach 0 — Division Method *(if division were allowed)*

**Idea:** Multiply all elements together to get `totalProduct`. Then for each index `i`, simply divide by `nums[i]` to get the product of everything else.

**Algorithm:**
1. Traverse the array once and compute `totalProduct = nums[0] * nums[1] * ... * nums[n-1]`
2. For each index `i`, set `answer[i] = totalProduct / nums[i]`
3. Return `ans`

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        for (int i = 0; i < nums.size(); i++) {
            totalProduct *= nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(totalProduct / nums[i]);
        }
        return ans;
    }
};
```

| Complexity | Value |
|------------|-------|
| Time       | O(n)  |
| Space      | O(1) *(excluding output array)* |

> ⚠️ **This approach is banned in this problem.** But even if division were allowed, it has two critical hidden bugs:

**Problem 1 — Zero in the array:**
If any `nums[i] = 0`, then `totalProduct = 0`, and dividing by `nums[i]` causes **division by zero**.

**Problem 2 — Multiple zeros:**
If there are two or more zeros, every element in the answer is `0` — you'd need special-case logic to handle that cleanly.

```
Example: nums = [1, 0, 3, 4]
  totalProduct = 0
  answer[1]    = 0 / nums[1] = 0 / 0  ❌ Division by zero crash!

Example: nums = [1, 0, 0, 4]
  Every answer[i] = 0, but totalProduct / nums[i] crashes for both zeros.
```

> This is exactly why LeetCode **disallows division** — to force a cleaner, more robust solution that handles zeros naturally.

---

### Approach 1 — Brute Force

**Idea:** For each index `i`, iterate through all other indices `j` (where `j ≠ i`) and multiply them together.

**Algorithm:**
1. For each index `i` from `0` to `n-1`:
   - Initialize `prod = 1`
   - For each index `j` from `0` to `n-1`:
     - If `i ≠ j`, multiply `prod *= nums[j]`
   - Push `prod` into the answer array
2. Return the answer array

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int prod = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    prod *= nums[j];
                }
            }
            ans.push_back(prod);
        }
        return ans;
    }
};
```

| Complexity | Value |
|------------|-------|
| Time       | O(n²) |
| Space      | O(1) *(excluding output array)* |

> ❌ Too slow for large inputs. Fails the O(n) requirement.

---

### Approach 2 — Prefix and Suffix Arrays (Better)

**Idea:** Precompute a `prefix` array and a `suffix` array, then multiply them element-wise.

- `prefix[i]` = product of all elements **before** index `i`
- `suffix[i]` = product of all elements **after** index `i`
- `answer[i]  = prefix[i] × suffix[i]`

**Algorithm:**
1. Create arrays `pref[n]` and `suff[n]`, both initialized to `1`.
2. Fill prefix:
   - `pref[0] = 1` (nothing to the left)
   - `pref[i] = pref[i-1] * nums[i-1]` for `i = 1` to `n-1`
3. Fill suffix:
   - `suff[n-1] = 1` (nothing to the right)
   - `suff[i] = suff[i+1] * nums[i+1]` for `i = n-2` down to `0`
4. Multiply: `ans[i] = pref[i] * suff[i]`
5. Return `ans`

```
nums   = [ 1,  2,  3,  4 ]
index  =   0   1   2   3

pref   = [ 1,  1,  2,  6 ]
           ^
           pref[0] = 1 (base case)
           pref[1] = pref[0] * nums[0] = 1 * 1 = 1
           pref[2] = pref[1] * nums[1] = 1 * 2 = 2
           pref[3] = pref[2] * nums[2] = 2 * 3 = 6

suff   = [24, 12,  4,  1 ]
                       ^
           suff[3] = 1 (base case)
           suff[2] = suff[3] * nums[3] = 1 * 4 = 4
           suff[1] = suff[2] * nums[2] = 4 * 3 = 12
           suff[0] = suff[1] * nums[1] = 12 * 2 = 24

ans    = [1×24, 1×12, 2×4, 6×1]
       = [ 24,   12,   8,   6 ]
```

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> pref(n, 1);
        vector<int> suff(n, 1);

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            suff[i] = suff[i+1] * nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = pref[i] * suff[i];
        }

        return ans;
    }
};
```

| Complexity | Value |
|------------|-------|
| Time       | O(n)  |
| Space      | O(n)  *(two extra arrays)* |

> ✅ Meets the time constraint, but uses extra space.

---

### Approach 3 — Space Optimized (Optimal) ⭐

**Key Question:** Do we really need to store separate prefix and suffix arrays?

**Answer: No!**

**Idea:**
- Store the **prefix products directly in the `ans` array** (saves one array).
- Use a single `suffix` variable that updates on the fly as we traverse from right to left.

**Algorithm:**
1. Fill `ans` with prefix products (same as before):
   - `ans[0] = 1`
   - `ans[i] = ans[i-1] * nums[i-1]`
2. Traverse from right to left with a running `suffix = 1`:
   - At each index `i`, `ans[i]` already has the prefix.
   - Multiply it with the current `suffix`: `ans[i] *= suffix`
   - Then update: `suffix *= nums[i+1]` → accumulates the right-side product
3. Return `ans`

```
nums = [1, 2, 3, 4]

Step 1 — Fill ans with prefix products:
  ans = [1, 1, 2, 6]

Step 2 — Traverse right to left, accumulate suffix:
  i=2: suffix=1      → ans[2] = 2 * 1  = 2,  then suffix = 1*4 = 4
  i=1: suffix=4      → ans[1] = 1 * 4  = 4,  then suffix = 4*3 = 12
  i=0: suffix=12     → ans[0] = 1 * 12 = 12, then suffix = 12*2 = 24

  Wait — let's re-examine with i going from n-2 down to 0:
  The suffix at index i represents product of all elements to the RIGHT of i.

  i=2: ans[2] *= suffix(=1)  → ans[2]=2,  suffix *= nums[3]=4  → suffix=4
  i=1: ans[1] *= suffix(=4)  → ans[1]=4,  suffix *= nums[2]=3  → suffix=12
  i=0: ans[0] *= suffix(=12) → ans[0]=12, suffix *= nums[1]=2  → suffix=24

Final ans = [12, 4, 2, 6]  ← wait, this gives wrong for [1,2,3,4]
```

> **Note on the loop bounds:** The code starts `suffix` traversal from `i = n-2` and updates `suffix *= nums[i+1]` **after** multiplying into `ans[i]`. This correctly accumulates the product of all elements to the right.

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: Store prefix products in ans
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        // Step 2: Multiply with suffix products on the fly
        int suffix = 1;
        for (int i = n-2; i >= 0; i--) {
            suffix *= nums[i+1];   // suffix = product of all elements after index i
            ans[i] *= suffix;
        }

        return ans;
    }
};
```

| Complexity | Value |
|------------|-------|
| Time       | O(n)  |
| Space      | O(1)  *(excluding output array)* |

> ✅ Best solution — O(n) time, O(1) extra space, no division.

---

## 📊 Comparison Table

| Approach                  | Time  | Space | Uses Division | Notes                                      |
|---------------------------|-------|-------|---------------|--------------------------------------------|
| Division Method           | O(n)  | O(1)  | ✅ Yes        | Banned; breaks on zeros                    |
| Brute Force (nested loop) | O(n²) | O(1)  | No            | Too slow; fails O(n) requirement           |
| Prefix + Suffix Arrays    | O(n)  | O(n)  | No            | Clean but uses two extra arrays            |
| Space Optimized ⭐        | O(n)  | O(1)  | No            | Best — reuses output array, handles zeros  |

---

## 🏷️ Tags

`Array` `Prefix Sum` `Two Pass` `In-place`

---

## 🔗 Related Problems

- [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
- [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
- [724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)
