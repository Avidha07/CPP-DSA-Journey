# 169. Majority Element

> **LeetCode Problem** | Array | Sorting | Boyer-Moore Voting Algorithm

---

## 📋 Problem Statement

Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than** `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

### Example

```
Input:  nums = [3, 2, 3]
Output: 3

Input:  nums = [2, 2, 1, 1, 1, 2, 2]
Output: 2
```

---

## 🚀 Approaches

### 1. Brute Force — O(N²) Time | O(1) Space

**Idea:** For every element, count its occurrences by iterating the full array. Return the first element whose count exceeds `⌊N/2⌋`.

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j])
                    cnt++;
            }
            if (cnt > n / 2)
                return nums[i];
        }
        return -1;
    }
};
```

**Steps:**
1. Iterate through the array and select each element one by one.
2. For each selected element, run another loop to count its occurrences.
3. If any element's count exceeds `⌊N/2⌋`, return it immediately.

| Complexity | Value |
|------------|-------|
| Time       | O(N²) |
| Space      | O(1)  |

---

### 2. Better — Hashing — O(N) Time | O(N) Space

**Idea:** Use a hash map to count occurrences of each element in a single pass, then find the element with count > `⌊N/2⌋`.

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            if (it.second > n / 2)
                return it.first;
        }
        return -1;
    }
};
```

**Steps:**
1. Store each element as a key in a hash map, with its count as the value.
2. Traverse the array and update each element's count.
3. Check if any key's count exceeds `⌊N/2⌋` and return it.

| Complexity | Value |
|------------|-------|
| Time       | O(N)  |
| Space      | O(N)  |

---

### 3. Optimal — Boyer-Moore Voting Algorithm — O(N) Time | O(1) Space ✅

**Idea:** The majority element appears more than `⌊N/2⌋` times, so it can "survive" a process of cancellation against all other elements. Track a candidate and a count — increment when you see the candidate, decrement when you don't. The last surviving candidate is the answer (verified with a second pass).

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ele;

        // Phase 1: Find the candidate
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt++;
                ele = nums[i];
            } else if (ele == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // Phase 2: Verify the candidate
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (ele == nums[i])
                cnt1++;
        }

        return (cnt1 > n / 2) ? ele : -1;
    }
};
```

**Steps:**
1. **Phase 1 — Find Candidate:** Initialize `count = 0` and `element` as undefined.
   - If `count == 0`, set the current element as the new candidate and set `count = 1`.
   - If the current element equals the candidate, increment `count`.
   - Otherwise, decrement `count`.
2. **Phase 2 — Verify:** Count the occurrences of the candidate. Return it if the count exceeds `⌊N/2⌋`.

| Complexity | Value |
|------------|-------|
| Time       | O(N)  |
| Space      | O(1)  |

---

## 📊 Comparison

| Approach              | Time  | Space | Notes                          |
|-----------------------|-------|-------|--------------------------------|
| Brute Force           | O(N²) | O(1)  | Too slow for large inputs      |
| HashMap               | O(N)  | O(N)  | Fast, but uses extra memory    |
| Boyer-Moore (Optimal) | O(N)  | O(1)  | Best of both worlds ✅          |

---

## 💡 Key Insight — Why Boyer-Moore Works

Since the majority element appears more than `N/2` times, it will always **outnumber all other elements combined**. Even if every non-majority element "cancels" one occurrence of the majority element, there will still be majority elements left standing at the end.

---

## 🔗 Related Problems

- [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/) — Find elements appearing more than `⌊N/3⌋` times
- [280. Wiggle Sort](https://leetcode.com/problems/wiggle-sort/)
- [75. Sort Colors](https://leetcode.com/problems/sort-colors/)
