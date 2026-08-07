# 169. Majority Element

## 📌 Problem Information

- **Problem Name:** Majority Element
- **Platform:** LeetCode
- **Difficulty:** Easy
- **Topics:** Array, Hashing, Boyer-Moore Voting Algorithm
- **Link:** https://leetcode.com/problems/majority-element/

---

# 📝 Problem Statement

Given an integer array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than ⌊n / 2⌋ times**.

You may assume that the majority element always exists.

---

# 💡 Intuition

If one element appears more than half of the time, then every other element together cannot completely cancel it.

Think like this:

- Same elements **increase** the count.
- Different elements **decrease** the count.
- Since the majority element appears more than `n/2` times, it will always survive after all cancellations.

This idea is called the **Boyer-Moore Voting Algorithm**.

---

# 👀 Observations

- Majority element appears more than half of the array.
- Every different element can cancel only one occurrence of the majority element.
- After all cancellations, the remaining candidate will be the majority element.
- In this solution, we verify the candidate in the second pass (good practice when majority is not guaranteed).

---

# 📋 Constraints

- `1 <= nums.length <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`

---

# 🚀 Approach 1: Brute Force

## Idea

Check the frequency of every element by traversing the whole array.

If any element appears more than `n/2` times, return it.

## Algorithm

1. Pick one element.
2. Count its frequency.
3. If frequency > n/2, return it.
4. Otherwise continue.

## Complexity

- **Time:** `O(N²)`
- **Space:** `O(1)`

---

# 🚀 Approach 2: Better

## Idea

Store frequencies using a Hash Map.

As soon as any frequency becomes greater than `n/2`, return that element.

## Algorithm

1. Create a hash map.
2. Count frequency of every element.
3. Return the element whose count becomes greater than `n/2`.

## Complexity

- **Time:** `O(N)`
- **Space:** `O(N)`

---

# 🚀 Approach 3: Optimal (Boyer-Moore Voting Algorithm)

## 💡 Thinking Process

Imagine every element is voting.

- If the current number is the same as the candidate, increase votes.
- If it is different, decrease votes.
- When votes become zero, choose the current element as the new candidate.

At the end, the remaining candidate is the majority element.

To be completely safe, we verify its frequency once again.

---

## Algorithm

### First Pass

- Maintain:
  - `candidate`
  - `count`
- Traverse the array.
- If `count == 0`
  - Make current element the candidate.
- If current element equals candidate
  - Increase count.
- Otherwise
  - Decrease count.

### Second Pass

- Count the frequency of the candidate.
- If frequency is greater than `n/2`, return it.
- Otherwise return `-1`.

---

# 🧪 Dry Run

### Input

```
nums = [2,2,1,1,1,2,2]
```

| Element | Candidate | Count |
|---------|-----------|-------|
|2|2|1|
|2|2|2|
|1|2|1|
|1|2|0|
|1|1|1|
|2|1|0|
|2|2|1|

Candidate after first pass = **2**

Verification:

Frequency of `2 = 4`

Since

```
4 > 7/2
```

Return

```
2
```

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(N²) | O(1) |
| Hash Map | O(N) | O(N) |
| Boyer-Moore | O(N) | O(1) |

---

# ⚠️ Edge Cases

### Single Element

```
[5]
```

Answer = 5

---

### All Elements Same

```
[3,3,3,3]
```

Answer = 3

---

### Majority at End

```
[1,2,3,3,3]
```

Answer = 3

---

### Negative Numbers

```
[-1,-1,-1,2]
```

Answer = -1

---

# ❌ Common Mistakes

- Forgetting to reset the candidate when count becomes zero.
- Returning the candidate without verification when majority is not guaranteed.
- Confusing majority element with the most frequent element.
- Using extra space when an O(1) solution exists.

---

# 🎯 Interview Explanation

If the interviewer asks:

**"Why does Boyer-Moore work?"**

You can say:

> Every occurrence of a non-majority element cancels one occurrence of the majority element. Since the majority element appears more than half of the time, it cannot be completely cancelled. Therefore, it remains as the final candidate.

---

# 🧩 Pattern Recognition

This problem teaches:

- Array Traversal
- Greedy Thinking
- Candidate Elimination
- Boyer-Moore Voting Algorithm

Whenever you see:

- Majority element
- Frequency greater than half
- O(1) space requirement

Think of **Boyer-Moore Voting Algorithm**.

---

# 🔗 Related Problems

- LeetCode 229 — Majority Element II
- LeetCode 136 — Single Number
- LeetCode 169 — Majority Element
- LeetCode 697 — Degree of an Array

---

# 📚 Key Learnings

- Majority element survives after pairwise cancellation.
- Boyer-Moore finds the candidate in one traversal.
- Verification is useful when majority is not guaranteed.
- Greedy algorithms can solve frequency problems without extra space.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int ele = 0;
        int cnt = 0;

        // Find candidate
        for (int i = 0; i < n; i++) {

            if (cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
            else if (ele == nums[i]) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        // Verify candidate
        int cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == ele)
                cnt1++;
        }

        if (cnt1 > n / 2)
            return ele;

        return -1;
    }
};
```

---

# 📝 Revision Notes

✅ Majority means frequency greater than `n/2`.

✅ Think of cancelling different elements.

✅ Candidate changes only when count becomes zero.

✅ Boyer-Moore gives:

- O(N) Time
- O(1) Space

---

# 📅 Revision Tracker

- [ ] Solved on LeetCode
- [ ] Understood Boyer-Moore intuition
- [ ] Can explain why cancellation works
- [ ] Can code without looking
- [ ] Revised before interviews
